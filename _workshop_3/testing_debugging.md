---
layout: default
title: Testing dan Debugging
last_modified_date: 2023-09-15
---
# Testing dan Debugging

## Testing

Proses *testing* berguna untuk memastikan bahwa program yang kita buat berjalan sesuai dengan yang kita harapkan. Biasanya *testing* dilakukan dengan membuat beberapa kasus sederhana yang dapat kita periksa hasilnya. Ada beberapa konsep *testing* yang dapat berguna untuk dipahami.

### Unit Testing

**Unit Testing** adalah proses *testing* yang dilakukan pada komponen kecil (*unit*) penyusun program.

### Integration Testing

### Continuous Integration/Continuous Delivery

## Debugging

Pada saat penulisan kode, tidak dapat dipungkiri bahwa kita akan membuat kesalahan atau ***bug***. Sebagian besar waktu yang kita habiskan untuk menulis kode adalah untuk ***debugging***. Pada workshop kali ini, kita akan membahas beberapa teknik *debugging* yang dapat digunakan untuk mempercepat proses penulisan kode.

### Print Statement

Salah satu cara paling sederhana dalam *debugging* adalah dengan menggunakan *print statement* untuk variabel yang ingin kita periksa.

### GDB

[GDB](https://www.gnu.org/software/gdb/) adalah *debugger* yang dapat digunakan untuk melakukan *debugging* secara interaktif. GDB dapat digunakan untuk berbagai bahasa pemrograman seperti C, C++, dan Fortran. GDB dapat digunakan untuk melakukan *debugging* pada kode yang telah dikompilasi dengan *flag* `-g`.

Penggunaan GDB memungkinkan kita untuk menjalankan program secara bertahap dan memeriksa nilai dari variabel pada tahapan tertentu.

### Valgrind

[Vaglgrind](https://valgrind.org/) adalah program yang dapat digunakan melakukan diagnosa memori pada program. Kegunaan utama Valgrind adalah untuk memeriksa penggunaan *memory* untuk C, C++, dan Fortran. Sama seperti GDB, program harus dikompilasi dengan *flag* `-g`. Contoh kasus yang mudah dideteksi oleh Valgrind adalah akses variabel di luar batas array (*out of bound*), kebocoran memori (*memory leak*), dan penggunaan variabel yang belum diinisialisasi.

### Linaro DDT

**Linaro DDT** (sebelumnya **Allinea DDT**/**Arm Forge**) adalah *Distributed Debugging Tool* yang banyak digunakan untuk melakukan *debugging* pada program parallel. Salah satu tantangan dalam program HPC berskala besar adalah banyaknya proses yang berjalan secara bersamaan dengan nama variabel yang sama. Keunggulan DDT adalah dimungkinkannya menambahkan *breakpoint* yang spesifik pada proses tertentu.
