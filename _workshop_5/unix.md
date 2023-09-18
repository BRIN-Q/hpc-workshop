---
layout: default
title: UNIX Shell
nav_order: 1
last_modified_date: 2023-09-07
---
# UNIX Shell

Seperti telah dijelaskan di awal, pada seri workshop kali ini kita menggunakan **UNIX syntax dan shell**.

Dalam sesi workshop kali ini, kita akan menjelajahi lebih lanjut **penggunaan UNIX Shell** dalam mendukung proses penelitian.

## Perbedaan dengan Windows

Mayoritas pengguna komputer di Indonesia menggunakan sistem operasi berbasis Windows yang menggunakan **DOS system**. Ada beberapa **perbedaan dari DOS dan UNIX**:

### *Line endings*

Pada Windows, akhir baris kode ditandai dengan dua karakter, yaitu `\r\n`  atau *Carriage Return* (CR) dan *Line Feed* (LF)

Sistem UNIX hanya menggunakan satu karakter LF `\n` untuk menandai akhir baris.

Perbedaan ini sering menyebabkan **masalah** dalam penelitian yang melibatkan banyak orang. Misalnya ketika kita menggunakan Git, **semua line** file yang disimpan dengan IDE di Windows akan diubah oleh IDE di UNIX. Hal ini akan membuat log dari Git penuh dengan perubahan *line ending* di setiap file.

{: .catatan }
Untuk menghindari masalah ini, kita dapat menggunakan *command* `git config --global core.autocrlf input`. Dengan perintah ini, Git akan secara otomatis mengubah line ending ketika kita melakukan *commit*.[^1]

### *Case sensitivity*

UNIX merupakan sistem operasi yang ***case sensitive***, artinya `a.txt` dan `A.txt` merupakan dua file yang berbeda. Hal ini berbeda dengan Windows yang *case insensitive* yang menganggap kedua nama file tersebut sama.

### *Path*

Sistem file untuk UNIX berbeda dengan Windows. Untuk UNIX, **seluruh direktori memiliki akar atau *root*** yang diawali dengan `/`.

Windows menggunakan **sistem *drive*** yang biasanya ditandai dengan abjad seperti `C:\`.

Pada UNIX, direktori dan file dipisahkan dengan `/`, sedangkan pada Windows dipisahkan dengan `\`.

### *File Permission*

UNIX menggunakan sistem ***file permission* yang membedakan akses untuk pengguna** yang dibagi menjadi *owner* (`o`), *group* (`g`), dan *all* (semua pengguna lainnya) (`a`). Untuk masing-masing jenis pengguna, terdapat **tiga jenis *permission*** yang berbeda yaitu *read* (`r`), *write* (`w`), dan *execute* (`x`).

Akses membaca (*read*) dan menulis (*write*) file dapat digunakan untuk melindungi file dari pengguna lain di kluster.

Akses eksekusi (*execute*) berguna untuk **mencegah** kita menjalankan file yang tidak seharusnya dieksekusi. Opsi ini dapat diubah untuk menjalankan file *binary* atau *script* dengan mudah.

#### Cara Mengubah *File Permission*

##### Menggunakan *Symbolic Notation*

Akses *file permission* dapat dengan mudah diubah menggunakan *command* `chmod [permission] [filename]`.

Penulisan `[permission]` dapat menggunakan simbol

```bash[pengguna: o/g/a][+ / -][r/w/x]```.

##### Menggunakan *Octal Notation*

Contohnya, `chmod og+x file.txt` akan menambahkan akses eksekusi untuk pemilik dan grup.

Penulisan `[permission]` juga dapat menggunakan **angka** yang merepresentasikan kombinasi dari `rwx` dengan nilai 4, 2, dan 1.

Contohnya, `chmod 755 file.txt` akan memberikan akses `rwxr-xr-x` untuk pemilik, grup, dan semua pengguna lainnya.

## *Command* Dasar

Berikut adalah beberapa *command* dasar yang sering digunakan dalam UNIX shell.

| *Command* | Keterangan |
| :- | :- |
| `man [COMMAND]` | Melihat *manual* dari `COMMAND` |
| `ls` | Melihat isi direktori |
| `cd` | Pindah direktori |
| `pwd` | Melihat direktori saat ini |
| `touch` | Membuat file kosong |
| `mkdir` | Membuat direktori |
| `rm` | Menghapus file atau direktori |
| `rmdir` | Menghapus direktori |
| `cp` | Mengcopy file atau direktori |
| `mv` | Memindahkan file atau direktori |
| `chmod` | Mengubah *file permission* |
| `cat` | Melihat isi file |
| `more` | Melihat isi file |
| `head` | Melihat isi file bagian awal |
| `tail` | Melihat isi file bagian akhir |
| `echo` | Menampilkan teks |
| `diff` | Membandingkan isi dua file |

## *Shell*

***Shell*** merupakan program yang berfungsi sebagai antarmuka antara pengguna dengan sistem operasi.

Ada **beberapa jenis *shell*** yang digunakan secara umum di sistem operasi UNIX, yaitu *Bourne Again Shell* (`bash`), *C Shell* (`csh`),
, dan *Z Shell* (`zsh`).

Pada seri workshop ini, kita akan menggunakan **`bash`** sebagai *shell* yang digunakan. Hampir semua *command* yang digunakan pada seri workshop ini dapat digunakan pada *shell* lainnya.

## *Shell Script*

Untuk memudahkan proses penelitian, seringkali kita membutuhkan beberapa *command* yang dijalankan secara **berurutan dan berulang**. ***Shell script*** merupakan kumpulan *command* yang disimpan dalam sebuah file.

Keuntungan dari penggunaan *shell script* dibandingkan program yang lebih kompleks, misalnya Python, adalah **kemudahan eksekusi** tanpa perlu adanya instalasi tambahan atau kompilasi.

Berikut adalah contoh *shell script* yang dapat digunakan untuk mengganti file dengan nama `result.dat` menjadi `result_[TANGGAL].dat` dan mengubah *file permission* menjadi `644`.

```bash
#!/bin/bash

# Mengambil tanggal saat ini
TANGGAL=$(date +%Y_%m_%d)

# Mengganti nama file
mv result.dat result_${TANGGAL}.dat

# Mengubah file permission
chmod 644 result_${TANGGAL}.dat
```

Baris pertama dari *shell script* yang diawali dengan *shebang* (`#!`) menandakan *shell* yang digunakan saat eksekusi langsung menggunakan `./[NAMA_FILE]`.

Untuk menjalankan *shell script*, kita dapat menggunakan *command* `bash [NAMA_FILE]` atau dengan menambahkan akses eksekusi di *file permission* dengan menggunakan `chmod +x [NAMA_FILE]`.

### Variabel

Seperti pada script di atas, kita dapat menyimpan nilai dalam sebuah variabel. Variabel dapat diinisialisasi dengan menggunakan `NAMA_VARIABEL=ISI_VARIABEL` atau `NAMA_VARIABEL=$(COMMAND)` untuk menggunakan hasil dari `COMMAND`.

Untuk mengakses nilai dari variabel, kita dapat menggunakan `${NAMA_VARIABEL}`. Walaupun memungkinkan menggunakan nilai variabel dengan `$NAMA_VARIABEL`, hal ini dapat menjadi rancu ketika kita memanipulasi string seperti `"${FOO}BAR"` dan `"$FOOBAR"`.

### If-Else

Untuk melakukan *conditional execution*, kita dapat menggunakan *command* `if` dan `else` seperti pada contoh di bawah ini.

```bash
if [KONDISI]
then
    statement
else
    statement
fi
```

`[KONDISI]` dapat menggunakan *command* `test` atau `[ ]` untuk membandingkan nilai dari variabel, contohnya `[ $A -eq $B ]` untuk membandingkan apakah nilai dari variabel `A` sama dengan `B`.

### For Loop

Untuk melakukan *looping*, kita dapat menggunakan *command* `for` seperti pada contoh di bawah ini.

```bash
for VARIABLE in [LIST]
do
    statement
done
```

`[LIST]` dapat berupa daftar nilai yang dipisahkan dengan spasi, misalnya `1 2 3 4 5` atau `$(ls *.txt)` untuk mengambil semua file dengan ekstensi `.txt`.

## Profil Bash

**Pengaturan** untuk *shell* `bash` dapat disimpan dalam sebuah file bernama `.bashrc` yang berada di direktori *home* pengguna.

`.bashrc` ditulis dengan sintaks yang sama dengan *shell script* dan akan dijalankan setiap kali *shell* dibuat. Kita juga dapat menggunakan profil yang terbarui dengan menggunakan *command* `source .bashrc`.

Beberapa komponen pengaturan yang dapat berguna adalah:

### *Alias*

***Alias*** merupakan ***shortcut*** untuk *command* yang sering digunakan. *Alias* dapat ditambahkan di `.bashrc` dengan sintaks `alias [ALIAS]=[COMMAND]`.

Contoh beberapa *alias* yang sering digunakan:

```bash
alias ll='ls -lh --color=auto' 2>/dev/null
```

### *Environment Variable*

***Environment variable*** merupakan variabel yang dapat terdefinisi pada tingkat *shell* dan dapat digunakan oleh semua program yang dijalankan dari *shell*. Variabel ini disimpan dengan menggunakan kata kunci `export`.

Beberapa variabel yang sering digunakan adalah:

```bash
export PATH=$PATH:/usr/local/bin
export PS2='> '
```

{: .catatan }
> Variabel `PATH` merupakan daftar direktori yang dicari oleh *shell* untuk menjalankan *command*.

{: .catatan}
> Variabel `PS[0-4]` mengatur tampilan *prompt* pada *shell*. Informasi lebih lanjut dapat dilihat di [sini](https://wiki.archlinux.org/title/Bash/Prompt_customization).

### *Prompt*

***Prompt*** merupakan teks yang muncul di *shell* setelah *command* selesai dijalankan. *Prompt* dapat diubah dengan mengubah nilai dari variabel `PS1`.

[^1]: [Tutorial GitHub untuk *line ending*.](https://docs.github.com/en/get-started/getting-started-with-git/configuring-git-to-handle-line-endings)
