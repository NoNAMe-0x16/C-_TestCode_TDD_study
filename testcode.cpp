#include "circle.hpp"

const double pi = 3.1415;

void test_get_value(int x, int y, int r)
{
	Point tmp(x, y);
	Circle a(x, y, r);
	
	if(tmp.getX() != x)
		cout << "-> test_get_value �׽�Ʈ ����. \n-> ���� : getX() \n";
	if (tmp.getY() != y)
		cout << "-> test_get_value �׽�Ʈ ����. \n-> ���� : getY() \n";
	if (a.getRadius() != r)
		cout << "-> test_get_value �׽�Ʈ ����. \n-> ���� : getRadius() \n";
	if (a.getDiameter() != r * 2)
		cout << "-> test_get_value �׽�Ʈ ����. \n-> ���� : getDiameter() \n";
	if (a.getWidth() != (double)r * (double)r * pi)
		cout << "-> test_get_value �׽�Ʈ ����. \n-> ���� : getWidth() \n";
}

void test_set_value(int x, int y, int r)
{
	Point tmp(x, y);
	Circle a(x, y, r);

	tmp.setX(x);
	if(tmp.getX() != x)
		cout << "-> test_set_value �׽�Ʈ ����. \n-> ���� : setX() \n";

	tmp.setY(y);
	if(tmp.getY() != y)
		cout << "-> test_set_value �׽�Ʈ ����. \n-> ���� : setY() \n";

	a.setRadius(r);
	if(a.getRadius() != r)
		cout << "-> test_set_value �׽�Ʈ ����. \n-> ���� : setRadius() \n";

	a.setCenter(x, y);
	if(a.getCenterX() != x)
		cout << "-> test_set_value �׽�Ʈ ����. \n-> ���� : setCenter() \n";
	if (a.getCenterY() != y)
		cout << "-> test_set_value �׽�Ʈ ����. \n-> ���� : setCenter() \n";
}

void test_TwoCircles_method(int x1, int y1, int r1, int x2, int y2, int r2)
{
	Circle a(x1, y1, r1), b(x2, y2, r2);
	if(a.getCentralDistance(b) != sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))
		cout << "-> test_TwoCircles_method �׽�Ʈ ����. \n-> ���� : getCentralDistance() \n";
	if(a.getCircleDistance(b) != sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) - r1 - r2)
		cout << "-> test_TwoCircles_method �׽�Ʈ ����. \n-> ���� : getCircleDistance() \n";
}

void test_Sphere_method(int x, int y, int r) {
	Sphere a(x, y, r);
	if( a.getSurfaceArea() != 4 * pow(r, 2) * pi)
		cout << "-> test_Sphere_method �׽�Ʈ ����. \n-> ���� : getSurfaceArea() \n";
	if( a.getVolume() != (4 * pow(r, 3) * pi) / 3)
		cout << "-> test_Sphere_method �׽�Ʈ ����. \n-> ���� : getVolume() \n";
}

int main(void)
{
	test_get_value(5, 5, 4);
	test_set_value(4, 4, 10);
	test_TwoCircles_method(5, 5, 4, -1, 4, 2);
	test_Sphere_method(1, 1, 10);
}