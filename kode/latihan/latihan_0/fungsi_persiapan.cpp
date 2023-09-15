#include "persiapan.h"

/*
 * @brief   Fungsi asin cepat berdasarkan Handbook of Mathematical Functions
 * @param   x   Input
 * @return  Hasil asin(x)
 */

float asin_cepat(float x) {
  float negate = float(x < 0);
  x = std::abs(x);
  float ret = -0.0187293;
  ret *= x;
  ret += 0.0742610;
  ret *= x;
  ret -= 0.2121144;
  ret *= x;
  ret += 1.5707288;
  ret = PI * 0.5 - std::sqrt(SATU - x) * ret;
  return ret - 2 * negate * ret;
}
