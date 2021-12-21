#include "pch.h"
#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle() : Point(), r(0)
{
	cout << "Вызван конструктор по умолчанию класса Circle : Circle()" << endl;
}

Circle::Circle(float a, float b, float rad) : Point(a, b), r(rad)
{
	cout << "Вызван конструктор с параметрами класса Circle : Circle(" << x << ", " << y << "," << rad << ")" << endl;
}

Circle::Circle(Circle& circle) : Point(circle), r(circle.r)
{
	cout << "Вызван конструктор копирования класса Circle : Circle (Circle& circle)" << endl;
}

void Circle::Modify()
{
	Point::Modify();
	cout << "  Radius = ";
	cin >> r;
}


void Circle::Print()
{
	Point::Print();
	cout << " || значение r : " << r;
}

const char* Circle::GetType()
{
	return "Circle";
}


Circle::~Circle()
{
	cout << "Вызван деструктор класса Circle" << endl;
}
