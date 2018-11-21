/*
문제 : 끝자리 숫자 계산하기
20130940 경제학과  3학년 장용훈

*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main(void)
{
	ifstream intStream;
	int numTestCase;
	int num;
	int numOfCompare;
	 int total;
	intStream.open("input.txt");

	if (intStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	intStream >> numTestCase;

	for (int i = 0; i < numTestCase; i++)
	{
		intStream >> numOfCompare;
		total = 1;
		for (int k = 0; k < numOfCompare; k++)
		{
			intStream >> num;
			num %= 10;
			total *= num;
			total %= 10;
		}
		cout << total  << endl;
	
	}

	intStream.close();

	return 0;
}
