/*
	����: �簢���� ������ �Ÿ�
	20130940 �����а� �����
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef struct _point{
	int x;
	int y;
} Point; 
void Sort(Point &p1, Point &p2);
int EuclideanDistance( Point p1, Point p2); //�����Ÿ�
int RectilinearDistance( Point p1, Point p2); //�����Ÿ�
int main(void)
{
	ifstream Inpustream;
	int numOfData;
	Point p1, p2; 
	Point CompareP;
	Point tempP;
	int d1,d2 ;
	Inpustream.open("input.txt");
	if (Inpustream.fail())
	{
		cerr << "file is not open" << endl;
	}
	Inpustream >> numOfData;
	for (int i = 0; i < numOfData; i++)
	{
		Inpustream >> p1.x >> p1.y >> p2.x >> p2.y>>CompareP.x>>CompareP.y;
		Sort(p1, p2);
		d1, d2 = 0;
		if ((p1.x <= CompareP.x && CompareP.x <= p2.x) && (p1.y <= CompareP.y && CompareP.y <= p2.y))
		{
			cout << '0' << ' ' << '0' << endl;
		}
		else if ((p1.y <= CompareP.y && CompareP.y <= p2.y))//y���� �簢�� �ȿ� ��°��
		{
			if (CompareP.x >= p2.x)  
			{
				tempP.x = p2.x;
				tempP.y = CompareP.y;
				d1 = RectilinearDistance(CompareP,tempP);
				d2 = EuclideanDistance(CompareP,tempP);
				cout << d1 << ' ' << d2 << endl;
				//d2 = sqrt(((pow(CompareP.x - p2.x, 2)+pow(CompareP.y-p2.y,2))));
			}
			else
			{
				tempP.x = p1.x;
				tempP.y = CompareP.y;
				d1 = RectilinearDistance(CompareP, tempP);
				d2 = EuclideanDistance(CompareP, tempP);
				cout << d1 << ' ' << d2 << endl;
			}
		}
		else if (p1.x <= CompareP.x && CompareP.x <= p2.x) //x���� �簢�� ���� �ȿ���°��
		{
			if (CompareP.y >= p2.y) 
			{
				tempP.x = CompareP.x;
				tempP.y = p2.y;
				d1 = RectilinearDistance(CompareP, tempP);
				d2 = EuclideanDistance(CompareP, tempP);
				cout << d1 << ' ' << d2 << endl;
			}
			else
			{
				tempP.x = CompareP.x;
				tempP.y = p1.y;
				d1 = RectilinearDistance(CompareP, tempP);
				d2 = EuclideanDistance(CompareP, tempP);
				cout << d1 << ' ' << d2 << endl;
			}
		}
		else if ((CompareP.x >= p2.x) && (CompareP.y >= p2.y))//x y�� �簢�� ���� �ۿ��ִ°�� (���� ��ũ��)
		{
			d1 = RectilinearDistance(CompareP,p2);
			d2 =EuclideanDistance(CompareP,p2);
			cout << d1 << ' ' << d2 << endl;
		}
		else if ((CompareP.x <= p1.x) && (CompareP.y <= p1.y)) //x y�� �簢�� ���� �ۿ��ִ°�� (���� ���۴�)
		{
			d1 = RectilinearDistance(CompareP, p1);
			d2 = EuclideanDistance(CompareP, p1);
			cout << d1 << ' ' << d2 << endl;
		}
		else if ((CompareP.x >= p2.x) && (CompareP.y <= p1.y)) 
		{
			tempP.x = p2.x;
			tempP.y = p1.y;
			d1 = RectilinearDistance(CompareP, tempP);
			d2 = EuclideanDistance(CompareP, tempP);
			cout << d1 << ' ' << d2 << endl;
		}//if���ұ��
		else {
			tempP.x = p1.x;
			tempP.y = p2.y;
			d1 = RectilinearDistance(CompareP, tempP);
			d2 = EuclideanDistance(CompareP, tempP);
			cout << d1 << ' ' << d2 << endl;
		}
	}
	return 0;
}
int EuclideanDistance( Point p1, Point p2) //�����Ÿ�
{
	return (abs(p1.x - p2.x) + abs(p1.y - p2.y));
} 
int RectilinearDistance(Point p1, Point p2)//�����Ÿ�
{
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}
void Sort(Point &p1, Point &p2)
{
	Point p;
	p.x = p1.x; p.y = p1.y;
	if (p1.x > p2.x)
	{
		p1.x = p2.x;
		p1.y = p2.y;
		p2.x = p.x;
		p2.y = p.y;
	}
}