// ConsoleApplication44.cpp: 定义控制台应用程序的入口点。
//4_4.cpp-类-对象

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;

//point类的定义
class Point {
public:
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	Point(Point &p);
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
private:
	int x, y;
};
//复制构造函数的实现
Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	cout << "calling the copy constructor of point" << endl;
}



//类的组合
class Line {
public:
	Line(Point xp1, Point xp2);
	Line(Line &l);
	double getlen() {
		return len;
	}
private:
	Point p1, p2;
	double len;
};
//组合类的构造函数
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
	cout << "calling constructor of line" << endl;
	double x = static_cast<double>(p1.getx() - p2.getx());
	double y = static_cast<double>(p1.gety() - p2.gety());
	len = sqrt(x*x + y*y);
}
//组合类的复制构造函数
Line::Line(Line &l) : p1(l.p1), p2(l.p2) {
	cout << "calling the copy constructor of line" << endl;
	len = l.len;
}

int main()
{
	Point myp1(1, 1), myp2(4, 5);
	Line line(myp1, myp2);
	Line line2(line);
	cout << "the length of the line is:";
	cout << line.getlen() << endl;
	cout << "the length of the line2 is:";
	cout << line2.getlen() << endl;
	return 0;
}

