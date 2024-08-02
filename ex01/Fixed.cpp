#include "Fixed.hpp"

int customRound(float value) {
  float myRound;
  myRound = std::abs(value - floor(value)) >= 0.5 ? ceil(value) : floor(value);
  return (static_cast<int>(myRound));
}
Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _rawBits = value << _nbFractionalBits;
}
Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _rawBits = customRound(value * (1 << _nbFractionalBits));
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &src) : _rawBits(src._rawBits) {
  std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = src._rawBits;
  return *this;
}
int Fixed::getRawBits(void) const { return _rawBits; }
void Fixed::setRawBits(int const raw) { _rawBits = raw; }
float Fixed::toFloat(void) const {
  return static_cast<float>(_rawBits) / (1 << _nbFractionalBits);
}
int Fixed::toInt(void) const { return _rawBits >> _nbFractionalBits; }
std::ostream &operator<<(std::ostream &out, const Fixed &src) {
  out << src.toFloat();
  return out;
}
const int Fixed::_nbFractionalBits = 8;