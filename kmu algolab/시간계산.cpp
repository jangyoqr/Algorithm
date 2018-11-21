/*
문제: 시간계산하기
20130940 경제학과  3학년 장용훈
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
void CalculateHour(int H, int M, int S, int &h, int &m, int&s);
void InfoDate(int &H, int &M, int &S, int &day);
int main(void)
{
	ifstream Inpustream;
	int numTestCase;
	int numOfPeople;
	int H, M, S, h, m, s;
	int totalH, totalM, totalS;
	int day = 0;
	Inpustream.open("input.txt");

	if (Inpustream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	Inpustream >> numTestCase;
	for (int i = 0; i < numTestCase; i++)
	{
		Inpustream >> numOfPeople;
		day = 0; totalH = 0; totalM = 0; totalS = 0;
		for (int k = 0; k < numOfPeople; k++)
		{
			H, M, S, h, m, s = 0;
			Inpustream >> H >> M >> S >> h >> m >> s;
			CalculateHour(H, M, S, h, m, s);
			totalH += (h - H);
			totalM += (m - M);
			totalS += (s - S);
		}
		InfoDate(totalH, totalM, totalS, day);
		cout << day << " " << totalH << " " << totalM << " " << totalS << endl;
	}
	Inpustream.close();
	return 0;
}
void CalculateHour(int H, int M, int S, int &h, int &m, int&s)
{
	if (M>m)
	{
		h -= 1;
		m += 60;
	}
	if (S>s)
	{
		m -= 1;
		s += 60;
	}

}
void InfoDate(int &H, int &M, int &S, int &day)
{
	if (S >= 60)
	{
		M += (S/60);
		S -= ((S / 60)*60);
	
	}
	if (M >= 60)
	{
		H += (M / 60);
		M -= ((M / 60) * 60);
	}
	if (H >= 24)
	{
		day += (H/24);
		H -=(day*24);
	}
}