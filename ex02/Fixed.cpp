#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called." << std::endl;
}

Fixed::Fixed(Fixed const &fixed){
	std::cout << "Copy constructor called." << std::endl;
	value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed){
	std::cout << "Assignation operator called." << std::endl;
	value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called." << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called." << std::endl;
	value = raw;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called." << std::endl;
	this->value = value << fractional_bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called." << std::endl;
	this->value = roundf(value * (1 << fractional_bits));
}

int Fixed::toInt(void) const{
	return (int)(this->value >> fractional_bits);
}

float Fixed::toFloat(void) const{
	return (float)this->value / (float)(1 << fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& copy){
	os << copy.toFloat();
	return os;
}

Fixed Fixed::operator+(const Fixed &fixed){
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed){
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed){
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed){
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(){
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(){
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

bool Fixed::operator>(const Fixed &fixed) const{
	return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const{
	return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const{
	return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const{
	return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const{
	return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const{
	return this->toFloat() != fixed.toFloat();
}
