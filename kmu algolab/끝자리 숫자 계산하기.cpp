/*
���� : ���ڸ� ���� ����ϱ�
20130940 �����а�  3�г� �����

*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main(void)
{
	ifstream intStream;
	int numTestCase;
	int num;
	int numOfCompare;
	 int total;
	intStream.open("input.txt");

	if (intStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	intStream >> numTestCase;

	for (int i = 0; i < numTestCase; i++)
	{
		intStream >> numOfCompare;
		total = 1;
		for (int k = 0; k < numOfCompare; k++)
		{
			intStream >> num;
			num %= 10;
			total *= num;
			total %= 10;
		}
		cout << total  << endl;
	
	}

	intStream.close();

	return 0;
}
