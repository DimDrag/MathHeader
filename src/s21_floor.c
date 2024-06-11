#include "s21_math.h"

long double s21_floor(double x) {
  double res = 0;
  if (s21_isinf(x))
    res = x;
  else if (s21_isnan(x))
    res = x;
  else {
    res = x - s21_fmod(x, 1);
    if (x < 0) res -= 1;
  }
  return res;
}