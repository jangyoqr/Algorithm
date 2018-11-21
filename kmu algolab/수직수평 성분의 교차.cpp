/*
	problem: 수직수평성분의 교차
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
void Change(Point  p1, Point  p2, Point  a1, Point a2,Point &h1, Point &h2, Point &v1, Point &v2);
void Sort(Point & h1, Point & h2, Point & v1, Point & v2);
int main(void)
{
	ifstream Input;
	int numOfData;
	Point p1, p2,a1,a2,h1,h2,v1,v2;
	Input.open("input.txt");
	if (Input.fail())
	{
		cerr << "file is not open" << endl;
	}
	Input >> numOfData;
	for (int i = 0; i < numOfData; i++)
		
	{
		Input >> p1.xpos >> p1.ypos >> p2.xpos >> p2.ypos>>a1.xpos>>a1.ypos>>a2.xpos>>a2.ypos;
		Change(p1, p2, a1, a2, h1, h2, v1, v2);
		Sort(h1, h2, v1, v2);
		if ((h1.ypos < v1.ypos) || (h2.ypos > v2.ypos) || h1.xpos > v1.xpos || h2.xpos < v1.xpos)
			cout << '0' << endl;
		else if (((v1.ypos <= h1.ypos && h1.ypos <= v2.ypos) && (h1.xpos == v1.xpos || h2.xpos == v1.xpos))
			|| ((h1.xpos <= v1.xpos && v1.ypos <= h2.ypos) && (v1.ypos == h1.ypos || v2.ypos == h1.ypos)))
			cout << '2' << endl;
		else cout << '1' << endl;
	}
	return 0;

}
void Change(Point  p1, Point  p2, Point  a1, Point a2, Point &h1, Point &h2, Point &v1, Point &v2)
{
	if (p1.xpos == p2.xpos)
	{
		v1.xpos = p1.xpos;
		v1.ypos = p1.ypos;
		v2.xpos = p2.xpos;
		v2.ypos = p2.ypos;
		h1.xpos = a1.xpos;
		h1.ypos = a1.ypos;
		h2.xpos = a2.xpos;
		h2.ypos = a2.ypos;
		
	}
	else {
		v1.xpos = a1.xpos;
		v1.ypos = a1.ypos;
		v2.xpos = a2.xpos;
		v2.ypos = a2.ypos;
		h1.xpos = p1.xpos;
		h1.ypos = p1.ypos;
		h2.xpos = p2.xpos;
		h2.ypos = p2.ypos;
	}
	
}
void Sort(Point & h1, Point & h2, Point & v1, Point & v2)
{
	Point temp;
	if (h1.xpos > h2.xpos) {
		temp.xpos = h1.xpos;
		h1.xpos = h2.xpos;
		h2.xpos = temp.xpos;
	}
	if (v1.ypos > v2.ypos)
	{
		temp.ypos = v1.ypos;
		v1.ypos = v2.ypos;
		v2.ypos = temp.ypos;
	}
}