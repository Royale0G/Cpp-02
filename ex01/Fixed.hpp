#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed{
private:
	int value;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(Fixed const &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int value);
	Fixed(const float value);
	int toInt(void) const;
	float toFloat(void) const;
	friend std::ostream& operator<<(std::ostream& os, const Fixed& copy);
};
#endif
