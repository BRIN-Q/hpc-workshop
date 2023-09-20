---
layout: default
title: OpenMPI
nav_order: 1
last_modified_date: 2023-09-15
---
# OpenMPI

**OpenMPI** adalah serangkaian *Application Programming Interface* (API) yang dapat digunakan untuk melakukan paralelisasi untuk C, C++, dan Fortran. Penggunaan OpenMPI akan sedikit lebih sulit dibanding [OpenMP](https://www.openmp.org/) dikarenakan sistem **paradigma memori terdistribusi (*distributed memory*)** yang digunakan oleh OpenMPI.

Karena memori yang digunakan oleh program OpenMPI dikelola oleh masing-masing proses yang berjalan secara paralel, program dapat dijalankan pada **beberapa unit komputer (*node*) sekaligus**. Hal ini memungkinkan eksekusi program yang jauh lebih besar dibanding OpenMP.

Kelemahan dari OpenMP adalah kita harus mendesain **komunikasi antar proses** secara eksplisit. Hal ini dapat dilakukan dengan menggunakan **panggilan fungsi** yang disediakan oleh OpenMPI.

## Dasar OpenMPI

Untuk memulai penggunaan OpenMPI, kita dapat melakukan kompilasi dengan wrapper `mpicc` atau `mpifort`:

```bash
mpicc program.c -o program
mpiifort program.f90 -o program
```

memanggil program yang terkompilasi dengan:

```bash
mpirun -np N ./program
```

Nilai `N` adalah jumlah proses yang akan dijalankan. Jika `N` tidak didefinisikan, maka OpenMPI akan menjalankan program dengan jumlah proses yang sama dengan jumlah *core* yang tersedia.

Untuk memulai penggunaan OpenMPI, kita harus memanggil fungsi:

```c++
MPI_Init(&argc, &argv);
```

Fungsi ini akan menginisialisasi OpenMPI dan mengalokasikan sumber daya yang dibutuhkan. Variabel `MPI_COMM_WORLD` akan terdefinisi setelah fungsi ini yang berisi referensi untuk komunikator proses yang berjalan.

Setelah selesai, kita dapat menggunakan:

```c++
MPI_Finalize();
```

Untuk mengetahui total jumlah proses yang dijalankan dan ***rank*** dari proses yang berjalan kita menggunakan:

```c++
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
```

{: .catatan }
Perlu diingat bahwa **semua** variabel akan bersifat *private*.

## Komunikasi Antar Proses

Komunikasi antar proses dapat dilakukan dengan menggunakan fungsi:

```c++
MPI_Send(&data, count, MPI_TYPE, dest, tag, MPI_COMM_WORLD);
MPI_Recv(&data, count, MPI_TYPE, source, tag, MPI_COMM_WORLD, &status);
MPI_Sendrecv(&send_data, send_count, MPI_TYPE, dest, send_tag, &recv_data, recv_count, MPI_TYPE, source, recv_tag, MPI_COMM_WORLD, &status);
```

{: .catatan }
> `MPI_TYPE` adalah tipe data yang akan dikirim. Contoh: `MPI_INT`, `MPI_DOUBLE`, `MPI_FLOAT`, dan lain-lain.
>
> `count` adalah jumlah data yang akan dikirim.
>
> `dest` adalah *rank* dari proses tujuan.
>
> `source` adalah *rank* dari proses sumber.
>
> `tag` adalah *tag* yang akan digunakan untuk mengidentifikasi pesan.
>
> `status` adalah status dari pesan yang diterima.

Selain kedua fungsi ini, juga terdapat fungsi yang **tidak memblokir** proses yang sedang berjalan:

```c++
MPI_Isend(&data, count, MPI_TYPE, dest, tag, MPI_COMM_WORLD, &request);
MPI_Irecv(&data, count, MPI_TYPE, source, tag, MPI_COMM_WORLD, &request);
```

{: .catatan }
> `request` adalah variabel yang akan menyimpan status dari fungsi yang dipanggil.

Untuk menunggu proses yang sedang berjalan, kita dapat menggunakan:

```c++
MPI_Wait(&request, &status);
```

## Komunikasi Masal

Ada beberapa komunikasi masal yang dapat dilakukan:

| Fungsi | Sumber | Target | Kegunaan |
| :- | :-: | :-: | :- |
| `MPI_Bcast` | 1 | banyak | Membagikan satu variabel ke banyak proses. |
| `MPI_Scatter` | 1 | banyak | Membagikan bagian dari variabel ke masing-masing proses. |
| `MPI_Gather` | banyak | 1 | Mengumpulkan bagian variabel dari masing-masing proses. |
| `MPI_Reduce` | banyak | 1 | Mengumpulkan satu variabel dari banyak proses ke satu proses dengan reduksi tertentu. |
| `MPI_Allreduce` | banyak | banyak | Melakukan `MPI_Reduce` lalu `MPI_Bcast`. |

## `MPI_Barrier`

`MPI_Barrier(comm)` adalah fungsi yang dapat kita gunakan untuk melakukan sinkronisasi semua proses. Penggunaan fungsi ini secara berlebih mengurangi performa paralelisasi.
