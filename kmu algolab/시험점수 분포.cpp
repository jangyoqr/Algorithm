/*
문제:시험점수분포
20130940 경제학과 3학년 장용훈
*/

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(void) {
	ifstream Input;
	Input.open("input.txt");
	int numOfData;
	if (Input.fail())
	{
		cerr << "file is not open" << endl;
	}
	
	Input >> numOfData;
	for (int k = 0; k<numOfData; ++k) {
		int n;
		Input >> n;
		int student[101] = { 0, };
		for (int i = 0; i<n; i++) {
			int num;
			Input>> num;
			student[num]++;
		}
		for (int i = 0; i <= 100; i++) {
			if (student[i] > 0)
				cout << i << " " << student[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
