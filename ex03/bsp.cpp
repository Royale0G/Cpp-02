#include "Point.hpp"

Fixed const fixedabs(Fixed const fixed) {
	if (fixed < 0) {
		return fixed * -1;
	}
	return fixed;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed half = 0.5f;
	Fixed totalA = half * fixedabs(a.getX()*(b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	Fixed a1 = half * fixedabs(point.getX()*(b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY()));
	Fixed a2 = half * fixedabs(a.getX()*(point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY()));
	Fixed a3 = half * fixedabs(a.getX()*(b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY()));
	if(a1 + a2 + a3 != totalA) {
		return false;
	}
	else
		return true;
}
