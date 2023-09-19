---
layout: default
title: Vektorisasi
nav_order: 2
last_modified_date: 2023-09-15
---
# Vektorisasi

**Vektorisasi** adalah proses mengubah instruksi operasi secara skalar menjadi vektor. Prosesor modern memiliki set intruksi yang dapat melakukan operasi yang sama untuk beberapa data sekaligus dalam bentuk **register vektor**. Dengan menggunakan vektorisasi, kita dapat mengurangi **jumlah instruksi** dan ***clock cycle*** yang dibutuhkan dalam menjalankan program.

Pada sesi kali ini, kita akan membahas penggunaan direktif `simd` dari OpenMP untuk melakukan vektorisasi dan membahas penambahan performa yang didapatkan.

## SIMD

**SIMD** atau **Single Instruction, Multiple Data** adalah sistem arsitektur komputer yang memungkinkan **satu instruksi** untuk melakukan **operasi pada beberapa data sekaligus**. Dari tahun ke tahun, SIMD terus berkembang dan mengalami perubahan.

Mengingat vektorisasi terus berkembang, pastikan **panjang vektor** yang dapat digunakan di komputer Anda dengan menjalankan perintah berikut di terminal:

```bash
lscpu | grep "SIMD"
```

## Vektorisasi di OpenMP

Sejak OpenMP 4.0, kita dapat menggunakan direktif `simd` untuk melakukan vektorisasi. Berikut adalah contoh penggunaan `simd`:

```c
#pragma omp simd
for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
}
```

{: .catatan }
> Kita dapat menggunakan `#pragma omp simd` untuk C/C++ dan `!$omp simd` untuk Fortran.

{: .peringatan }
> Kita tidak dapat menggunakan `simd` untuk semua jenis operasi. *Compiler* akan memberikan peringatan jika operasi yang digunakan tidak dapat divektorisasi.

{: .catatan }
> Fungsi dapat dikompilasi agar menjadi tervektorisasi dengan direktif `#pragma omp declare simd`.

### Contoh Kasus

Berikut adalah contoh kasus yang akan kita gunakan untuk membandingkan performa vektorisasi:

```c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double *a, *b, *c;
    double t1, t2;

    a = (double *) malloc(N * sizeof(double));
    b = (double *) malloc(N * sizeof(double));
    c = (double *) malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        a[i] = (double) i;
        b[i] = (double) i;
    }

    t1 = omp_get_wtime();
    #pragma omp simd
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
    t2 = omp_get_wtime();
    printf("Time: %f\n", t2 - t1);

    free(a);
    free(b);
    free(c);
    return 0;
}
```

{: .catatan }
> Kita dapat menggunakan `omp_get_wtime()` untuk menghitung waktu eksekusi program.
