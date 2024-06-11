#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (s21_isinf(x))
    result = S21_NEG_NAN;
  else if (s21_isnan(x))
    result = x;
  else {
    int sign = (-1);
    x = s21_fmod(x, S21_PI * 2);
    if (x > (S21_PI / 2.0) && x <= S21_PI)
      x = (S21_PI - x) * (sign = 1);
    else if (x > S21_PI && x <= ((S21_PI * 3.0) / 2.0))
      x -= S21_PI;
    else if (x > ((S21_PI * 3.0) / 2.0) && x <= (S21_PI * 2.0))
      x = (2 * S21_PI) - x;
    else
      sign = 1;
    result = x;
    long double valueTailor = x;
    for (int i = 1; s21_fabs(valueTailor / x) > 1e-100; i += 1)
      result += (valueTailor = ((-valueTailor) * s21_pow(x, 2)) /
                               ((2.0 * i + 1) * (2.0 * i)));
    result *= sign;
  }
  return result;
}
