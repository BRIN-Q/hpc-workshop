---
layout: default
title: Solusi Latihan 0
parent: Latihan 0
last_modified_date: 2023-09-11
---
# Solusi Latihan 0

## *Preprocessor*

{: .pertanyaan }
> Lakuikan proses *preprocessing* terhadap program `fungsi_persiapan.cpp` dan `persiapan.cpp`. Lihat hasil file `*.i` yang dihasilkan.
>
> * Apa yang terjadi pada direktif `#include "persiapan.h"`?
>
>     {: .jawaban }
>
> > Direktif akan berganti menjadi isi dari file `persiapan.h`.
>
> * Apa yang terjadi pada direktif `#define`?
>
>     {: .jawaban }
>
> > Direktif akan hilang dan semua nilai `SATU` yang ada di kode yang menggunakan `persiapan.h` akan berubah menjadi `1.0`.

{: .pertanyaan }
> Lakukan kompilasi dengan opsi `-D PIBULAT`, apa yang terjadi pada direktif `#ifdef ... #endif`?
>
> {: .jawaban }
> > Direktif `#define PI 3` akan berlaku yang akan mengubah nilai `PI` menjadi `3`.

## *Compiler*

{: .pertanyaan }
> Lakukan proses *compilation* terhadap program `fungsi_persiapan.cpp` dan `persiapan.cpp`.
>
> Apa isi dari file `*.s` yang dihasilkan?
>
> {: .jawaban }
> > `*.s` akan berisi instruksi dalam bahasa *assembly* yang secara umum berbentuk `[command] [register 1] ([register 2])`.

## *Assembler*

{: .pertanyaan }
> Ubah `fungsi_persiapan.cpp` dan `persiapan.cpp` menjadi *object file*.
>
> Mengapa kita cenderung mengubah masing-masing *source code* menjadi *object file* terlebih dahulu?
>
> {: .jawaban }
> > Hal ini memudahkan kita dalam melakukan kompilasi parsial. Misalnya apabila kita ingin mengubah file `fungsi_persiapan.cpp` kita tidak perlu lagi melakukan kompilasi terhadap file `persiapan.cpp`. Kita akan menggunakan metode ini secara sistematis saat kita membahas mengenai [Makefile](/workshop_3/makefile.html).

## *Linker*

{: .pertanyaan }
> Lakukan proses *linking* terhadap *object file* yang dihasilkan dan beri nama program yang dihasilkan `persiapan`.
>
> Apa hasil keluaran dari `persiapan 0.5`?
>
> {: .jawaban }
> > `arcsin(0.5) = 0.523645`
