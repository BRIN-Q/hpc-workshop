---
layout: default
title: Version Control dengan Git
last_modified_date: 2023-09-07
---
# *Version Control* dengan Git

![Kejadian umum dalam riset](../assets/images/phdc_version.gif)
*Diambil dari [
Piled Higher and Deeper oleh Jorge Cham](https://phdcomics.com/comics/archive.php?comicid=1531)*

## Mengapa *Version Control*?

Selama ini kita mungkin sudah terbiasa dengan cara tradisional dalam melakukan *version control* seperti yang dapat kita lihat dari komik di atas. Perubahan nama file sebagai *version control* memang mudah, tapi akan dapat menimbulkan masalah seperti:

* Meningkatnya jumlah file yang disimpan.
* Tidak mudah untuk melihat perubahan dari satu versi ke versi lainnya.
* Penamaan file sering kali tidak konsisten dan dapat membuat bingung.
* Melacak awal mula dari kesalahan atau *bug* yang ada dapat menjadi rumit dan memakan waktu yang lama.
* Berbagi file dan berkolaborasi dengan orang lain menjadi lebih susah apabila kita ingin juga bekerja pada waktu yang bersamaan.
* Terkadang kita lupa untuk menyimpan *backup* dari versi terakhir file yang kita kerjakan.

Untuk mengatasi permasalahan di atas, kita sebaiknya menggunakan *version control* modern sebagai sarana untuk mengelola file yang kita kerjakan. Dalam sejarahnya, ada beberapa jenis *version control* yang umum digunakan. Pada kesempatan kali ini kita akan membahas penggunaan **Git** sebagai metode *version control* modern.

## Pengenalan Git

Sistem Git memungkinkan untuk menyimpan histori file secara otomatis dan secara terdistribusi. Patut diakui bagi banyak orang desain Git cukup menantang dan dapat menjadi rumit. Git sendiri menggunakan konsep [*Directed Acyclic Graph* (DAG)](https://en.wikipedia.org/wiki/Directed_acyclic_graph) untuk menyimpan histori dari file yang kita kerjakan.

### Terminologi

Ada beberapa kosa kata yang sering digunakan dalam pembahasan Git:

| Terminologi | Penjelasan |
| :--- | :--- |
| **Repository** | Satuan kerja dari Git yang melingkupi beberapa file dan direktori yang terlacak. |
| **Commit** | Rekaman *repo* dari satu waktu tertentu. |
| **Staging** | Proses menambahkan file ke dalam wadah untuk direkam sebagai *commit*. |
| **Branch** | *Pointer* dengan nama yang mengarah ke suatu *commit* di *repo*. |
| **Merge** | Penggabungan dari dua cabang histori yang berbeda. |
| **Remote** | Lokasi eksternal tempat penyimpanan *repo*. |
| **Pull** | Memperbarui file lokal dengan file yang ada di *remote repo*. |
| **Push** | Memperbarui file di *remote repo* dengan file lokal. |

### *Command* Dasar

Ada beberapa command dasar yang kita dapat gunakan untuk menggunakan Git:

| Command | Penjelasan |
| :--- | :--- |
| `git init` | Membuat *repo* baru. |
| `git status` | Melihat status ringkasan dari *repo* saat ini. |
| `git log` | Melihat *log* dari *repo*. |
| `git add [Nama File]` | Menambahkan file ke dalam *staging area*. |
| `git commit -m [Pesan]` | Menyimpan file yang ada di *staging area* ke dalam *commit* baru di *repo*. |
| `git checkout [Nama Branch]` | Pindah ke *branch*. |
| `git checkout -b [Nama Branch]` | Membuat *branch* baru dan pindah ke *branch* tersebut. |
| `git clone [URL]` | Mengunduh *repo* dari *remote* ke *local*. |
| `git remote add [Nama Remote] [URL]` | Menambahkan *remote* baru ke *repo* lokal. |
| `git pull` | Memperbarui file lokal dengan file yang ada di *remote repo*. |
| `git push` | Memperbarui file di *remote repo* dengan file lokal. |
| `git merge [Nama Branch]` | Menggabungkan *branch* yang sedang aktif dengan *branch* yang dituju. |

{: .catatan }
> Ada dua jenis *remote repo* yaitu yang menggunakan autentikasi HTTPS atau SSH:
>
> * HTTPS: `https://github.com/BRIN-Q/hpc-workshop.git`
> * SSH: `git@github.com:BRIN-Q/hpc-workshop.git`

### Setup Git

Sebelum menggunakan Git, kita harus melakukan beberapa pengaturan yang akan menjadi identitas kita. Untuk penggunaan paling sederhana, kita harus mengatur nama dan alamat email yang akan menjadi penanda *commit* dengan cara:

```bash
git config --global user.name 'Peneliti BRIN'
git config --global user.email 'email@brin.go.id'
```

## Penggunaan GitHub

Ada beberapa situs yang sering digunakan sebagai lokasi *remote repo*. Pada workshop kali ini kita akan menggunakan [GitHub](https://github.com/) sebagai lokasi *remote*. Selain GitHub, beberapa situs populer lainnya adalah [GitLab](https://gitlab.com/) dan [BitBucket](https://bitbucket.org/).

Untuk menggunakan GitHub, pastikan kalian telah mendaftarkan diri dan memilih user ID yang unik. Setelah mendaftar, pastikan untuk mendaftarkan alamat email yang kalian gunakan pada [tahap sebelumnya](#setup-git) agar akun kalian dapat terhubung dengan *commit* yang telah kalian buat.

{: .catatan}
Sangat dianjurkan untuk menggunakan autentikasi SSH untuk *remote repo* yang akan kita gunakan. Penggunaan SSH dapat dilihat di HIMA(add link ke workshop ssh).
