#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &src){
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}
Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = src.getRawBits();
  return *this;
}
int Fixed::getRawBits(void) const { return _rawBits; }
void Fixed::setRawBits(int const raw) { _rawBits = raw; }
const int Fixed::_nbFractionalBits = 8;
//////////////////////////////
Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _rawBits = value << _nbFractionalBits;
}
Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _rawBits = std::roundf(value * (1 << _nbFractionalBits));
}
float Fixed::toFloat(void) const {
  return static_cast<float>(_rawBits) / (1 << _nbFractionalBits);
}
int Fixed::toInt(void) const { return _rawBits >> _nbFractionalBits; }
std::ostream &operator<<(std::ostream &out, const Fixed &src) {
  out << src.toFloat();
  return out;
}