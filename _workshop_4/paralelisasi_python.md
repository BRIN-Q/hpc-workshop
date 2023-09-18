---
layout: default
title: Paralelisasi di Python
nav_order: 2
last_modified_date: 2023-09-07
---
# Paralelisasi di Python

Sebagai **bahasa tingkat tinggi interpretatif**, Python tidak dapat melakukan paralelisasi secara langsung.

Hal ini disebabkan adanya ***Global Interpreter Lock* (GIL)** yang mengunci *interpreter* Python sehingga hanya satu baris kode di satu *thread* saja yang dijalankan.

Meskipun demikian, pada sesi workshop ini kita akan membahas beberapa cara untuk menggunakan banyak CPU secara bersamaan untuk melakukan parallelisasi di Python.

## `multiprocessing`

`multiprocessing` adalah *library* bawaan Python yang dapat digunakan untuk melakukan proses **paralelisasi berbasis *process***.

*Library* ini bekerja dengan cara **membuat beberapa proses yang berjalan secara bersamaan namun terpisah**. Setiap proses memiliki **akses memori yang terpisah** dan membutuhkan interaksi eksplisit untuk berkomunikasi antar proses.

Pada workshop kali ini, kita akan membahas penggunaan `multiprocessing` untuk melakukan parallelisasi sederhana di mana **tidak ada kebutuhan untuk komunikasi antar proses**.

Contoh penggunaan `multiprocessing` dalam kasus ini adalah untuk ***post-processing* data** skala besar dan **visualisasi untuk animasi**. Kedua contoh tersebut akan kita jelajahi pada [Latihan 4](/workshop_4/latihan_4.html).

### Metode untuk `Pool`

Pada workshop kali ini kita akan membahas penggunaan `multiprocessing` dengan objek `Pool`. `Pool` bekerja sebagai objek **manajemen sekelompok proses** terpisah yang terdefinisi dalam konteks yang sama.

Dalam konteks `Pool` yang asma, kita dapat mengirim fungsi untuk dijalankan secara paralel di masing-masing proses. Untuk mencegah *runaway process* saat terjadi `Error`, sebaiknya `Pool` didefinisikan dalam context manager `with`:

```python
import multiprocessing as mp

JUMLAH_PROSES = 4

with mp.Pool(processes=JUMLAH_PROSES) as pool:
    # do something
    pass
```

Ada beberapa metode untuk menbagikan fungsi dan argumen yang ingin dijalankan dalam suatu `Pool`. Berikut adalah rangkuman perbedaan antara metode-metode tersebut:

| Metode | Jumlah Argumen | Jumlah Komponen Argumen | Pembagian Kerja |
| :-: | :-: | :-: | :- |
| `apply` | 1 | 1 | 1 argumen per proses |
| `map` | banyak | 1 | 1 argumen per proses, pembagian argumen di awal |
| `imap` | banyak | 1 | 1 argumen per proses, pembagian argumen secara bertahap |
| `starmap` | banyak | banyak | 1 argumen per proses, pembagian argumen di awal |

### Metode *async*

Masing-masing metode di atas memiliki versi ***asynchronous* (*async*)** dalam bentuk `[metode]_async`.

Metode dalam bentuk *async* akan berjalan di belakang layar dan memperbolehkan proses utama untuk menjalankan perintah selanjutnya. Metode *async* ini akan memanggil fungsi *callback* yang akan diberikan pada saat proses selesai.

Hasil fungsi dapat diperoleh dengan memanggil metode `wait()` dari hasil objek metode *async* atau menggunakan fungsi `Pool.close()` diikuti dengan `Pool.join()` untuk menutup `Pool` dan menunggu semua proses selesai.

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
