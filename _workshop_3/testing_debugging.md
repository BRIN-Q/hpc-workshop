---
layout: default
title: Testing dan Debugging
nav_order: 3
last_modified_date: 2023-09-15
---
# Testing dan Debugging

## Testing

Proses *testing* berguna untuk memastikan bahwa program yang kita buat berjalan sesuai dengan yang kita harapkan. Biasanya *testing* dilakukan dengan membuat beberapa kasus sederhana yang dapat kita periksa hasilnya. Ada beberapa konsep *testing* yang dapat berguna untuk dipahami.

### Unit Testing

**Unit Testing** adalah proses tes yang dilakukan pada komponen kecil (*unit*) penyusun program.

Kita akan membahas penggunaan *unit testing* secara lebih lanjut pada [Latihan 3](/workshop_3/latihan_3.html).

### Integration Testing

Berbeda dengan *unit test*, **Integration Testing** menguji interaksi dari beberapa bagian penyusun program atau kinerja keseluruhan program.

Proses ini sebaiknya dilakukan seusai *unit test* dan akan kita pelajari lebih lanjut pada [Latihan 3](/workshop_3/latihan_3.html).

### Regression Testing

**Regression Testing** adalah proses *testing* yang dilakukan untuk memastikan bahwa perubahan kode tidak mempengaruhi hasil dari program.

Dalam penelitian, hasil dari *regression testing* dapat digunakan dengan cara membandingkan hasil untuk **model atau kasus sederhana** yang mudah diverifikasi.

### Continuous Integration/Continuous Delivery

**Continuous Integration** adalah proses *testing* yang dilakukan secara otomatis setiap perubahan kode.

Proses ini dapat dilakukan dengan menggunakan *tools* seperti [**Travis CI**](https://travis-ci.org/) atau [**Jenkins**](https://jenkins.io/). Selain itu, beberapa penyedia layanan *cloud* untuk *repo* seperti GitHub dan GitLab juga menyediakan layanan *continuous integration*.

**Continuous Delivery** adalah proses penyebaran pemuktahiran (*update*) secara otomatis setiap perubahan kode. Umumnnya proses ini dilakukan setelah *continuous integration*.

## Debugging

Pada saat penulisan kode, tidak dapat dipungkiri bahwa kita akan membuat kesalahan atau ***bug***. Sebagian besar waktu yang kita habiskan untuk menulis kode adalah untuk ***debugging***. Pada workshop kali ini, kita akan membahas beberapa teknik *debugging* yang dapat digunakan untuk mempercepat proses penulisan kode.

### Print Statement

Salah satu cara paling sederhana dalam *debugging* adalah dengan menggunakan *print statement* untuk variabel yang ingin kita periksa.

### GDB

[**GNU Debugger** atau **GDB**](https://www.gnu.org/software/gdb/) adalah *debugger* yang dapat digunakan untuk melakukan *debugging* secara interaktif. GDB dapat digunakan untuk berbagai bahasa pemrograman seperti C, C++, dan Fortran. GDB dapat digunakan untuk melakukan *debugging* pada kode yang telah dikompilasi dengan *flag* `-g`.

Penggunaan GDB memungkinkan kita untuk menjalankan program secara bertahap dan memeriksa nilai dari variabel pada tahapan tertentu.

### Valgrind

[**Vaglgrind**](https://valgrind.org/) adalah program yang dapat digunakan melakukan diagnosa memori pada program. Sama seperti GDB, program harus dikompilasi dengan *flag* `-g`.

Kegunaan utama Valgrind adalah untuk memeriksa **penggunaan memori** untuk C, C++, dan Fortran. Contoh kasus yang mudah dideteksi oleh Valgrind adalah akses variabel di luar batas array (*out of bound*), kebocoran memori (*memory leak*), dan penggunaan variabel yang belum diinisialisasi.

### Linaro DDT

[**Linaro DDT**](https://www.linaroforge.com/linaroDdt) (sebelumnya **Allinea DDT**/**Arm Forge**) adalah *Distributed Debugging Tool* yang umum digunakan untuk melakukan *debugging* pada program parallel HPC.

Salah satu tantangan dalam program HPC berskala besar adalah banyaknya proses yang berjalan secara bersamaan dengan nama variabel yang sama. Keunggulan DDT adalah dimungkinkannya menambahkan *breakpoint* yang spesifik pada proses tertentu.
