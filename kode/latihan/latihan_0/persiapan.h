/*
 * @file    persiapan.h
 * @brief   Header untuk persiapan workshop HPC BRIN
 */

#pragma once

#define SATU 1.0

#ifdef PIBULAT
#define PI 4
#else
#define PI 3.14159265358979323846
#endif

#include <cmath>

// Handbook of Mathematical Functions
// M. Abramowitz and I.A. Stegun, Ed.

float asin_cepat(float x);