---
layout: default
title: Kolaborasi Riset
last_modified_date: 2023-09-07
---
# Kolaborasi Riset dengan Git

## *Version Control* dalam Kolaborasi

Penggunaan *version control* menjadi penting dalam kolaborasi riset. Selama ini kita mungkin sudah melakukan hal tersebut tanpa disadari. Maraknya penggunaan *online editor* seperti Google Docs atau Overleaf secara tidak langsung menunjukkan manfaat utama dari *version control* dalam kolaborasi.

Git berbeda dari *online editor* melakukan *version control* secara bertahap dan dalam tingkat file. Hal ini berarti bahwa dua orang tidak dapat mengedit satu file yang sama secara bersamaan. Akan tetapi, dua orang masih dapat mengedit file secara terpisah dan melakukan proses ***Merge***. Ini adalah buntut dari sistem Git yang terdistribusi, di masing-masing lokasi lokal dapat memiliki file yang berbeda.

Pada sesi kali ini, kita akan membahas salah satu alur penggunaan Git dengan basis *feature branch*. Ada beberapa metode lain yang mungkin bisa kalian gunakan sesuai dengan kebutuhan yang memiliki keuntungan dan kekurangan masing-masing.

## *Merging Branch*

Dalam proses kolaborasi, kita tidak dapat menghindari kenyataan bahwa pada suatu waktu histori *commit* kita akan bercabang. Untuk hal ini ada beberapa cara yang dapat kita gunakan untuk meluruskan histori file di Git. Kita akan membahas lebih lanjut proses *merging* dalam HIMA:LATIHAN 2.

## *Pull Request*

*Pull request* adalah salah satu fitur GitHub yang sangat berguna untuk kolaborasi. Fitur ini berfungsi untuk melakukan *review* secara eksplisit terhadap proses *merge* dari dua *branch* yang berbeda. Beberapa pengguna yang ditunjuk sebagai pengawas *repo* dapat melakukan pengecekan terhadap kode-kode yang akan digabungkan dengan *branch* utama. Dalam penggunaan fitur ini, biasanya *branch* utama hanya akan dapat diakses oleh beberapa orang saja. Hal ini mengurangi resiko penulisan kode yang tidak sesuai dengan standar yang ditetapkan.

HIMA:

## *Feature Branch*

*Feature branch* adalah metode penggunaan Git yang memanfaatkan *branch* untuk mengelola subset file berkaitan dengan suatu fitur tertentu. Misalnya dalam penelitian, satu peneliti dapat bertanggung jawab terhadap program pengolah data sedangkan peneliti lain dapat bertanggung jawab dalam program untuk analisa. Dengan menggunakan konsep ini, masing-masing peneliti membuat *branch* yang berbeda dari *branch* utama (*main* atau *master*). Seluruh perubahan yang dilakukan akan kemudian disimpan dalam *branch* masing-masing. Saat program keseluruhan ingin dijalankan, fitur yang sudah selesai dapat digabungkan dengan *branch* utama.

Konsep ini juga mendorong modularisasi proses penelitian dan mengurangi kebutuhan untuk *merging* yang rawan kesalahan.

## Privatisasi *Repository*

Sering kali saat kita ingin bekerja dengan orang lain, kita tidak ingin agar apa yang kita kerjakan selalu terlihat oleh orang lain. GitHub sendiri memiliki konsep ***Fork*** di mana kita dapat membuat *repo* terpisah dari *repo* utama yang terhubung secara tidak langsung di platform GitHub. Akan tetapi, konsep *Fork* bukanlah konsep dari Git dan memiliki kelemahan bahwa *repo* yang dihasilkan tidak bisa bersifat privat.

Untuk hal ini kita dapat menggunakan *repo* privat yang ditambahkan sebagai *remote* kedua dari local *repo* yang kita kerjakan. Dengan cara ini dan sistem [*Feature Branch*](#feature-branch), kita dapat bekerja sama tanpa harus khawatir tentang hasil kerja sementara kita terlihat oleh orang lain.

Tahapan kerja untuk hal ini dapat dilihat di HIMA:LATIHAN 2.
