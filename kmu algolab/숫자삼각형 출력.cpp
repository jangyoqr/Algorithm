/*
문제: 숫자삼각형 출력
20130940 경제학과  3학년 장용훈
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(void)
{
	ifstream Inpustream;
	int numTestCase;
	int num;
	Inpustream.open("input.txt");
	if (Inpustream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	Inpustream >> numTestCase;
	for (int p = 0; p < numTestCase; p++)
	{
		Inpustream >> num;
			int col = 0;							
			int m = 0;
			for (int i = 1; i <= num; i++)			
			{
				cout << i << " ";
				col = i;
				for (int j = 1; j < i; j++)			
				{
					col += m - 1;					
					cout << col << " ";
					m--;
				}
				m = num;
				cout << endl;
			}
	}
	Inpustream.close();
	return 0;
}


