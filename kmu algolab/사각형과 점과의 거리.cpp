/*
	문제: 사각형과 점과의 거리
	20130940 경제학과 장용훈
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
int EuclideanDistance( Point p1, Point p2); //직선거리
int RectilinearDistance( Point p1, Point p2); //직각거리
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
		else if ((p1.y <= CompareP.y && CompareP.y <= p2.y))//y값이 사각형 안에 드는경우
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
		else if (p1.x <= CompareP.x && CompareP.x <= p2.x) //x값이 사각형 범위 안에드는경우
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
		else if ((CompareP.x >= p2.x) && (CompareP.y >= p2.y))//x y가 사각형 범위 밖에있는경우 (값이 더크다)
		{
			d1 = RectilinearDistance(CompareP,p2);
			d2 =EuclideanDistance(CompareP,p2);
			cout << d1 << ' ' << d2 << endl;
		}
		else if ((CompareP.x <= p1.x) && (CompareP.y <= p1.y)) //x y가 사각형 범위 밖에있는경우 (값이 더작다)
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
		}//if를할까말까
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
int EuclideanDistance( Point p1, Point p2) //직각거리
{
	return (abs(p1.x - p2.x) + abs(p1.y - p2.y));
} 
int RectilinearDistance(Point p1, Point p2)//직선거리
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