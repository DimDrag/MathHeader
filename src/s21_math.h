#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_LN_2 0.6931471805599453
#define S21_E 2.718281828459045
#define S21_PI 3.14159265358979323846
#define S21_POS_INFINITY +1.0 / 0.0
#define S21_NEG_INFINITY -1.0 / 0.0
#define S21_NEG_NAN 0.0 / 0.0
#define S21_POS_NAN get_pos_nan()

double get_pos_nan();
int s21_isnan(double x);
int s21_isinf(double x);
int s21_signbit(double x);
long double s21_fabsl(long double x);
long double s21_factorial(unsigned long long x);
long double s21_powi(double base, long long int exp);

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_sqrt(double x);
long double s21_log(double x);
long double s21_exp(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
long double s21_fmod(double x, double y);
long double s21_floor(double x);
long double s21_ceil(double x);

#endif  // S21_MATH_H
