---
layout: default
title: OpenMP
nav_order: 1
last_modified_date: 2023-09-15
---
# OpenMP

[**OpenMP**](https://www.openmp.org/) adalah serangkaian *Application Programming Interface* (API) yang dapat digunakan untuk melakukan paralelisasi untuk C, C++, dan Fortran. Penggunaan OpenMP akan sedikit lebih mudah dibanding [OpenMPI]HIMA dikarenakan sistem paradigma memori bersama (*shared memory*) yang digunakan oleh OpenMP. Hal ini berarti bahwa manajemen akses memori dilakukan secara abstrak oleh OpenMP tanpa perlu adanya komunikasi eksplisit seperti OpenMPI. Hal ini juga menjadi kelemahan dari OpenMP karena abstraksi akses memori hanya dapat diterapkan pada satu unit komputer (*node*) saja.

OpenMP sendiri menggunakan sistem ***multi-threading*** untuk melakukan paralelisasi. Sejak pertengahan tahun 1990-an, banyak perusahaan sudah menerapkan sistem *multi-threading* yang berbeda pada prosesor mereka. Standar OpenMP 1.0 untuk Fortran diadopsi sejak tahun 1997. Sejak saat itu, OpenMP terus berkembang dan menambahkan beberapa fitur baru seperti ***Single Instruction Multiple Data*** (SIMD) yang akan kita pelajari pada sesi Vektorisasi dan direktif untuk GPU.

![Performa Komputer](/assets/images/50-years-processor-trend.png)

*Diambil dari [Microprocessor Trend Data](https://github.com/karlrupp/microprocessor-trend-data).*

## Konsep dalam OpenMP

Ada beberapa terminologi yang sering digunakan untuk OpenMP:

* **Master Thread**: Thread yang pertama kali dijalankan oleh program.
* **Fork**: Proses pembuatan *thread* baru (*child*).
* **Join**: Proses penggabungan *child* ke *master thread*
* **Sequential Region**: Bagian dari kode yang akan dieksekusi secara berurutan (*serial*). Biasanya digunakan untuk inisialisasi variabel, alokasi memori, dan lain-lain.
* **Parallel Region**: Bagian dari kode yang akan dieksekusi secara paralel. Biasanya digunakan untuk melakukan komputasi.
* **Private Variable**: Variabel yang hanya dapat diakses oleh satu *thread* atau *proses* saja.
* **Shared Variable**: Variabel yang dapat diakses oleh semua *thread* atau *proses*.

## Penggunaan OpenMP

OpenMP dapat digunakan dengan mudah karena hanya mengandalkan *preprocessor directive* seperti Numba yang sudah kita pelajari sebelumnya. Berikut adalah contoh *Hello World* untuk OpenMP di C/C++:

```c
HIMA
```

{: .catatan }
> Untuk penggunaan di Fortran yang tidak memiliki *preprocessor* seperti C/C++, kita dapat mengganti `#` sebagai penanda dengan `!$omp`, `c$omp`, atau `*$omp`.
> Penggunaan tanda kurung `{...}` akan berganti menjadi kata kunci `end` seperti:
>
> ```fortran
> !$omp parallel [klausa tambahan]
>   ! kode yang akan dieksekusi secara paralel
> !$omp end parallel
> ```

{: .peringatan }
*Preprocessor directive* atau ekuivalennya di Fortran harus dimulai dari kolom pertama tanpa indentasi di setiap barisnya.

## Fungsi atau Metode di OpenMP

Ada beberapa fungsi yang biasa kita gunakan dalam OpenMP:

1. `omp_get_max_threads()`

    Memberikan jumlah *thread* maksimum yang dapat digunakan oleh OpenMP.

2. `omp_get_num_threads()`

    Memberikan jumlah *thread* yang sedang digunakan oleh OpenMP.

3. `omp_get_thread_num()`

    Memberikan nomor *thread* yang sedang digunakan oleh OpenMP.

{: .catatan }
OpenMP juga akan membaca *environment variable* `OMP_NUM_THREADS` yang akan mengatur jumlah *thread* yang akan digunakan. Jika *environment variable* tersebut tidak terdefinisi, maka OpenMP akan menggunakan jumlah *thread* maksimum yang dapat digunakan oleh OpenMP.

## Direktif OpenMP

Ada beberapa direktif yang biasa digunakan dalam OpenMP:

### Pembagian kerja

| Direktif | C/C++ | Fortran | Deskripsi |
| :-: | :- | :- | :- |
| `parallel` | `#pragma omp parallel [klausa tambahan]` | `!$omp parallel [klausa tambahan]` | Membuat region paralel. |
| `for` | `#pragma omp for [klausa tambahan]` | `!$omp do [klausa tambahan]` | Mendistribusikan loop ke masing-masing thread. |
| `single` | `#pragma omp single [klausa tambahan]` | `!$omp single [klausa tambahan]` | Membuat bagian kode dieksekusi oleh satu thread. |
| `sections` | `#pragma omp sections [klausa tambahan]` | `!$omp sections [klausa tambahan]` | Membagi bagian kode ke beberapa thread. |

### Sinkronisasi

| Direktif | C/C++ | Fortran | Deskripsi |
| :-: | :- | :- | :- |
| `barrier` | `#pragma omp barrier` | `!$omp barrier` | Menunggu semua thread selesai. |
| `critical` | `#pragma omp critical [klausa tambahan]` | `!$omp critical [klausa tambahan]` | Membuat bagian kode dieksekusi bergantian oleh masing-masing thread. |
| `atomic` | `#pragma omp atomic` | `!$omp atomic` | Memastikan eksekusi `=`, `++`, dan `--` yang merubah memori tidak tumpang tindih. |
| `master` | `#pragma omp master` | `!$omp master` | Membuat bagian kode dieksekusi oleh *master thread*. |

## Klausa Tambahan

Ada beberapa klausa tambahan yang biasa digunakan dalam OpenMP:

### Pengaturan

| Klausa | Deskripsi |
| :- | :- |
| `num_threads(n)` | Mendefinisikan jumlah thread yang akan digunakan. |
| `if(condition)` | Mendefinisikan kondisi apakah region paralel akan dieksekusi atau tidak. |
| `schedule(type, chunk)` | Mendefinisikan bagaimana loop akan didistribusikan ke masing-masing thread. Tipe yang dapat digunakan: `static`, `dynamic`, `guided`, atau `runtime`. |
| `nowait` | Mendefinisikan bahwa thread tidak perlu menunggu thread lainnya. |
| `ordered` | Mendefinisikan bahwa bagian kode yang dieksekusi oleh thread harus dieksekusi secara berurutan. |

### Pembagian data

| Klausa | Deskripsi |
| :- | :- |
| `private(list)` | Mendefinisikan variabel yang hanya dapat diakses oleh satu thread. |
| `shared(list)` | Mendefinisikan variabel yang dapat diakses oleh semua thread. |
| `reduction(operator:list)` | Mendefinisikan operasi reduksi yang akan dilakukan oleh semua thread. Operator yang dapat digunakan: `+`, `*`, `-`, `&`, `^`, `|`,`&&`, atau`||` |
| `firstprivate(list)` | Mendefinisikan variabel yang hanya dapat diakses oleh satu thread dan diinisialisasi dengan nilai dari variabel yang sama di luar region paralel. |
| `lastprivate(list)` | Mendefinisikan variabel yang hanya dapat diakses oleh satu thread dan pada akhir region paralel akan diinisialisasi dengan nilai dari thread yang berjalan terakhir. |
| `default(shared\|none)` | Mendefinisikan apakah variabel yang tidak didefinisikan secara eksplisit akan dianggap `shared` atau `private`. |
| `copyin(list)` | Mendefinisikan variabel yang hanya dapat diakses oleh satu thread dan diinisialisasi dengan nilai dari variabel yang sama di luar region paralel. |

## *Common Bugs*

### Variabel *shared* dan *private*

Hal yang sering terjadi adalah variabel yang kita kerjakan memiliki sifat pembagian data yang tidak tepat.

Contohnya dalam loop yang kita distribusikan, indeks loop sekunder haruslah bersifat *private*. Saat indeks tidak hidup sendiri di masing-masing thread.

### *Race Condition*

Hal ini terjadi apabila ada beberapa thread yang mengakses variabel yang sama secara bersamaan. Hal ini dapat diatasi dengan menggunakan klausa `critical` atau `atomic`.
