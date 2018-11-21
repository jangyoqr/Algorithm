/*
문제:최빈값
20130940 경제학과 3학년 장용훈
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void process(int k, ifstream &inStream);
void sort(int naNum[100], int nCount);

int main(void)
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt"); //open input file
	if (inStream.fail())
	{
		cerr << "Input file opening failed. \n";
		exit(1);
	}
	inStream >> numTestCases;

	int nCount = 0;

	for (int i = 0; i<numTestCases; i++)
	{
		inStream >> nCount; 
		process(nCount, inStream);    // 최빈값 찾기
	}
	inStream.close();
	return 0;
}

void process(int k, ifstream &inStream)
{
	int naNum[100][2];  
	int nIdx = 0;      
	int i, j;           

						
	for (i = 0; i < 100; i++)
		naNum[i][1] = 0;

	int nCurrentNum;    

						
	for (i = 0; i < k; i++)
	{
		inStream >> nCurrentNum; 
		for (j = 0; j < nIdx; j++)
		{
			if (naNum[j][0] == nCurrentNum)
				break;
		}

		if (j == nIdx) 
		{
			naNum[nIdx][0] = nCurrentNum; 
			naNum[nIdx][1]++;                 
			nIdx++;
		}
		else               
		{
			naNum[j][1]++;                    
		}
	}


	int nMaxFreq = 0;   
	for (i = 0; i < nIdx; i++)
	{
		if (nMaxFreq < naNum[i][1])
			nMaxFreq = naNum[i][1];
	}


	// 최빈값 찾기
	int naMaxs[100];
	int nMaxCount = 0;
	for (i = 0; i < nIdx; i++)
	{
		if (nMaxFreq == naNum[i][1])
			naMaxs[nMaxCount++] = naNum[i][0];
	}


	sort(naMaxs, nMaxCount);


	cout << nMaxCount << " " << nMaxFreq << " ";
	for (i = 0; i < nMaxCount; i++)
		cout << naMaxs[i] << " ";
	cout << endl;
}

void sort(int naNum[100], int nCount)
{
	int i, j;
	int temp;

	for (i = 0; i < nCount; i++)
	{
		for (j = 0; j < nCount - i - 1; j++)
		{
			if (naNum[j] > naNum[j + 1])
			{
				temp = naNum[j];
				naNum[j] = naNum[j + 1];
				naNum[j + 1] = temp;
			}
		}
	}
}