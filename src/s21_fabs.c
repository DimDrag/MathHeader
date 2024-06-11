#include "s21_math.h"

long double s21_fabs(double x) {
  unsigned long long L =
      (*((unsigned long long*)&x)) & ~((unsigned long long)1 << 63);
  return *((double*)&L);
}
