---
layout: default
title: Latihan 0
has_children: true
has_toc: false
nav_order: 2
last_modified_date: 2023-09-11
---
# Latihan 0

Pada latihan kali ini kita akan mempelajari proses kompilasi sederhana untuk program yang menghitung nilai `arcsin(x)` secara cepat. Dengan menggunakan pendekatan polinomial Lagrange, nilai fungsi `arcsin(x)` dapat disederhanakan menjadi polinomial orde 4.

File untuk latihan dapat dilihat di *repository* [Latihan 0](https://github.com/brin-hpc-workshop/latihan-0).

## *Preprocessor*

{: .pertanyaan }
> Lakuikan proses *preprocessing* terhadap program `fungsi_persiapan.cpp` dan `persiapan.cpp`. Lihat hasil file `*.i` yang dihasilkan.
>
> * Apa yang terjadi pada direktif `#include "persiapan.h`?
> * Apa yang terjadi pada direktif `#define SATU`?

{: .pertanyaan }
> Lakukan kompilasi dengan opsi `-D PIBULAT`, apa yang terjadi pada direktif `#ifdef ... #endif`?

## *Compiler*

{: .pertanyaan }
> Lakukan proses *compilation* terhadap program `fungsi_persiapan.cpp` dan `persiapan.cpp`.
>
> Apa isi dari file `*.s` yang dihasilkan?

## *Assembler*

{: .pertanyaan }
> Ubah `fungsi_persiapan.cpp` dan `persiapan.cpp` menjadi *object file*.
>
> Mengapa kita cenderung mengubah masing-masing *source code* menjadi *object file* terlebih dahulu?

## *Linker*

{: .pertanyaan }
> Lakukan proses *linking* terhadap *object file* yang dihasilkan dan beri nama program yang dihasilkan `persiapan`.
>
> Apa hasil keluaran dari `persiapan 0.5`?
