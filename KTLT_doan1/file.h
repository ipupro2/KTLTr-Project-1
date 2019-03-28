#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct saveData
{
	string name;
	unsigned long long score;
};

void LoadScore(saveData data[]);
void SaveScore(saveData data);

#endif // !FILE_H
