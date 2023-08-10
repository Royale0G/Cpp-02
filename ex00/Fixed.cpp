#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called." << std::endl;
}

Fixed::Fixed(Fixed &fixed){
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