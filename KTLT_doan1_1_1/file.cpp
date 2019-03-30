#include "file.h"

void LoadScore(saveData data[])
{
	ifstream inNameScore;
	inNameScore.open("name_score.txt");
	if (!inNameScore)
	{
		ofstream outNameScore;
		outNameScore.open("name_score.txt");
		for (int i = 0; i < 10; i++)
			outNameScore << "Noname 0" << endl;
		outNameScore.close();
	}
	for (int i = 0; i < 10; i++)
	{
		inNameScore >> data[i].name;
		inNameScore >> data[i].score;
	}
	inNameScore.close();
}

void SaveScore(saveData data)
{
	ifstream inNameScore;
	inNameScore.open("name_score.txt");
	saveData a[10];
	string t1;
	unsigned long long t2;
	int i = 0;
	LoadScore(a);
	for (i = 0; i < 10; i++)
		if (a[i].score < data.score)
		{
			t1 = a[i].name;
			t2 = a[i].score;
			a[i].name = data.name;
			a[i].score = data.score;
			for (int j = 9; j > i + 1; j--)
			{
				a[j].name = a[j - 1].name;
				a[j].score = a[j - 1].score;
			}
			a[i + 1].name = t1;
			a[i + 1].score = t2;
			break;
		}
	cout << endl;
	inNameScore.close();
	ofstream outNameScore;
	outNameScore.open("name_score.txt");
	for (i = 0; i < 10; i++)
	{
		outNameScore << a[i].name << " " << a[i].score << endl;
	}

	outNameScore.close();
}