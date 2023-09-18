---
layout: default
title: Makefile
nav_order: 2
last_modified_date: 2023-09-15
---
# Makefile

**Makefile** adalah file yang digunakan oleh program **GNU Make** untuk melakukan kompilasi secara cerdas. Makefile bekerja dengan cara memeriksa waktu modifikasi dari file terkait dan melakukan kompilasi hanya pada file yang telah berubah sejak waktu kompilasi terakhir.

## Rule Makefile

Untuk menggunakan Makefile, kita harus membuat file dengan nama `Makefile` yang berada pada direktori kompilasi. Masing-masing direktori dapat memiliki `Makefile` yang berbeda-beda. Berikut adalah ***rule*** umum dari `Makefile`:

```makefile
target: dependencies
    command
    command
```

| Syntax | Keterangan |
| --- | --- |
| `target` | Nama dari file yang akan dibuat. |
| `dependencies` | Nama dari satu atau file yang dibutuhkan untuk membuat `target`. |
| `command` | Perintah yang akan dijalankan untuk membuat `target`. |

{: .catatan }
Apabila ada beberapa file yang ditulis di `target`, masing-masing file akan dibuat secara terpisah dimulai.

{: .peringatan }
File `Makefile` harus menggunakan indentasi *hard* dalam bentuk `Tab` sebelum setiap `command`.

## Menjalankan Makefile

Untuk membuat salah satu target yang ada di Makefile, kita dapat menggunakan perintah:

```bash
make target
```

Apabila tidak ada file dengan nama `target`, setiap file di `dependencies` akan menjadi target baru yang akan dibuat. Setelah itu, `command` untuk `target` akan dijalankan.

Sebaliknya, apabila sudah ada file dengan nama `target`, hanya file di `dependencies` yang memiliki *timestamp* lebih baru dari `target` akan dibuat menjadi target baru. Apabila ada target yang dibuat ulang, `command` untuk `target` akan dijalankan.

## Variabel Makefile

Ada beberapa cara definisi variabel di Makefile:

| Syntax | Keterangan |
| :- | :- |
| `VARIABLE = value` | Variabel memiliki nilai `value` yang akan diekspansi saat penggunaan `VARIABLE`. |
| `VARIABLE := value` | Variabel memiliki nilai `value` yang akan diekspansi saat definisi `VARIABLE`. |
| `VARIABLE += value` | Nilai `value` akan ditambahkan ke `VARIABLE` nilai `value` akan diekspansi sesuai dengan jenis definisi `VARIABLE`. |
| `VARIABLE ?= value` | Variabel memiliki nilai `value` yang akan diekspansi saat penggunaan `VARIABLE` apabila `VARIABLE` belum didefinisikan. |

Nilai variabel dapat diakses dengan menggunakan `$(VARIABLE)`.

### Wildcard

Wildcard dapat digunakan untuk menyederhanakan penulisan Makefile. Sama seperti penggunaan di *shell*, kita dapat menggunakan `*.o` untuk mencocokan semua file yang berakhiran `.o`.

{: .peringatan }
> Wildcard tidak terekspansi saat menggunakan definisi variabel. Untuk penggunaan yang optimum gunakan definisi `objects := $(wildcard *.o)`.

### Pattern Rule

Pattern rule dapat digunakan untuk menyederhanakan penulisan Makefile. Pattern rule digunakan untuk membuat target yang memiliki pola tertentu. Berikut adalah contoh penggunaan pattern rule:

```makefile
%.o: %.c
    $(CC) -c $(CFLAGS) $< -o $@
```

Pada contoh di atas, target yang dibuat memiliki pola `%.o` yang mencakup semua file `*.o`. `%.c` menandakan bahwa `dependencies` adalah file berakhiran `.c` dengan nama yang sama. `$<` dan `$@` adalah variabel otomatis yang akan dijelaskan pada bagian selanjutnya.

### Variabel Otomatis

Ada beberapa variabel otomatis yang juga dapat digunakan untuk menyederhanakan penulisan Makefile:

| Variabel | Keterangan |
| :- | :- |
| `$@` | Nama dari target yang sedang dibuat. |
| `$<` | Nama dari file pertama di `dependencies`. |
| `$^` | Nama dari semua file di `dependencies`. |
| `$?` | Nama dari semua file di `dependencies` yang memiliki *timestamp* lebih baru dari target. |
| `$*` | Nama dari target yang sedang dibuat tanpa ekstensi. Biasanya digunakan untuk penggunaan *pattern rule*. |

### `.PHONY`

`.PHONY` adalah target spesial yang dapat digunakan agar perintah `make` selalu dapat berjalan tanpa harus khawatir akan adanya file dengan nama yang sama. Berikut adalah contoh penggunaan `.PHONY`:

```makefile
.PHONY: clean

clean:
    rm -f *.o
```

## Contoh Makefile

```makefile
CC = gcc
CFLAGS = -O2

objects := $(wildcard *.o)

all: program

%.o: %.c
    $(CC) -c $(CFLAGS) $< -o $@

program: $(objects)
    $(CC) $(CFLAGS) $^ -o $@

.PHONY: all

clean:
    rm -f *.o
```
