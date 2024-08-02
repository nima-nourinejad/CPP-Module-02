#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  ~Fixed();
  Fixed(const Fixed &src);
  Fixed &operator=(const Fixed &src);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  Fixed operator+(const Fixed &src) const;
  Fixed operator-(const Fixed &src) const;
  Fixed operator*(const Fixed &src) const;
  Fixed operator/(const Fixed &src) const;

  bool operator>(const Fixed &src) const;
  bool operator<(const Fixed &src) const;
  bool operator>=(const Fixed &src) const;
  bool operator<=(const Fixed &src) const;
  bool operator==(const Fixed &src) const;
  bool operator!=(const Fixed &src) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static Fixed const &min(const Fixed &a, const Fixed &b);
  static Fixed const &max(const Fixed &a, const Fixed &b);

  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);

private:
  static const int _nbFractionalBits;
  int _rawBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif
