/*
	problem: 삼각형의 종류_2
	20130940 경제학과 3학년 장용훈
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int arr[3] = { 0 };
int p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;

void calculate();
void sorting();

int main(void)
{
	ifstream Inputstream;

	Inputstream.open("input.txt");

	if (Inputstream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	int numOfData;

	Inputstream >> numOfData;

	for (int i = 0; i<numOfData; i++) {
		p1_x, p1_y, p2_x, p2_y, p3_x, p3_y = 0;
		Inputstream >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y;

		calculate();
		sorting();

		if ((sqrt(arr[2]) < sqrt(arr[0]) + sqrt(arr[1])) && (sqrt(arr[2]) > sqrt(arr[1]) - sqrt(arr[0])))
		{
			if (arr[0] + arr[1] > arr[2])
				cout << 3 << endl;
			else if (arr[0] + arr[1] == arr[2])
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
		else
			cout << 0 << endl;
	}

	Inputstream.close();
	return 0;
}
void calculate () {
	arr[0] = (p1_x - p2_x)*(p1_x - p2_x) + (p1_y - p2_y)*(p1_y - p2_y);
	arr[1] = (p1_x - p3_x)*(p1_x - p3_x) + (p1_y - p3_y)*(p1_y - p3_y);
	arr[2] = (p3_x - p2_x)*(p3_x - p2_x) + (p3_y - p2_y)*(p3_y - p2_y);
}

void sorting()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3 - i - 1; j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
