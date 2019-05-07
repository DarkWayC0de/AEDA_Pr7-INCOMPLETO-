//
// Created by darkwaycode on 23/04/19.
//

#include "../include/DNI.h"

DNI::DNI():DNI_(0) {

}
DNI::DNI(long long int dni):DNI_(dni) {

}
DNI::~DNI() = default;
bool DNI::operator<(const DNI &rhs) const {
  return DNI_ < rhs.DNI_;
}
bool DNI::operator>(const DNI &rhs) const {
  return rhs < *this;
}
bool DNI::operator<=(const DNI &rhs) const {
  return !(rhs < *this);
}
bool DNI::operator>=(const DNI &rhs) const {
  return !(*this < rhs);
}
bool DNI::operator==(const DNI &rhs) const {
  return DNI_ == rhs.DNI_;
}
bool DNI::operator!=(const DNI &rhs) const {
  return !(rhs == *this);
}
std::ostream &operator<<(std::ostream &os, const DNI &dni) {
  os << dni.DNI_;
  return os;
}
void DNI::setDni(long long int dni) {
  DNI_ = dni;
}
