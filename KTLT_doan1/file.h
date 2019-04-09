#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct saveData
{
	string name;
	unsigned long score;
};


//Load dữ liệu người chơi trong file save
void LoadScore(saveData data[]);

//Lưu lại dữ liệu người chơi nếu người chơi có điểm cao hơn các điểm được lưu trong file save
void SaveScore(saveData data);

#endif // !FILE_H
