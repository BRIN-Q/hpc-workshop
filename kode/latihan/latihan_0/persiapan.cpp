/*
 * @file    persiapan.cpp
 * @brief   Source code untuk persiapan workshop HPC BRIN
 */

#include "persiapan.h"

#include <iostream>

int main(int argc, char* argv[]) {
  // Ambil nilai dari command line
  if (argc != 2) {
    std::cout << "Cara pemakaian: " << argv[0] << " x" << std::endl;
    return 1;
  }
  float x = atof(argv[1]);

  std::cout << "arcsin(" << x << ") = " << asin_cepat(x) << std::endl;
  return 0;
}