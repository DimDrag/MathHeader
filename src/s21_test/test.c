#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#define NO_FORK
#define EPS 1e-6

START_TEST(test_abs) {
  ck_assert_int_eq(abs(90), s21_abs(90));
  ck_assert_int_eq(abs(-123), s21_abs(-123));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_ldouble_eq(fabs(0.00120993), s21_fabs(0.00120993));
  ck_assert_ldouble_eq(fabs(-0.00120993), s21_fabs(-0.00120993));
  ck_assert_ldouble_eq(fabs(1.79E308), s21_fabs(1.79E308));
  ck_assert_ldouble_eq(fabs(-1.79E308), s21_fabs(-1.79E308));

  ck_assert_int_eq(fabs(S21_POS_INFINITY) == INFINITY,
                   s21_fabs(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(fabs(S21_NEG_INFINITY) == INFINITY,
                   s21_fabs(S21_NEG_INFINITY) == INFINITY);

  ck_assert_ldouble_nan(fabs(S21_POS_NAN));
  ck_assert_ldouble_nan(fabs(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_NEG_NAN));
}
END_TEST

START_TEST(test_atan) {
  ck_assert_ldouble_eq_tol(atan(1E16), s21_atan(1E16), EPS);
  ck_assert_ldouble_eq_tol(atan(-1E16), s21_atan(-1E16), EPS);
  ck_assert_ldouble_eq_tol(atan(+1 + __DBL_EPSILON__),
                           s21_atan(+1 + __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 + __DBL_EPSILON__),
                           s21_atan(-1 + __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(+1 + 1E9 * __DBL_EPSILON__),
                           s21_atan(+1 + 1E9 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 + 1E9 * __DBL_EPSILON__),
                           s21_atan(-1 + 1E9 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(+1 - 19985E8 * __DBL_EPSILON__),
                           s21_atan(+1 - 19985E8 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 - 19985E8 * __DBL_EPSILON__),
                           s21_atan(-1 - 19985E8 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 + 19985E8 * __DBL_EPSILON__),
                           s21_atan(-1 + 19985E8 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(+1 + 15E11 * __DBL_EPSILON__),
                           s21_atan(+1 + 15E11 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 - 15E11 * __DBL_EPSILON__),
                           s21_atan(-1 - 15E11 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 + 15E11 * __DBL_EPSILON__),
                           s21_atan(-1 + 15E11 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(+1), s21_atan(+1), EPS);
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), EPS);
  ck_assert_ldouble_eq_tol(atan(+0.0), s21_atan(+0.0), EPS);
  ck_assert_ldouble_eq_tol(atan(-0.0), s21_atan(-0.0), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 - __DBL_EPSILON__),
                           s21_atan(-1 - __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(atan(-1 - 1E9 * __DBL_EPSILON__),
                           s21_atan(-1 - 1E9 * __DBL_EPSILON__), EPS);

  ck_assert_int_eq(atan(S21_POS_INFINITY) == INFINITY,
                   s21_atan(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(atan(S21_NEG_INFINITY) == -INFINITY,
                   s21_atan(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(atan(S21_POS_NAN));
  ck_assert_ldouble_nan(atan(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_atan(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_atan(S21_NEG_NAN));
}
END_TEST

START_TEST(test_asin) {
  ck_assert_ldouble_nan(asin(1E16));
  ck_assert_ldouble_nan(s21_asin(1E16));
  ck_assert_ldouble_nan(asin(-1E16));
  ck_assert_ldouble_nan(s21_asin(-1E16));
  ck_assert_ldouble_nan(asin(+1 + __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(+1 + __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(asin(-1 + __DBL_EPSILON__),
                           s21_asin(-1 + __DBL_EPSILON__), EPS);
  ck_assert_ldouble_nan(asin(+1 + 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(+1 + 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(asin(-1 + 1E9 * __DBL_EPSILON__),
                           s21_asin(-1 + 1E9 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(asin(+1 - 19985E8 * __DBL_EPSILON__),
                           s21_asin(+1 - 19985E8 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_nan(asin(-1 - 19985E8 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(-1 - 19985E8 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(asin(+1 + 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(+1 + 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(asin(-1 - 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(-1 - 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(asin(-1 + 15E11 * __DBL_EPSILON__),
                           s21_asin(-1 + 15E11 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(asin(+1), s21_asin(+1), EPS);
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), EPS);
  ck_assert_ldouble_eq_tol(asin(+0.0), s21_asin(+0.0), EPS);
  ck_assert_ldouble_eq_tol(asin(-0.0), s21_asin(-0.0), EPS);
  ck_assert_ldouble_nan(asin(-1 - __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(-1 - __DBL_EPSILON__));
  ck_assert_ldouble_nan(asin(-1 - 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_asin(-1 - 1E9 * __DBL_EPSILON__));

  ck_assert_int_eq(asin(S21_POS_INFINITY) == INFINITY,
                   s21_asin(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(asin(S21_NEG_INFINITY) == -INFINITY,
                   s21_asin(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(asin(S21_POS_NAN));
  ck_assert_ldouble_nan(asin(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_NEG_NAN));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_ldouble_nan(acos(1E16));
  ck_assert_ldouble_nan(s21_acos(1E16));
  ck_assert_ldouble_nan(acos(-1E16));
  ck_assert_ldouble_nan(s21_acos(-1E16));
  ck_assert_ldouble_nan(acos(+1 + __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(+1 + __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(acos(-1 + __DBL_EPSILON__),
                           s21_acos(-1 + __DBL_EPSILON__), EPS);
  ck_assert_ldouble_nan(acos(+1 + 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(+1 + 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(acos(-1 + 1E9 * __DBL_EPSILON__),
                           s21_acos(-1 + 1E9 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(acos(+1 - 19985E8 * __DBL_EPSILON__),
                           s21_acos(+1 - 19985E8 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_nan(acos(-1 - 19985E8 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(-1 - 19985E8 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(acos(+1 + 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(+1 + 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(acos(-1 - 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(-1 - 15E11 * __DBL_EPSILON__));
  ck_assert_ldouble_eq_tol(acos(-1 + 15E11 * __DBL_EPSILON__),
                           s21_acos(-1 + 15E11 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(acos(+1), s21_acos(+1), EPS);
  ck_assert_ldouble_eq_tol(acos(-1), s21_acos(-1), EPS);
  ck_assert_ldouble_eq_tol(acos(+0.0), s21_acos(+0.0), EPS);
  ck_assert_ldouble_eq_tol(acos(-0.0), s21_acos(-0.0), EPS);
  ck_assert_ldouble_nan(acos(-1 - __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(-1 - __DBL_EPSILON__));
  ck_assert_ldouble_nan(acos(-1 - 1E9 * __DBL_EPSILON__));
  ck_assert_ldouble_nan(s21_acos(-1 - 1E9 * __DBL_EPSILON__));

  ck_assert_int_eq(acos(S21_POS_INFINITY) == INFINITY,
                   s21_acos(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(acos(S21_NEG_INFINITY) == -INFINITY,
                   s21_acos(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(acos(S21_POS_NAN));
  ck_assert_ldouble_nan(acos(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_NEG_NAN));
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_ldouble_nan(sqrt(-1.7E17));
  ck_assert_ldouble_nan(s21_sqrt(-1.7E17));
  ck_assert_ldouble_eq_tol(sqrt(__DBL_EPSILON__), s21_sqrt(__DBL_EPSILON__),
                           EPS);
  ck_assert_ldouble_eq_tol(sqrt(1E17 * __DBL_EPSILON__),
                           s21_sqrt(1E17 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(sqrt(10.1231), s21_sqrt(10.1231), EPS);
  ck_assert_ldouble_eq_tol(sqrt(1000.28137119), s21_sqrt(1000.28137119), EPS);
  ck_assert_ldouble_nan(sqrt(-1000.28137119));
  ck_assert_ldouble_nan(s21_sqrt(-1000.28137119));
  ck_assert_ldouble_eq_tol(sqrt(1 + __DBL_EPSILON__),
                           s21_sqrt(1 + __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(sqrt(1.79E17), s21_sqrt(1.79E17), EPS);

  ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt(0.0), EPS);

  ck_assert_int_eq(sqrt(S21_POS_INFINITY) == INFINITY,
                   s21_sqrt(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(sqrt(S21_NEG_INFINITY) == -INFINITY,
                   s21_sqrt(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(sqrt(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_POS_NAN));
  ck_assert_ldouble_nan(sqrt(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NEG_NAN));
}
END_TEST

START_TEST(test_log) {
  ck_assert_ldouble_eq_tol(log(1 - 1E3 * __DBL_EPSILON__),
                           s21_log(1 - 1E3 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(log(1 + 1E3 * __DBL_EPSILON__),
                           s21_log(1 + 1E3 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(log(1E308 - 1E3 * __DBL_EPSILON__),
                           s21_log(1E308 - 1E3 * __DBL_EPSILON__), EPS);

  ck_assert_ldouble_nan(log(-10));
  ck_assert_ldouble_nan(s21_log(-10));
  ck_assert_int_eq(log(0) == -INFINITY, s21_log(0) == -INFINITY);

  ck_assert_ldouble_eq_tol(log(1), s21_log(1), EPS);
  ck_assert_ldouble_eq_tol(log(1.79E308), s21_log(1.79E308), EPS);
  ck_assert_int_eq(log(S21_POS_INFINITY) == INFINITY,
                   s21_log(S21_POS_INFINITY) == INFINITY);
  ck_assert_ldouble_nan(log(S21_NEG_INFINITY));
  ck_assert_ldouble_nan(s21_log(S21_NEG_INFINITY));

  ck_assert_ldouble_nan(log(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_log(S21_POS_NAN));
  ck_assert_ldouble_nan(log(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_log(S21_NEG_NAN));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_ldouble_eq_tol(exp(__DBL_EPSILON__ - 100),
                           s21_exp(__DBL_EPSILON__ - 100), EPS);
  ck_assert_ldouble_eq_tol(exp(__DBL_EPSILON__ + 100),
                           s21_exp(__DBL_EPSILON__ + 100), EPS);
  ck_assert_ldouble_eq_tol(exp(__DBL_EPSILON__), s21_exp(__DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(exp(-__DBL_EPSILON__), s21_exp(-__DBL_EPSILON__),
                           EPS);
  ck_assert_ldouble_eq_tol(exp(101), s21_exp(101), EPS);
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), EPS);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), EPS);
  ck_assert_ldouble_eq_tol(exp(-1), s21_exp(-1), EPS);
  ck_assert_ldouble_eq_tol(exp(709.7827), s21_exp(709.7827), EPS);
  ck_assert_int_eq(exp(S21_POS_INFINITY) == INFINITY,
                   s21_exp(S21_POS_INFINITY) == INFINITY);
  ck_assert_ldouble_eq_tol(exp(S21_NEG_INFINITY), s21_exp(-INFINITY), EPS);

  ck_assert_ldouble_nan(exp(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_POS_NAN));
  ck_assert_ldouble_nan(exp(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_NEG_NAN));
}
END_TEST

START_TEST(test_sin) {
  ck_assert_ldouble_eq_tol(sin(__DBL_EPSILON__ - 100),
                           s21_sin(__DBL_EPSILON__ - 100), EPS);
  ck_assert_ldouble_eq_tol(sin(__DBL_EPSILON__ + 100),
                           s21_sin(__DBL_EPSILON__ + 100), EPS);
  ck_assert_ldouble_eq_tol(sin(__DBL_EPSILON__), s21_sin(__DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(sin(-__DBL_EPSILON__), s21_sin(-__DBL_EPSILON__),
                           EPS);
  ck_assert_ldouble_eq_tol(sin(101), s21_sin(101), EPS);
  ck_assert_ldouble_eq_tol(sin(1), s21_sin(1), EPS);
  ck_assert_ldouble_eq_tol(sin(0), s21_sin(0), EPS);
  ck_assert_ldouble_eq_tol(sin(-1), s21_sin(-1), EPS);
  ck_assert_ldouble_eq_tol(sin(709.7827), s21_sin(709.7827), EPS);

  for (int i = 0; i < 10; i++) {
    ck_assert_ldouble_eq_tol(sin(i), s21_sin(i), EPS);
  }

  ck_assert_ldouble_nan(sin(S21_POS_INFINITY));
  ck_assert_ldouble_nan(s21_sin(S21_POS_INFINITY));
  ck_assert_ldouble_nan(sin(S21_NEG_INFINITY));
  ck_assert_ldouble_nan(s21_sin(S21_NEG_INFINITY));

  ck_assert_ldouble_nan(sin(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_POS_NAN));
  ck_assert_ldouble_nan(sin(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_NEG_NAN));
}
END_TEST

START_TEST(test_cos) {
  ck_assert_ldouble_eq_tol(cos(__DBL_EPSILON__ - 100),
                           s21_cos(__DBL_EPSILON__ - 100), EPS);
  ck_assert_ldouble_eq_tol(cos(__DBL_EPSILON__ + 100),
                           s21_cos(__DBL_EPSILON__ + 100), EPS);
  ck_assert_ldouble_eq_tol(cos(__DBL_EPSILON__), s21_cos(__DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(cos(-__DBL_EPSILON__), s21_cos(-__DBL_EPSILON__),
                           EPS);
  ck_assert_ldouble_eq_tol(cos(101), s21_cos(101), EPS);
  ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), EPS);
  ck_assert_ldouble_eq_tol(cos(0), s21_cos(0), EPS);
  ck_assert_ldouble_eq_tol(cos(-1), s21_cos(-1), EPS);
  ck_assert_ldouble_eq_tol(cos(709.7827), s21_cos(709.7827), EPS);

  ck_assert_ldouble_nan(cos(S21_POS_INFINITY));
  ck_assert_ldouble_nan(s21_cos(S21_POS_INFINITY));
  ck_assert_ldouble_nan(cos(S21_NEG_INFINITY));
  ck_assert_ldouble_nan(s21_cos(S21_NEG_INFINITY));

  ck_assert_ldouble_nan(cos(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_POS_NAN));
  ck_assert_ldouble_nan(cos(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_NEG_NAN));
}
END_TEST

START_TEST(test_tan) {
  ck_assert_ldouble_eq_tol(tan(__DBL_EPSILON__ - 100),
                           s21_tan(__DBL_EPSILON__ - 100), EPS);
  ck_assert_ldouble_eq_tol(tan(__DBL_EPSILON__ + 100),
                           s21_tan(__DBL_EPSILON__ + 100), EPS);
  ck_assert_ldouble_eq_tol(tan(__DBL_EPSILON__), s21_tan(__DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(tan(-__DBL_EPSILON__), s21_tan(-__DBL_EPSILON__),
                           EPS);
  ck_assert_ldouble_eq_tol(tan(101), s21_tan(101), EPS);
  ck_assert_ldouble_eq_tol(tan(1), s21_tan(1), EPS);
  ck_assert_ldouble_eq_tol(tan(0), s21_tan(0), EPS);
  ck_assert_ldouble_eq_tol(tan(-1), s21_tan(-1), EPS);
  ck_assert_ldouble_eq_tol(tan(709.7827), s21_tan(709.7827), EPS);

  ck_assert_ldouble_nan(tan(S21_POS_INFINITY));
  ck_assert_ldouble_nan(s21_tan(S21_POS_INFINITY));
  ck_assert_ldouble_nan(tan(S21_NEG_INFINITY));
  ck_assert_ldouble_nan(s21_tan(S21_NEG_INFINITY));

  ck_assert_ldouble_nan(tan(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_POS_NAN));
  ck_assert_ldouble_nan(tan(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_NEG_NAN));
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_ldouble_eq_tol(fmod(1.7E308, 13 * __DBL_EPSILON__),
                           s21_fmod(1.7E308, 13 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(fmod(1.7E298, 23 * __DBL_EPSILON__),
                           s21_fmod(1.7E298, 23 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(fmod(0, 0.4), s21_fmod(0, 0.4), EPS);
  ck_assert_ldouble_eq_tol(fmod(-6, 13 * __DBL_EPSILON__),
                           s21_fmod(-6, 13 * __DBL_EPSILON__), EPS);
  ck_assert_ldouble_eq_tol(fmod(-6.1263, 1), s21_fmod(-6.1263, 1), EPS);

  double* arr = (double*)calloc(10, sizeof(double));
  arr[0] = +0.0;
  arr[1] = -0.0;
  arr[2] = INFINITY;
  arr[3] = -INFINITY;
  arr[4] = +1.0;
  arr[5] = -1.0;
  arr[6] = S21_NEG_NAN;
  arr[7] = S21_POS_NAN;
  arr[8] = +5.4;
  arr[9] = -5.4;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (isnan(fmod(arr[i], arr[j]))) {
        ck_assert_ldouble_nan(fmod(arr[i], arr[j]));
        ck_assert_ldouble_nan(s21_fmod(arr[i], arr[j]));
      } else {
        ck_assert_ldouble_eq_tol(fmod(arr[i], arr[j]), s21_fmod(arr[i], arr[j]),
                                 EPS);
      }
    }
  }
  free(arr);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_ldouble_eq_tol(pow(-1.7E30, -1), s21_pow(-1.7E30, -1), EPS);
  ck_assert_ldouble_eq_tol(pow(__DBL_EPSILON__, -0.00034566),
                           s21_pow(__DBL_EPSILON__, -0.00034566), EPS);
  ck_assert_ldouble_eq_tol(pow(__DBL_EPSILON__, -1.1),
                           s21_pow(__DBL_EPSILON__, -1.1), EPS);
  ck_assert_ldouble_eq_tol(pow(__DBL_EPSILON__, -1.000000000000001),
                           s21_pow(__DBL_EPSILON__, -1.000000000000001), EPS);
  ck_assert_ldouble_eq_tol(pow(1E17 * __DBL_EPSILON__, 10.00034566),
                           s21_pow(1E17 * __DBL_EPSILON__, 10.00034566), EPS);
  ck_assert_ldouble_eq_tol(pow(10.1231, 100), s21_pow(10.1231, 100), EPS);
  ck_assert_ldouble_eq_tol(pow(__DBL_EPSILON__, -1.00000000000000000001),
                           s21_pow(__DBL_EPSILON__, -1.00000000000000000001),
                           EPS);
  ck_assert_ldouble_eq_tol(pow(1000.28137119, -0.01738172937190),
                           s21_pow(1000.28137119, -0.01738172937190), EPS);
  ck_assert_ldouble_nan(pow(-1000.28137119, -0.01738172937190));
  ck_assert_ldouble_nan(s21_pow(-1000.28137119, -0.01738172937190));
  ck_assert_ldouble_eq_tol(pow(1 + __DBL_EPSILON__, 1.79E10),
                           s21_pow(1 + __DBL_EPSILON__, 1.79E10), EPS);

  double* arr = (double*)calloc(10, sizeof(double));
  arr[0] = +0.0;
  arr[1] = -0.0;
  arr[2] = INFINITY;
  arr[3] = -INFINITY;
  arr[4] = +1.0;
  arr[5] = -1.0;
  arr[6] = S21_NEG_NAN;
  arr[7] = S21_POS_NAN;
  arr[8] = +5.4;
  arr[9] = -5.4;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (isnan(pow(arr[i], arr[j]))) {
        ck_assert_ldouble_nan(pow(arr[i], arr[j]));
        ck_assert_ldouble_nan(s21_pow(arr[i], arr[j]));
      } else if (pow(arr[i], arr[j]) == INFINITY) {
        ck_assert_int_eq(pow(arr[i], arr[j]) == INFINITY,
                         s21_pow(arr[i], arr[j]) == INFINITY);
      } else if (pow(arr[i], arr[j]) == -INFINITY) {
        ck_assert_int_eq(pow(arr[i], arr[j]) == -INFINITY,
                         s21_pow(arr[i], arr[j]) == -INFINITY);
      } else {
        ck_assert_ldouble_eq_tol(pow(arr[i], arr[j]), s21_pow(arr[i], arr[j]),
                                 EPS);
      }
    }
  }
  free(arr);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_ldouble_eq_tol(floor(-0.12), s21_floor(-0.12), EPS);
  ck_assert_ldouble_eq_tol(floor(0.12), s21_floor(0.12), EPS);
  ck_assert_ldouble_eq_tol(floor(-3.12), s21_floor(-3.12), EPS);
  ck_assert_ldouble_eq_tol(floor(3.12), s21_floor(3.12), EPS);
  ck_assert_ldouble_eq_tol(floor(-3.57), s21_floor(-3.57), EPS);
  ck_assert_ldouble_eq_tol(floor(3.57), s21_floor(3.57), EPS);

  ck_assert_int_eq(floor(S21_POS_INFINITY) == INFINITY,
                   s21_floor(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(floor(S21_NEG_INFINITY) == -INFINITY,
                   s21_floor(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(floor(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_POS_NAN));
  ck_assert_ldouble_nan(floor(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_NEG_NAN));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_ldouble_eq_tol(ceil(-0.12), s21_ceil(-0.12), EPS);
  ck_assert_ldouble_eq_tol(ceil(0.12), s21_ceil(0.12), EPS);
  ck_assert_ldouble_eq_tol(ceil(-3.12), s21_ceil(-3.12), EPS);
  ck_assert_ldouble_eq_tol(ceil(3.12), s21_ceil(3.12), EPS);
  ck_assert_ldouble_eq_tol(ceil(-3.57), s21_ceil(-3.57), EPS);
  ck_assert_ldouble_eq_tol(ceil(3.57), s21_ceil(3.57), EPS);

  ck_assert_int_eq(ceil(S21_POS_INFINITY) == INFINITY,
                   s21_ceil(S21_POS_INFINITY) == INFINITY);
  ck_assert_int_eq(ceil(S21_NEG_INFINITY) == -INFINITY,
                   s21_ceil(S21_NEG_INFINITY) == -INFINITY);

  ck_assert_ldouble_nan(ceil(S21_POS_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_POS_NAN));
  ck_assert_ldouble_nan(ceil(S21_NEG_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NEG_NAN));
}
END_TEST

Suite* root_suite(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_math");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abs);
  tcase_add_test(tc_core, test_fabs);
  tcase_add_test(tc_core, test_atan);
  tcase_add_test(tc_core, test_asin);
  tcase_add_test(tc_core, test_acos);
  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_log);
  tcase_add_test(tc_core, test_exp);
  tcase_add_test(tc_core, test_sin);
  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_tan);
  tcase_add_test(tc_core, test_fmod);
  tcase_add_test(tc_core, test_pow);
  tcase_add_test(tc_core, test_floor);
  tcase_add_test(tc_core, test_ceil);
  suite_add_tcase(s, tc_core);

  return s;
}
int main(void) {
  int number_failed;
  Suite* s = root_suite();
  SRunner* runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
