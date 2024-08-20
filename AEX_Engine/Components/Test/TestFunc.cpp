#include "TestFunc.h"
#include <iostream>
#include <ctime>
#include <random>

time_t start;
int randomIntA, randomIntB, randomIntC;
bool stateA = false, stateB = false;
int a = 0, b = 0, c = 0;
int nyanCount = 0;

void TestFunc::Update()
{
	if (RandomExcute(a, randomIntA))
	{
		Print("�ɳ�");
		if (nyanCount == 4)
		{
			Print("�ɳ���ġ!");
			Print("����");
			nyanCount = 0;
		}
		nyanCount++;
	}
	if (RandomExcute(b, randomIntB))
	{
		Print("�п�");
	}
	if (RandomExcute(c, randomIntC))
	{
		Print("...");
	}
}

bool TestFunc::RandomExcute(int& index, int& randomInt)
{
	if (index == 0)
	{
		index = 1;
		randomInt = rand() % 3;
		start = time(NULL);
	}
	else if ((double)(time(NULL) - start) >= (double)randomInt)
	{
		index = 0;
		return true;
	}
	return false;
}

void TestFunc::Print(std::string context)
{
	std::cout << context << std::endl;
}
