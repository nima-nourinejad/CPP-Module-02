#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &src): _rawBits(src._rawBits) {
  std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = src._rawBits;
  return *this;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _rawBits;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
}
const int Fixed::_nbFractionalBits = 8;