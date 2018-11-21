/*
problem: 삼각형의 종류_1
20130940 경제학과 3학년 장용훈
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
	int numOfData;
	ifstream Inpustream;
	int a, b, c;
	Inpustream.open("input.txt");
	if (Inpustream.fail())
	{
		cerr << "file is not open" << endl;
	}
	Inpustream >> numOfData;
	for (int i = 0; i < numOfData; i++)
	{
		Inpustream >> a>>b>>c;
		if (a >= (b + c) || b >= (a + c) ||  c >= (a + b)) cout << '0' << endl;//삼각형이 아니다
		else
		{
			if (a == b && a == c && b == c) //정삼각형 
				cout << '1' << endl;
			else if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(b, 2) + pow(c, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
			{
				if (a == b || a == c || b == c) cout << '0' << endl;//직각 이등변삼각형
				else cout << '2' << endl;//직각삼각형
			}
			else if (a == b || a == c || b == c)
			{
				if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(b, 2) + pow(c, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
					cout << '0' << endl;//직각 이등변 삼각형
				else cout << '3' << endl;//이등변삼각현
			}
			else cout << '4' << endl;//일반삼각현
		}
		
	}
	return 0;
}

