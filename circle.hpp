#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(int a, int b) :x(a), y(b) { }
	~Point() {}

	void setY(int y) {
		this->y = y;
	}

	void setX(int x) {
		this->x = x;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

class Circle {
protected:
	const double pi = 3.1415;
	Point center;
	int radius;
public:

	Circle() {
		center.setX(0);
		center.setY(0);
		radius = 0;
	}
	
	Circle(int a, int b, int radius)
	{
		center.setX(a);
		center.setY(b);
		this->radius = radius;
	}

	~Circle() {}
	/*
	int getCommonChordEquation(Circle a)  //Equation of Straight line Across the Intersection of two circles
	{
		//�������� ������ ���ϱ�
		if (isIntersectionTrue(a) == 0)
		{

		}
		else if (isIntersectionTrue(a) > 0)
		{

		}
		else
		{
			cout <<
		}
	}
	*/

	int isIntersectionTrue(Circle a)	//�� ���� ���� ���� ���� Ȯ��
	{
		if (getCentralDistance(a) == ((double)radius + (double)a.radius) && getCentralDistance(a) != 0)
			return 0;		//0�̸� ���Ѵ�.
		else if (getCentralDistance(a) > ((double)radius + (double)a.radius))
			return -1;		//������ �ʴ´�. (������ ����.)
		else
			return 1;		//������ �� �� �̻� �ִ�. (��ġ�� ���ϰ�� ������ �����ϴ�)
	}

	double getCircleDistance(Circle a)		//���� �������� �Ÿ�
	{
		if (isIntersectionTrue(a) >= 0)
			return 0;
		else {
			double tmp = getCentralDistance(a);
			tmp = tmp - a.radius - radius;
			return tmp;
		}
	}

	double getCentralDistance(Circle a)		//���� �߽ɰ��� �Ÿ�
	{
		double dist_x;
		double dist_y;

		dist_x = abs(a.center.getX() - center.getX());
		dist_y = abs(a.center.getY() - center.getY());

		return sqrt(pow(dist_x, 2) + pow(dist_y, 2));
	}

	double getWidth() {
		return pi * radius * radius;
	}

	double getCircumference() {
		return pi * (radius * 2.0);
	}

	int getCenterY() {
		return center.getY();
	}

	int getCenterX() {
		return center.getX();
	}

	int getDiameter() {
		return radius * 2;
	}

	int getRadius() {
		return radius;
	}

	void setCenter(int x, int y) {
		center.setX(x);
		center.setY(y);
	}

	void setRadius(int radius) {
		this->radius = radius;
	}
};

class Sphere : public Circle {
public:

	Sphere() {}
	Sphere(int a, int b, int radius)
	{
		center.setX(a);
		center.setY(b);
		this->radius = radius;
	}
	~Sphere() {}

	double getSurfaceArea() {
		return 4 * pow(radius, 2) * pi;
	}

	double getVolume() {
		return (4 * pow(radius, 3) * pi) / 3;
	}
};