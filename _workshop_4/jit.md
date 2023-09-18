---
layout: default
title: Just-in-Time (JIT) untuk Python
nav_order: 1
last_modified_date: 2023-09-07
---
# Just-in-time (JIT) Compiler untuk Python

**Python** sebagai bahasa pemrograman tingkat tinggi cenderung lebih **mudah digunakan** dalam proses penelitian.

Akan tetapi, dibandingkan dengan bahasa pemrograman terkompilasi seperti C/C++ dan Fortran, Python memiliki **kelemahan** dalam hal **kecepatan eksekusi** program.

![Perbandingan kecepatan bahasa pemrograman](../assets/images/prog_speed.png)

Pada sesi kali ini, kita akan membahas beberapa cara untuk meningkatkan kecepatan eksekusi program Python dengan menggunakan ***Just-in-time* (JIT) compiler**.

## JIT Compiler

***JIT compiler*** adalah program yang akan melakukan proses **kompilasi pada saat** program dijalankan.

Bagi peserta yang belum familier dengan penggunaan bahasa terkompilasi dapat melihat [materi persiapan](/persiapan/persiapan_kompilasi.html).

Dalam workshop ini, kita akan menggunakan *library* [**Numba**](https://numba.pydata.org/) sebagai *JIT compiler*. Selain Numba, ada beberapa *library* lain yang dapat digunakan untuk melakukan JIT, misalnya [PyPy](https://www.pypy.org/).

## Numba

[**Numba**](https://numba.pydata.org/) adalah *library JIT compiler* yang dikembangkan oleh Anaconda.

Dibanding *JIT compiler* lain seperti Cython, Numba lebih mudah digunakan karena **tidak memerlukan *type annotation*** secara eksplisit. Numba melakukan **vektorisasi dan optimasi kode secara otomatis**, [setara dengan `-O3` pada GCC](https://stackoverflow.com/questions/36526708/comparing-python-numpy-numba-and-c-for-matrix-multiplication). Selain untuk kompilasi JIT, Numba juga dapat digunakan untuk **paralelisasi kode Python** yang akan kita pelajari lebih lanjut pada sesi selanjutnya.

Penggunaan Numba untuk kompilasi JIT dilakukan dengan **menambahkan dekorator fungsi** `@jit(nopython=True)` atau `@njit` sebelum definisi fungsi.

Contoh penggunaan Numba untuk menghitung nilai integral sederhana dapat dilihat pada kode berikut.

```python
import numpy as np
from numba import jit

@jit(nopython=True)
def integral(f, a, b, N):
    x = np.linspace(a, b, N)
    dx = x[1] - x[0]
    return np.sum(f(x)) * dx
```

### Parameter Dekorator Numba

#### `nopython=True`

Opsi `nopython=True` digunakan untuk memastikan bahwa Numba akan mengubah kode Python menjadi *machine code*.

Jika opsi ini tidak digunakan, Numba akan mengubah kode Python dalam [*object mode*](https://numba.pydata.org/numba-doc/latest/glossary.html#term-object-mode). Kode dalam *object mode* akan menggunakan Python C API yang seringkali **tidak menghasilkan peningkatan kecepatan yang signifikan**.

Untuk menggunakan opsi ini, kode Python harus ditulis dalam bentuk sederhana tanpa penggunaan objek `class` Python yang lazim digunakan dalam **Object Oriented Programming (OOP)**.

{: .catatan }
> Versi terbaru Numba akan menambahkan dukungan untuk [`@jitclass`](https://numba.pydata.org/numba-doc/dev/user/jitclass.html).

Untuk proses kompilasi, Numba dapat menggunakan bentuk dasar seperti `int` atau `float` dan juga **array NumPy**. Numba juga dirancang untuk dapat menggunakan fungsi-fungsi dari *library* NumPy secara langsung. Akan tetapi, Numba **tidak mendukung** penggunaan *library* eksternal lainnya seperti `scipy`.

Untuk menjalankan fungsi terkompilasi, **semua input** dari fungsi juga harus dapat dipahami oleh Numba. Misalnya dalam contoh di atas, fungsi `integral` yang telah dikompilasi oleh Numba hanya dapat menerima fungsi `f` yang dikompilasi dengan Numba.

{: .catatan }
> `@njit` adalah *alias* dari `@jit(nopython=True)`.

#### `cache=True`

Pada waktu fungsi **pertama kali dipanggil**, Numba akan melakukan kompilasi instan dan menyimpan hasilnya ke dalam *cache* di memori.

Hal ini menyebabkan **penambahan *runtime*** untuk kali pertama penggunaan fungsi.

Opsi `cache=True` pada dekorator Numba akan menyimpan hasil kompilasi fungsi ke dalam file yang dapat digunakan kembali pada saat program dijalankan di waktu yang berbeda.

## Penggunaan JIT di Fisika

JIT dalam penelitian Fisika biasanya digunakan dalam proses ***post-processing* data berskala besar** yang membutuhkan waktu eksekusi yang lama.

Selain itu JIT juga dapat digunakan untuk melakukan **simulasi numerik skala kecil** sampai menengah. Bergantung pada skala simulasi yang diinginkan, penggunaan kode Python dengan JIT dapat menghemat waktu untuk menulis kode dibandingkan dengan penggunaan C++ atau Fortran.

Kita akan membahas secara lebih lanjut penggunaan JIT untuk simulasi sederhana Fisika pada [Latihan 4](/workshop_4/latihan_4.html).
