/*
	����:�з�Ƽ��Ʈ
	20130940 �����а� 3�г� �����
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int main(void)
{
	fstream Input;
	int numOfdData;
	unsigned int  num;
	int a;
	int count ;
	Input.open("input.txt");
	if (Input.fail())
	{
		cerr << "file is not open," << endl;
	}
	Input >> numOfdData;
	for (int i = 0 ;i < numOfdData; i++)
	{
		Input >> num;
		a = 1;
		count = 0;
		for (int k = 0; k < 31; k++)
		{
			if (a&num) count++;
			a = a << 1;
		}
		if ((count % 2 == 1)) 	num = a | num;
		
		cout << num << endl;
	}
	return 0;
}
