#include "Fixed.hpp"

int customRound(float value) {
  float myRound;
  myRound = std::abs(value - floor(value)) >= 0.5 ? ceil(value) : floor(value);
  return (static_cast<int>(myRound));
}
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const int value) { _rawBits = value << _nbFractionalBits; }
Fixed::Fixed(const float value) {
  _rawBits = std::roundf(value * (1 << _nbFractionalBits));
}
Fixed::~Fixed() {}
Fixed::Fixed(const Fixed &src){ *this = src; }
Fixed &Fixed::operator=(const Fixed &src) {
  this->_rawBits = src.getRawBits();
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

Fixed Fixed::operator+(const Fixed &src) const {
  return Fixed(this->toFloat() + src.toFloat());
}
Fixed Fixed::operator-(const Fixed &src) const {
  return Fixed(this->toFloat() - src.toFloat());
}
Fixed Fixed::operator*(const Fixed &src) const {
  return Fixed(this->toFloat() * src.toFloat());
}
Fixed Fixed::operator/(const Fixed &src) const {
  return Fixed(this->toFloat() / src.toFloat());
}

bool Fixed::operator>(const Fixed &src) const {
  return this->_rawBits > src._rawBits;
}
bool Fixed::operator<(const Fixed &src) const {
  return this->_rawBits < src._rawBits;
}
bool Fixed::operator>=(const Fixed &src) const {
  return this->_rawBits >= src._rawBits;
}
bool Fixed::operator<=(const Fixed &src) const {
  return this->_rawBits <= src._rawBits;
}
bool Fixed::operator==(const Fixed &src) const {
  return this->_rawBits == src._rawBits;
}
bool Fixed::operator!=(const Fixed &src) const {
  return this->_rawBits != src._rawBits;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
  if (b < a)
    return b;
  return a;
}
Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
  if (b > a)
    return b;
  return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (b < a)
    return b;
  return a;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (b > a)
    return b;
  return a;
}

Fixed &Fixed::operator++() {
  ++_rawBits;
  return *this;
}
Fixed &Fixed::operator--() {
  --_rawBits;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed before = *this;
  ++_rawBits;
  return before;
}
Fixed Fixed::operator--(int) {
  Fixed before = *this;
  --_rawBits;
  return before;
}