#include "core.h"

void GameCore()
{
	//Khởi tạo giá trị cho game
	position playerPos; // vị trí của người chơi
	playerPos.c = boardWidth / 2; //Vị trí được đặt mặt định ở chính giữa bên dưới màn hình.
	playerPos.r = boardHeight - 3;
	int playerBulletCount = 0, //Số lượng đạn của người chơi trong game
		enemyBulletCount = 0, //Số lượng đạn của kẻ địch trong game
		meteoriteCount = 0,  // Số lượng thiên thạch trong game
		pause = 0, //Nếu game đang tạm dùng biến này sẽ trở thành 1
		curSelection = 1,//Vị trí hiện tại người chơi chọn trong Menu tạm dừng
		planeCount = 0,//Số lượng máy bay địch
		createdCount = 0,//Số lượng máy bay đã tạo trong lượt 
		planeCountMax = 1,//Số lượng tối đa máy bay xuất hiện(Tăng dần theo thời gian),
		gameOver = 0, //Nếu Game Over biến này trở thành 1
		count = 0, //Nếu biến đếm đạt đến giá trị nhất định nào đó thì sẽ kích hoạt các sự kiện(hàm)
		playerHP = 20,//Lượng HP của người chơi
		bossHP = 0,//Lượng HP của Boss
		maxBossHp = 10,//Lượng HP tối đa hiện tại của Boss
		powerUpRemainTime = 0,
		shootingDelay = 20;//Thời gian trì hoãn giữa 2 lần bắn(của người chơi)
	unsigned long score = 0;//Điểm số người chơi đã đạt được
	ULONGLONG lastedTime = 0,//Thời gian kể từ lần cuối thực hiện dãy các lệnh, nếu giá trị nó lớn hơn hoặc bằng fixedTime thì dãy lệnh sẽ được
						 //thực hiện. Điều này nhằm giữ cho thời gian chạy trên các máy là tương đồng, và giữa những lúc nhiều vật thể không
						 //quá chậm so với khi có ít vật thể trong game
		deltaTime,//Biến dùng để tính thời gian giữa 2 lần gọi hàm GetTickCount64();
		lastTime = GetTickCount64(),//Thời điểm gọi hàm GetTickCount64() trước
		now;//Thời điểm đang gọi hàm GetTickCount64()

	//Các mảng dưới đây lưu lại vị trí của các vật thể
	position playerBullets[100],//Mảng các viên đạn của người chơi
		enemyBullets[100],//Mảng các viên đạn của kẻ địch
		meteoritePos[100],//Mảng các thiên thạch
		planePos[100],//Mảng các máy bay địch
		bossPosition,//Vị trí của Boss trong game
		hpPosition = { -1,-1 },
		powerUpPos = { -1,-1 };//Vị trí của item Power Up(Tăng tốc độ bắn)
	PlaneThroughScreen();
	DrawScreenFromFile("game.map");
	DrawPlayer(playerPos);
	//Dòng While chính của game
	while (!gameOver)
	{
		if (!pause)
		{
			now = GetTickCount64();
			deltaTime = now - lastTime;
			lastedTime += deltaTime;
			lastTime = now;
			if (lastedTime > fixedTime)
			{
				lastedTime -= fixedTime;
				count++;
				BulletControl(playerBullets, playerBulletCount, 'U', '^');
				if (count % 4 == 0)
					BulletControl(enemyBullets, enemyBulletCount, 'D', '|');
				if (count % shootingDelay == 0)
				{
					PlaySound(TEXT("Resources/gameEffect/NormalShot.wav"), NULL, SND_ASYNC);
					Shoot(playerPos, playerBullets, playerBulletCount, '^');
				}
				if (count % 20 == 0)
				{
					CreateNewMeteorite(meteoritePos, meteoriteCount);
				}
				if (count % 4 == 0)
				{
					MeteoriteControl(meteoritePos, meteoriteCount);
					PlaneComputer(planePos, planeCount);
				}
				if (count % 40 == 0)
				{
					SetBoardValue(2, 107, (char)((CLOCKS_PER_SEC / deltaTime) / 100 + 48));
					SetBoardValue(2, 108, (char)((CLOCKS_PER_SEC / deltaTime) % 100 / 10 +48));
					SetBoardValue(2, 109, (char)((CLOCKS_PER_SEC / deltaTime) % 10 + 48));
					if (powerUpPos.r != -1)
					{
						MovePowerUp(powerUpPos);
					}
					if (hpPosition.r != -1)
					{
						MoveHP(hpPosition);
					}
					if (createdCount < planeCountMax)
					{
						CreatePlane(planePos, planeCount);
						createdCount++;
					}
					if (planeCount == 0)
					{
						planeCountMax++;
						createdCount = 0;
					}
					PlaneShoot(planePos, planeCount, enemyBullets, enemyBulletCount);
				}
				HitPlayer(playerPos, meteoritePos, meteoriteCount, enemyBullets, enemyBulletCount, playerHP);
				HitMeteorite(playerBullets, playerBulletCount, meteoritePos, meteoriteCount, score);
				BulletHitPlane(playerBullets, playerBulletCount, planePos, planeCount, score);
				PlayerCollidePowerUp(powerUpPos, playerPos, powerUpRemainTime);
				PlayerCollideHP(hpPosition, playerPos, playerHP);
				PlayerCollidePlane(playerPos, planePos, planeCount, playerHP);
				HitMeteorite(playerBullets, playerBulletCount, meteoritePos, meteoriteCount, score);
				if (count % 2 == 0)
					PlayerMove(playerPos);
				if (bossHP > 0 && count % 4 == 0)
				{
					BossMovement(playerPos, bossPosition);
				}

				if (bossHP > 0 && count % 20 == 0)
				{
					PlaySound(TEXT("Resources/gameEffect/bossShoot.wav"), NULL, SND_ASYNC);
					Shoot({ bossPosition.r + 6, bossPosition.c }, enemyBullets, enemyBulletCount, '|');
					if(bossPosition.c - 10 > 0)
						Shoot({ bossPosition.r + 6, bossPosition.c - 10 }, enemyBullets, enemyBulletCount, '|');
					if (bossPosition.c + 10 < boardWidth - 1)
						Shoot({ bossPosition.r + 6, bossPosition.c + 10 }, enemyBullets, enemyBulletCount, '|');
				}
				if (bossHP > 0)
					HitBoss(playerBullets, playerBulletCount, bossPosition, bossHP, score);
				if (count % 3000 == 0)
				{
					if (rand() % 2)
						CreatePowerUp(powerUpPos);
					else
						CreateHP(hpPosition);
				}
				if (powerUpRemainTime > 0)
				{
					powerUpRemainTime--;
					shootingDelay = 4;
				}
				else
				{
					shootingDelay = 20;
				}
				if (count % 2000 == 0 && bossHP <= 0)
				{
					CreateBoss(bossHP, maxBossHp, bossPosition);
				}
				UpdateHP(playerHP);
				DrawPlayer(playerPos);
				if (playerHP <= 0)
				{
					gameOver = 1;
				}
				if (!gameOver)
				{
					RedrawBoard();
					PauseGame(pause);
				}
			}
			while (lastedTime > fixedTime)
			{
				lastedTime -= fixedTime;
			}
			if (count > 100000)
				count = 1;
		}
		else
		{
			PauseMenu(pause, curSelection, gameOver);
		}
	}
	GameOver(score);
}