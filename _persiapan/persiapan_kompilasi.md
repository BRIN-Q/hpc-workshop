---
layout: default
title: Kompilasi Kode
has_toc: false
last_modified_date: 2023-09-11
---
# Kompilasi Kode

Pada workshop kali ini, kita akan menggunakan bahasa pemrograman tingkat tinggi, dalam bentuk **Python**, dan bahasa pemrograman terkompilasi, dalam bentuk **C++** dan **Fortran**. Bagi banyak peneliti, penggunaan bahasa tingkat tinggi terinterpretasi sudah cukup untuk kebutuhan penelitian mereka. Penggunaan bahasa pemrograman terkompilasi menjadi kebutuhan untuk simulasi numerik atau pemrosesan data skala besar.

## Kompilasi

Kompilasi adalah proses pengubahan program dari bentuk *source code* yang dapat dipahami manusia menjadi *machine code* yang dapt dicerna oleh komputer. Ada beberapa tahapan dalam proses kompilasi, yaitu:

1. *Preprocessor*

    Tahap ini memiliki peran untuk melakukan substitusi terhadap ***preprocessor directives*** atau makro yang diawali dengan tanda `#` seperti `#include` dan `#define`. Penggunaan makro ini memudahkan kita untuk menulis program yang lebih mudah dipahami.

    Kita dapat menambahkan opsi `-D [opsi]` atau `-D [opsi]=[nilai]` untuk menambahkan makro definis secara eksplisit pada waktu kompilasi.

    Tahapan ini biasanya tidak dilakukan secara eksplisit.

    * C++: `g++ -E program.cpp -o program.i`
    * Fortran: `gfortran -E program.f90 -o program.i`

    {: .catatan }
    > Direktif `#include` yang menggunakan *angled brackets* seperti `#include <iostream>` akan berusaha mencari file header di daftar include path sedangkan direktif yang menggunakan tanda kutip seperti `#include "persiapan.h"` akan mencari file header di direktori saat ini terlebih daulu sebelum mencari di direktori yang ada di include path.

    {: .catatan }
    > Fortran pada dasarnya tidak memiliki tahapan *preprocessing*. Akan tetapi, kebanyakan *compiler* Fortran dapat mencerna *preprocessor directives* sesuai dengan standar C/C++.
    >
    > Hal ini akan menjadi penting saat kita membahas mengenai [OpenMP](/workshop_7/openmp.html).

2. *Compiler*

    Tahap ini mengubah *source code* menjadi *assembly code*. Bahasa *assembly* sudah bisa dipahami langsung oleh komputer tetapi juga masih bisa dibaca oleh manusia.

    Tahapan ini biasanya juga tidak dilakukan secara eksplisit.

    * C++: `g++ -S program.cpp -o program.s`
    * Fortran: `gfortran -S program.f90 -o program.s`

3. *Assembler*

    Tahap ini mengubah *assembly code* menjadi *machine code* yang sudah tidak bisa dipahami oleh manusia. *Machine code* ini akan disimpan dalam bentuk *object file* yang memiliki ekstensi `.o` atau `.obj`.

    Tahapan ini biasanya dilakukan secara eksplisit untuk mempercepat proses kompilasi program berskala besar.

    * C++: `g++ -c program.cpp -o program.o`
    * Fortran: `gfortran -c program.f90 -o program.o`

4. *Linker*

    Pada tahap ini semua *object file* akan digabungkan menjadi satu program *executable* yang dapat dijalankan oleh komputer. Pada tahap ini pula, kita akan menghubungkan *library* yang dibutuhkan oleh program kita.

    * C++: `g++ file1.o file2.o ... -o program`
    * Fortran: `gfortran file1.o file2.o ... -o program`

## Optimasi Hasil Kompilasi

Pada waktu kompilasi, ada beberapa opsi yang dapat kita gunakan untuk membuat program kita berjalan lebih cepat. Opsi-opsi ini dapat digunakan pada tahap *compiler* dan *linker*. Contoh optimasi yang sering digunakan adalah `-O2`, `-O3`, dan `-Ofast`. Untuk lebih lanjut, silahkan mengacu pada [dokumentasi GCC](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html).
