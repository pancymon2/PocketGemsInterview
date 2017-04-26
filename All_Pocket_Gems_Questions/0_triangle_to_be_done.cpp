#include<iostream>

using namespace std;

const double ebsilon = 1e-6;

class point
{
public:
	double x;
	double y;

	point() {}

	point(double x, double y) :x(x), y(y) {}

	point operator-(point& rhs)
	{
		point ret;
		ret.x = x - rhs.x;
		ret.y = y - rhs.y;
		return ret;
	}

	double operator*(point& rhs)
	{
		return x*rhs.y - y*rhs.x;
	}
};

double area(point a, point b, point c)
{
	point ab = b - a;
	point ac = c - a;
	return 0.5*abs(ab*ac);
}

bool point_in_triangle_area(point a, point b, point c, point p)
{
	double abp = area(a, b, p);
	double acp = area(a, c, p);
	double bcp = area(b, c, p);
	double abc = area(a, b, c);
	return abp + acp + bcp - abc < ebsilon;
}

bool same_side_of_ab(point a, point b, point m, point n)
{
	point ab = b - a;
	point am = m - a;
	point an = n - a;
	return (ab*am)*(ab*an) >= 0;
}

bool point_in_triangle_line(point a, point b, point c, point p)
{
	return same_side_of_ab(a, b, c, p) && same_side_of_ab(a, c, b, p) && same_side_of_ab(b, c, a, p);
}

//int main()
//{
//	int x1, y1, x2, y2, x3, y3, x4, y4;
//	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
//	{
//		point a(x1, y1);
//		point b(x2, y2);
//		point c(x3, y3);
//		point p(x4, y4);
//		cout << point_in_triangle_area(a, b, c, p) << endl;
//		cout << point_in_triangle_line(a, b, c, p) << endl;
//	}
//}