/*
문제:해밍수
20130940 경제학과 3학년 장용훈
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ifstream Input;
	int numOfdData;
	int k;
	vector <unsigned int>v;
	int num = 1;
	Input.open("input.txt");
	if (Input.fail())
	{
		cerr << "file is not open," << endl;
	}

	for (int i = 1;; i *= 5) {
		for (int k = i;; k *= 3) {
			for (int j = k;; j *= 2)
			{
				v.push_back(j);
				if (j > UINT_MAX/2)break;
			}
			if (k > UINT_MAX / 3)break;
		}
		if (i > UINT_MAX / 5)break;
	}
	sort(v.begin(), v.end());
	Input >> numOfdData;
	for (int i = 0; i < numOfdData; i++)
	{
		Input >> k;
		cout << v[k - 1] << endl;
		
	}
	return 0;
}


