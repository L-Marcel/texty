#include "../core.h"

int32_t txy_pow_int(int32_t base, int32_t exp) {
  int32_t result = 1;
  int32_t current_exp = exp;
loop_start:
  if (current_exp <= 0) goto loop_end;
  result = result * base;
  current_exp = current_exp - 1;
  goto loop_start;
loop_end:
  return result;
};

int64_t txy_pow_long(int64_t base, int64_t exp) {
  int64_t result = 1;
  int64_t current_exp = exp;
loop_start:
  if (current_exp <= 0) goto loop_end;
  result = result * base;
  current_exp = current_exp - 1;
  goto loop_start;
loop_end:
  return result;
};

double txy_exp_double(double x) {
  double sum = 1.0;
  double term = 1.0;
  int32_t i = 1;
loop_start:
  if (i > 30) goto loop_end;
  term = term * x / i;
  sum = sum + term;
  i = i + 1;
  goto loop_start;
loop_end:
  return sum;
};

double txy_ln_double(double x) {
  if (x <= 0.0) return 0.0;
  double y = (x - 1.0) / (x + 1.0);
  double y_squared = y * y;
  double sum = 0.0;
  double term = y;
  int32_t n = 0;
loop_start:
  if (n > 30) goto loop_end;
  sum = sum + term / (2 * n + 1);
  term = term * y_squared;
  n = n + 1;
  goto loop_start;
loop_end:
  return 2.0 * sum;
};

double txy_pow_double(double base, double exp) {
  if (base == 0.0) return 0.0;
  if (exp == 0.0) return 1.0;

  if (exp == (int64_t)exp) {
    double result = 1.0;
    int64_t current_exp = (int64_t)exp;
    if (current_exp < 0) {
      base = 1.0 / base;
      current_exp = -current_exp;
    }
loop_start:
    if (current_exp <= 0) goto loop_end;
    result = result * base;
    current_exp = current_exp - 1;
    goto loop_start;
loop_end:
    return result;
  }

  return txy_exp_double(exp * txy_ln_double(base));
};

float txy_pow_float(float base, float exp) {
  return (float)txy_pow_double((double)base, (double)exp);
};
