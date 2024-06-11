#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (s21_isnan(x))
    res = x;
  else if (s21_isnan(y))
    res = y;
  else if (s21_isinf(x))
    res = S21_NEG_NAN;
  else if (s21_isinf(y))
    res = x;
  else if (y == 0)
    res = S21_NEG_NAN;
  else {
    if (y < 0) y *= -1;
    int minus_flag = 0;
    if (x < 0) {
      x *= -1;
      minus_flag = 1;
    }
    while (x >= y) {
      long double diff = y;
      while (x > diff * 2) {
        diff *= 2;
      }
      x -= diff;
    }
    if (minus_flag) x *= -1;
    res = x;
  }
  return res;
}