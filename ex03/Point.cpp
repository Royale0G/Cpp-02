#include "Point.hpp"

Point::Point(){}

Point::Point(Point &point) : x(point.x), y(point.y) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::~Point() {}

Point &Point::operator=(Point const &point) {
	if (this != &point) {
		*this = point;
	}
	return *this;
}

Fixed const Point::getX() const {
	return this->x;
}

Fixed const Point::getY() const {
	return this->y;
}
