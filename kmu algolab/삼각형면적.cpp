/*
problem: 삼각형의 면적
20130940 경제학과 3학년 장용훈
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Point {
public:
	int xpos;
	int ypos;
};
int Area(Point  p1, Point  p2, Point  p3);
int main(void)
{
	ifstream Input;
	int numOfData;
	Point p1, p2, p3;
	Input.open("input.txt");
	if (Input.fail())
	{
		cerr << "file is not open" << endl;
	}
	Input >> numOfData;
	for (int i = 0; i < numOfData; i++)

	{
		Input >> p1.xpos >> p1.ypos >> p2.xpos >> p2.ypos >> p3.xpos >> p3.ypos ;
		if (Area(p1, p2, p3) > 0) cout << abs(Area(p1, p2, p3)) << ' ' << "1" << endl;
		else if(Area(p1, p2, p3)<0) cout << abs(Area(p1, p2, p3)) << ' ' << "-1" << endl;
		else cout << abs(Area(p1, p2, p3)) << ' ' << "0" << endl;
	}
	return 0;

}
int Area(Point  p1, Point  p2, Point  p3)
{
	return (((p2.xpos - p1.xpos)*(p3.ypos - p1.ypos)) - ((p3.xpos - p1.xpos)*(p2.ypos - p1.ypos)));

}
