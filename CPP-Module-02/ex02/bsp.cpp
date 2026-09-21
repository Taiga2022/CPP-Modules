#include "Point.hpp"

static float cross(const Point &a, const Point &b, const Point &point)
{
	return ((b.getX().toFloat() - a.getX().toFloat())
		* (point.getY().toFloat() - a.getY().toFloat())
		- (b.getY().toFloat() - a.getY().toFloat())
		* (point.getX().toFloat() - a.getX().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const float ab = cross(a, b, point);
	const float bc = cross(b, c, point);
	const float ca = cross(c, a, point);

	if (ab == 0.0f || bc == 0.0f || ca == 0.0f)
		return (false);
	return ((ab > 0.0f && bc > 0.0f && ca > 0.0f)
		|| (ab < 0.0f && bc < 0.0f && ca < 0.0f));
}
