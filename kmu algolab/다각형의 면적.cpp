/*
problem: 다각형의 면적
20130940 경제학과 3학년 장용훈
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int Area(int * a, int *b, int point);
int main(void)
{
	ifstream Input;
	int numOfData;
	int point;
	int a[1000] = {0,};
	int b[1000] = { 0, };
	Input.open("input.txt");
	if (Input.fail())
	{
		cerr << "file is not open" << endl;
	}
	Input >> numOfData;
	for (int i = 0; i < numOfData; i++)

	{
		Input >> point;
		for (int j = 0; j < point; j++) {
			Input >> a[j] >> b[j];
		}
		if (Area(a, b, point) > 0) cout << abs(Area(a, b, point)) << ' ' << "1"<<endl;
		else cout << abs(Area(a, b, point)) << ' ' << "-1"<<endl;
	}
	return 0;

}
int Area(int * a, int * b, int point)
{
	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	for (int i = 0; i < point; i++)
	{
		if (i == point - 1) {
			sum = ((a[i] + a[0])*(b[0] - b[i]));
			sum2 += sum;
			break;
		}
		sum = ((a[i] + a[i + 1])*(b[i + 1] - b[i]));
		 sum2 += sum;
	}
	
	return sum2;
}