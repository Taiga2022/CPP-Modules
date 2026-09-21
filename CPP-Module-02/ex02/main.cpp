#include "Point.hpp"
#include <iostream>

static void test(const Point &a, const Point &b, const Point &c,
	const Point &point, const char *description)
{
	std::cout << description << ": "
		<< (bsp(a, b, c, point) ? "inside" : "outside") << std::endl;
}

int main(void)
{
	const Point a(0.0f, 0.0f);
	const Point b(10.0f, 0.0f);
	const Point c(0.0f, 10.0f);

	test(a, b, c, Point(2.0f, 2.0f), "inner point");
	test(a, b, c, Point(8.0f, 8.0f), "outer point");
	test(a, b, c, Point(5.0f, 0.0f), "edge point");
	test(a, b, c, Point(0.0f, 0.0f), "vertex");
	return (0);
}
