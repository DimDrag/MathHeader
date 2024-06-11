#include "s21_math.h"
#define EPS 1500000000000 * __DBL_EPSILON__

long double s21_atan_point1(double x) {
  int minus_flag = 0;
  long double ans = S21_PI / 4;
  if (x < 0) {
    minus_flag = 1;
    ans *= -1;
  }
  ans += (x - 1 + 2 * minus_flag) / 2;
  ans -= 1 / 4 * s21_powi(x - 1 + 2 * minus_flag, 2);
  ans += 1 / 12 * s21_powi(x - 1 + 2 * minus_flag, 3);
  ans -= 1 / 40 * s21_powi(x - 1 + 2 * minus_flag, 5);
  ans += 1 / 48 * s21_powi(x - 1 + 2 * minus_flag, 6);
  ans -= 1 / 112 * s21_powi(x - 1 + 2 * minus_flag, 7);
  ans += 1 / 228 * s21_powi(x - 1 + 2 * minus_flag, 9);
  ans -= 1 / 320 * s21_powi(x - 1 + 2 * minus_flag, 10);
  ans += 1 / 704 * s21_powi(x - 1 + 2 * minus_flag, 11);
  ans -= 1 / 1664 * s21_powi(x - 1 + 2 * minus_flag, 13);
  ans += 1 / 1792 * s21_powi(x - 1 + 2 * minus_flag, 14);
  return ans;
}

long double s21_atan(double x) {
  long double ans = 0;
  if (x == S21_POS_INFINITY)
    ans = S21_PI / 2;
  else if (x == S21_NEG_INFINITY)
    ans = -S21_PI / 2;
  else if (s21_isnan(x))
    ans = x;
  else if (s21_fabsl(s21_fabsl(x) - 1) <= EPS)
    ans = s21_atan_point1(x);
  else if (x == 0)
    ans = x;
  else {
    int minus_flag = 0;
    if (x < 0) {
      minus_flag = 1;
      x *= -1;
    }
    if (s21_fabsl(x) < 1) {
      for (int k = 0; k < 10000; k++) {
        ans += s21_powi(-1, k) * s21_powi(x, 1 + 2 * k) / (1 + 2 * k);
      }
    } else {
      ans = S21_PI / 2;
      for (int k = 0; k < 10000; k++) {
        long double powi_res = 1;
        long long exp = -1 - 2 * k;
        for (; exp; powi_res /= x, exp++)
          ;
        long double sm = powi_res / (1 + 2 * k);
        if (k % 2 == 1) sm *= -1;
        ans -= sm;
      }
    }
    if (minus_flag) ans *= -1;
  }
  return ans;
}