/*
problem: �ﰢ���� ����_1
20130940 �����а� 3�г� �����
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
		if (a >= (b + c) || b >= (a + c) ||  c >= (a + b)) cout << '0' << endl;//�ﰢ���� �ƴϴ�
		else
		{
			if (a == b && a == c && b == c) //���ﰢ�� 
				cout << '1' << endl;
			else if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(b, 2) + pow(c, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
			{
				if (a == b || a == c || b == c) cout << '0' << endl;//���� �̵�ﰢ��
				else cout << '2' << endl;//�����ﰢ��
			}
			else if (a == b || a == c || b == c)
			{
				if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(b, 2) + pow(c, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
					cout << '0' << endl;//���� �̵ �ﰢ��
				else cout << '3' << endl;//�̵�ﰢ��
			}
			else cout << '4' << endl;//�Ϲݻﰢ��
		}
		
	}
	return 0;
}

