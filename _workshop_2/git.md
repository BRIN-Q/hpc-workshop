---
layout: default
title: Version Control dengan Git
nav_order: 1
last_modified_date: 2023-09-07
---
# *Version Control* dengan Git

![Kejadian umum dalam riset](../assets/images/phdc_version.gif)

*Diambil dari [
Piled Higher and Deeper oleh Jorge Cham](https://phdcomics.com/comics/archive.php?comicid=1531).*

## Mengapa *Version Control*?

Selama ini kita mungkin sudah terbiasa dengan cara tradisional dalam melakukan **version control** seperti yang dapat kita lihat dari komik di atas. Perubahan nama file sebagai *version control* memang mudah, tapi akan dapat menimbulkan masalah seperti:

* **Meningkatnya jumlah file** yang disimpan.
* Tidak mudah untuk melihat **perubahan file** dari satu versi ke versi lainnya.
* Penamaan file sering kali tidak **konsisten** dan dapat membuat bingung.
* **Melacak perubahan** yang menyebabkan *bug* rumit dan memakan waktu yang lama.
* **Berbagi file dan berkolaborasi** dengan orang lain menjadi lebih susah apabila kita ingin juga bekerja pada waktu yang bersamaan.
* **Penyimpanan *backup*** dari versi terakhir tidak otomatis file yang kita kerjakan.

*Version control* modern dapan menjadi sarana untuk mengatasi permasalahan di atas dalam pengelolaan file.

Dalam sejarahnya, ada beberapa jenis *version control* yang cukup umum digunakan. Pada kesempatan kali ini kita akan fokus dalam penggunaan **Git** sebagai metode *version control* modern.

## Pengenalan Git

Sistem Git memungkinkan untuk menyimpan histori atau versi file secara **otomatis** dan **terdistribusi**.

Git sendiri menggunakan konsep [*Directed Acyclic Graph* (DAG)](https://en.wikipedia.org/wiki/Directed_acyclic_graph) untuk menyimpan histori dari file yang kita kerjakan.

Bagi banyak orang desain Git sendiri terlihat cukup rumit, namum dalam penggunaan sehari-hari kita tidak perlu mengkhawatirkan basis implementasinya.

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

**Command dasar** yang sering digunakan untuk menggunakan Git:

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
> * HTTPS: `https://github.com/[USER atau ORGANISASI]/[NAMA REPO].git`
> * SSH: `git@github.com:[USER atau ORGANISASI]/[NAMA REPO].git`

### Setup Git

Sebelum menggunakan Git, kita harus melakukan beberapa pengaturan yang akan menjadi **identitas** kita. Identitas ini akan berguna sebagai penanda dari *commit*.

Untuk penggunaan paling sederhana, kita harus mengatur **nama** dan **alamat email** dengan cara:

```bash
git config --global user.name 'Peneliti BRIN'
git config --global user.email 'email@brin.go.id'
```

Selain itu, ada beberapa hal yang dapat kita gunakan seperti editor, **alias**, dan warna. Pengaturan juga dapat disimpan di dalam file `.gitconfig` yang berada di direktori *home* untuk tingkat *global* atau di dalam direktori *repo* untuk pengaturan lokal.

Contoh isi file `.gitconfig`:

```ini
[user]
        name = Peneliti BRIN
        email = email@brin.go.id
[core]
        editor = nano
[alias]
        co = checkout
        ci = commit
        br = branch
        lg = log --oneline --graph --decorate
        lga = log --oneline --graph --decorate --all
        st = status -s
        revchange = !git checkout . && git clean -dfX
[color]
        diff = auto
        status = auto
        branch = auto
        interactive = auto
        ui = true
        pager = true
[pull]
        ff = only
```

## Penggunaan GitHub

Ada beberapa situs yang sering digunakan sebagai lokasi ***remote repo***.

Pada workshop kali ini kita akan menggunakan [GitHub](https://github.com/) sebagai lokasi *remote*. Selain GitHub, beberapa situs populer lainnya adalah [GitLab](https://gitlab.com/) dan [BitBucket](https://bitbucket.org/).

Untuk menggunakan **GitHub**, pastikan kalian telah mendaftarkan diri dan memilih user ID yang unik. Setelah mendaftar, pastikan untuk mendaftarkan alamat email yang kalian gunakan pada [tahap sebelumnya](#setup-git) agar akun kalian dapat terhubung dengan *commit* yang telah kalian buat.

### Autentikasi dengan SSH

***Secure Shell*** (SSH) adalah protokol jaringan komunikasi antara dua perangkat jarak jauh. Dalam konteks penggunaan GIT, kita akan menggunakan **sistem autentikasi SSH** untuk mengakses *remote repo*.

Untuk pengguna sistem berbasis UNIX, protokol SSH dapat diakses secara langsung melalui terminal. Untuk pengguna Windows 10/11 versi terbaru, fitur SSH harus diaktifkan terlebih dahulu di pengaturan `Opsional Aplikasi > Pengaturan > Windows`, lalu mencari "**OpenSSH**" di fitur yang diinstal. Selain itu, kita juga dapat menggunakan aplikasi seperti [PuTTY](https://www.putty.org/) atau [Git Bash](https://gitforwindows.org/) untuk mengakses protokol SSH.

Untuk menggunakan autentikasi melalui SSH, kita harus [membuat **pasangan kunci** (*key pair*)](https://docs.oracle.com/en/cloud/cloud-at-customer/occ-get-started/generate-ssh-key-pair.html) terlebih dahulu.

Setelah membuat pasangan kunci, kita dapat menambahkan **kunci publik** (*public key*) ke dalam akun GitHub kita melalui [tautan ini](https://github.com/settings/ssh/new). Pastikan bahwa perintah `ssh -T git@github` berhasil dijalankan.
