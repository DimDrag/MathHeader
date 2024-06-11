#include "s21_math.h"

long double s21_log(double x) {
  long double ans = 0;
  if (s21_isnan(x))
    ans = x;
  else if (x < 0)
    ans = S21_NEG_NAN;
  else if (x == 0)
    ans = S21_NEG_INFINITY;
  else if (x == S21_POS_INFINITY)
    ans = x;
  else {
    int k = 0;
    for (; s21_fabsl(x) < 1; x *= 2, k--)
      ;
    for (; s21_fabsl(x) > 1; x /= 2, k++)
      ;
    if (s21_fabsl(x - 1) < 1) {
      for (int n = 1; n < 200; n++) {
        ans -= s21_powi(-1, n) * s21_powi(-1 + x, n) / n;
      }
    }
    ans += S21_LN_2 * k;
  }
  return ans;
}