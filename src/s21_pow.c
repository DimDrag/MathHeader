#include "s21_math.h"

long double s21_pow_solve_limits_and_nan_situations(double a, double x,
                                                    int* extreme_case) {
  long double ans = 0;
  if (x == 0)
    ans = 1;
  else if (s21_isnan(a)) {
    if (s21_fabsl(x) == 1)
      ans = S21_POS_NAN;
    else
      ans = a;
  } else if (s21_isnan(x)) {
    if (a == 1)
      ans = 1;
    else
      ans = x;
  } else if (x == S21_POS_INFINITY) {
    if (s21_fabsl(a) == 1)
      ans = s21_fabsl(a);
    else if (a == 0)
      ans = 0;
    else
      ans = x;
  } else if (x == S21_NEG_INFINITY) {
    if (a == 0)
      ans = S21_POS_INFINITY;
    else if (s21_fabsl(a) == 1)
      ans = 1;
    else
      ans = 0;
  } else if (s21_isinf(a)) {
    if (a == S21_POS_INFINITY && x < 0)
      ans = 0;
    else if (a == S21_POS_INFINITY && x > 0)
      ans = a;
    else if (a == S21_NEG_INFINITY) {
      if (x > 0) {
        if (s21_fmod(x, 1) != 0)
          ans = S21_POS_INFINITY;
        else if (s21_fmod(x, 2) == 1)
          ans = a;
        else
          ans = S21_POS_INFINITY;
      } else {
        if (s21_fmod(x, 1) != 0)
          ans = +0.0;
        else if (s21_fmod(x, 2) == -1)
          ans = -0.0;
        else
          ans = 0;
      }
    }
  } else if (a == 0) {
    if (s21_signbit(a) == 0) {
      if (x > 0)
        ans = 0;
      else
        ans = S21_POS_INFINITY;
    } else {
      if (x > 0) {
        if (s21_fmod(x, 1) != 0)
          ans = 0;
        else if (s21_fmod(x, 2) == 1)
          ans = a;
        else
          ans = 0;
      } else {
        if (s21_fmod(x, 1) != 0)
          ans = S21_POS_INFINITY;
        else if (s21_fmod(x, 2) == -1) {
          ans = S21_NEG_INFINITY;
        } else
          ans = S21_POS_INFINITY;
      }
    }

  } else if (a < 0 && s21_fmod(x, 1) != 0)
    ans = S21_NEG_NAN;
  else {
    *extreme_case = 0;
  }
  return ans;
}

long double s21_pow(double base, double exp) {
  long double ans = 0;
  // base = 2^m * n
  // exp = k + l
  // base^exp = (2^mk * n^k) * (2^ml * n*l)
  int extreme_case = 1;
  ans = s21_pow_solve_limits_and_nan_situations(base, exp, &extreme_case);
  if (!extreme_case) {
    if (s21_fmod(exp, 1) == 0)
      ans = s21_powi(base, exp);
    else {
      int minus_flag = 0;
      if (base < 0) {
        if (s21_fabsl(s21_fmod(exp, 2)) == 1) minus_flag = 1;
        base *= -1;
      }
      double m = 0;
      double k = 0;
      for (; base < 1; base *= 2, m--)
        ;
      for (; base > 1; base /= 2, m++)
        ;

      k += exp - s21_fmod(exp, 1);
      exp = s21_fmod(exp, 1);

      ans += s21_powi(2, m * k) * s21_powi(base, k);
      long double part1 = 0;
      for (int i = 0; i < 300; i++) {
        part1 += s21_powi(m * exp * s21_log(2), i) / s21_factorial(i);
      }
      long double part2 = 0;
      for (int i = 0; i < 300; i++) {
        part2 += s21_powi(exp * s21_log(base), i) / s21_factorial(i);
      }
      ans *= (part1 != 0) ? part1 : 1;
      ans *= (part2 != 0) ? part2 : 1;
      if (minus_flag) ans *= -1;
    }
  }
  return (double)ans;
}