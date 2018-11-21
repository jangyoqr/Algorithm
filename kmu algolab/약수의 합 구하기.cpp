/*
	문제:약수의 합 구하기
	20130940 경제학과 3학년 장용훈

*/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(void)
{
	ifstream Input;
	int numOfData;
	Input.open("input.txt");
	int num=0;
	int arr[1000];
	int n ;
	int sum;
	if (Input.fail())
	{
		cerr << "File is not open" << endl;
	}
	Input >> numOfData;
	for (int i = 0; i < numOfData; i++)
	{
		Input >> num;
		n = 0;
		sum = 0;
		for (int k = 1; k*k <= num; k++)
		{
			if ((num % k) == 0)
			{
				arr[n++] = k;
				arr[n++] = num / k;
				sum += k;
				sum+= num / k;
			}
			
		}
		cout << n-1 << " " << sum-num << endl;
	}
}