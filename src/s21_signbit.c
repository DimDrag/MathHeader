#include "s21_math.h"

int s21_signbit(double x) {
  double x_cp = x;
  unsigned long long L =
      (*((unsigned long long*)&x_cp)) & ((unsigned long long)1 << 63);
  return (L != 0);
}