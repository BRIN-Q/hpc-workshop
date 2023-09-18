---
layout: default
title: Paralelisasi di Python
last_modified_date: 2023-09-07
---
# Paralelisasi di Python

Sebagai bahasa tingkat tinggi interpretatif, Python pada umumnya tidak dapat melakukan paralelisasi secara langsung. Hal ini disebabkan adanya *Global Interpreter Lock* (GIL) yang mengunci *interpreter* Python sehingga hanya satu baris kode di satu *thread* saja yang dijalankan. Meskipun demikian, ada beberapa cara untuk menggunakan beberapa CPU secara bersamaan untuk melakukan parallelisasi di Python.

## `multiprocessing`

`multiprocessing` adalah *library* bawaan Python yang dapat digunakan untuk melakukan paralelisasi. *Library* ini bekerja dengan cara membuat beberapa proses yang berjalan secara bersamaan namun terpisah. Setiap proses memiliki akses memori yang terpisah yang membutuhkan interaksi eksplisit untuk berkomunikasi antar proses. Pada workshop kali ini, kita akan membahas penggunaan `multiprocessing` untuk melakukan parallelisasi sederhana di mana **tidak** ada kebutuhan untuk berkomunikasi antar proses. Contoh aplikasi `multiprocessing` dengan cara ini adalah untuk melakukan *post-processing* data skala besar dan visualisasi untuk animasi.

Salah satu cara penggunaan `multiprocessing` adalah dengan memulai sekelompok proses terpisah dalam bentuk `Pool`. Kita kemudian dapat mengirim fungsi yang akan dijalankan secara paralel ke masing-masing proses dalam `Pool` dengan beberapa metode seperti `apply` dan `map`.

### Metode untuk `Pool`

Metode-metode ini menerima suatu fungsi dan argumen dari fungsi tersebut, berikut adalah rangkuman perbedaan antara metode-metode tersebut:

| Metode | Jumlah Argumen | Jumlah Komponen Argumen | Pembagian Kerja |
| :-: | :-: | :-: | :- |
| `apply` | 1 | 1 | 1 argumen per proses |
| `map` | banyak | 1 | 1 argumen per proses, pembagian argumen di awal |
| `imap` | banyak | 1 | 1 argumen per proses, pembagian argumen secara bertahap |
| `starmap` | banyak | banyak | 1 argumen per proses, pembagian argumen di awal |

Masing-masing metode di atas memiliki versi *asynchronous* (*async*) dalam bentuk `[metode]_async`. Metode dalam bentuk *async* akan berjalan di belakang yang menyebabkan proses utama dapat berjalan ke perintah selanjutnya. Metode *async* ini bergantung pada fungsi *callback* yang akan dijalankan saat proses selesai. Hasil fungsi dapat diperoleh dengan memanggil metode `wait()` dari hasil pemanggilan metode *async* atau menggunakan fungsi `Pool.close()` diikuti dengan `Pool.join()` untuk menutup `Pool` dan menunggu semua proses selesai.

### Contoh penggunaan

Berikut adalah contoh penggunaan `multiprocessing` untuk melakukan paralelisasi sederhana:

```python
import multiprocessing as mp
import numpy as np
from time import sleep

def f(x):
    return x*x

def g(x):
    sleep(1)
    return x*x
    
def h(x, y):
    return x*y

def cback(result):
    print(f"**async**: {result}")

if __name__ == '__main__':
    with mp.Pool(processes=4) as pool:
        # apply
        print(f"apply    : {pool.apply(f, (7,))}")

        # map
        print(f"map      : {pool.map(f, range(10))}")

        # map_async
        print(f"map_async: {pool.map_async(g, range(10), callback=cback)}")

        # starmap
        print(f"starmap  : {pool.starmap(h, [(1, 2), (3, 4)])}")

        pool.close()
        pool.join()
```

## Cara lain

Beberapa *library* lain yang dapat digunakan untuk melakukan paralelisasi di Python adalah:

* [mpi4py](https://mpi4py.readthedocs.io/en/stable/)
* [Dask](https://dask.org/)

Selain itu, kita juga sudah dapat menggunakan paralelisasi implisit dalam fungsi di beberapa *library* seperti:

* [NumPy](https://numpy.org/)
* [Numba](https://numba.pydata.org/)
* [PyTorch](https://pytorch.org/)
* [TensorFlow](https://www.tensorflow.org/)
