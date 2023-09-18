---
layout: default
title: Coding Best Practice
last_modified_date: 2023-09-07
---

# Coding Best Practice

Tidak semua peneliti memiliki dasar ilmu pemrogaman yang sama. Hal ini dapat menjadi masalah ketika kita ingin berkolaborasi dengan peneliti lain. Untuk itu ada beberapa hal yang dapat kita lakukan untuk mempermudah proses kolaborasi.

## Penggunaan IDE

IDE atau *Integrated Development Environment* adalah program penulisan kode yang dapat membantu kita untuk menulis kode dengan lebih efisien. Pada workshop kali ini, kita akan membahas penggunaan [Visual Studio Code (VS Code)](https://code.visualstudio.com/) sebagai IDE utama. VS Code memiliki keunggulan sebagai IDE *open-source* yang ringan dan dapat diubah sesuai dengan kebutuhan penggunaan. VS Code juga dapat digunakan baik secara daring maupun luring di berbagai jenis sistem operasi.

Ada beberapa komponen dari IDE yang dapat kita gunakan untuk mempermudah alur kerja:

* **Linting**

    *Linting* adalah proses *formatting* kode secara otomatis. Penggunaan *linter* dengan pengaturan yang sama dapat meminimialisasi konflik cara penulisan antar pengguna, misalnya jumlah tabulasi yang digunakan.

* **Syntax Highlighting**

    Dibanding dengan editor teks sederhana, IDE pada umumnya dapat memberikan warna yang berbeda untuk variabel, fungsi, maupun kata kunci dari program yang sedang kita edit. Hal ini dapat mengurangi kesalahan penulisan kode, seperti kurangnya tabulasi di Python atau hilangnya tanda titik koma di C++.

* **Refactoring**

    Keunggulan lain dari IDE adalah mudahnya melakukan proses *refactoring* yaitu proses perubahan penulisan kode menjadi lebih efisien tanpa mengubah cara kerja kode. IDE dapat menggaris bawahi variabel yang tidak digunakan, melakukan *rename* variabel secara pintar, dan bahkan menyarankan bentuk kode yang lebih efisien.

* **Build System**

    IDE juga dapat membantu kita dalam proses kompilasi dan menjalankan program secara otomatis. Kita tidak lagi perlu untuk melakukan kompilasi manual `g++ ...` setiap kali kita mengubah satu subset kode.

* **Debugger**

    IDE modern juga biasanya memiliki sistem integrasi dengan *debugger* yang dapat membantu kita dalam menemukan kesalahan yang terjadi pada kode kita. Hasil keluaran *debugger* dapat ditampilkan secara langsung di IDE sehingga memudahkan proses *debugging*.

* **Testing**

    Proses *testing* kode mungkin menjadi hal yang paling asing bagi peneliti ilmiah. Tujuan dari proses *testing* adalah untuk menguji kinerja program yang ingin kita tulis agar sesuai dengan tujuan yang diharapkan. IDE dapat membantu kita untuk melakukan proses ini secara otomatis dan lebih mudah.

## Format Kode

Dalam penulisan kode secara kolaboratif, penentuan standar format penulisan kode sangatlah penting. Beberapa bahasa pemrograman memiliki standar format yang ditentukan, misalnya [PEP8](https://www.python.org/dev/peps/pep-0008/) untuk Python. Bahasa lain seperti C++ memiliki beberapa standar format yang dapat digunakan, misalnya [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). Untuk kasus seperti ini, sebaiknya format penulisan yang sama disetujui oleh semua anggota tim pada awal kolaborasi.

Beberapa poin yang patut diperhatikan dalam format penulisan kode adalah:

* **Indentasi**

    Indentasi dapat bersifat *hard* yang menggunakan karakter `Tab` atau *soft* yang menggunakan beberapa karakter `Space`. Dalam beberapa bahasa pemrograman seperti Python dan Fortran, indentasi menjadi penanda konteks kode.

* **Penamaan Variabel**

    Penamaan variabel dapat digunakan untuk mempermudah pemahaman kode. Misalnya, di Python variabel umum menggunakan `mixedCase` sedangkan menurut Google C++ Style Guide variabel menggunakan `snake_case`. Parameter pada umumnya diketik menggunakan `UPPER_CASE`.

    Penamaan variabel juga harus deskriptif, kita akan lebih mudah memahami arti dari variabel `posisi` dibandingkan dengan `x` atau `posisi_benda`.

* **Panjang Baris**

    Panentuan panjang baris maksimum dari kode dapat mempermudah pada waktu kita harus membaca ulang kode. Coba bandingkan penulisan kode seperti ini:

    ```fortran
    g=bx(l+ix,1,1)+bx(l+ix-iz,1,1)+dz*(bx(l+ix+iz,1,1)-bx(l+ix-iz,1,1))+g+dy*(bx(l+ix+iy,1,1)+bx(l+ix+iy-iz,1,1)+dz*(bx(l+ix+iy+iz,1,1)-bx(l+ix+iy-iz,1,1))-g)
    ```

    dengan kode seperti ini:

    ```fortran
     g = bx(l+ix,1,1) + bx(l+ix-iz,1,1) + dz * (bx(l+ix+iz,1,1) - &
        bx(l+ix-iz,1,1)) + g + dy * (bx(l+ix+iy,1,1) + bx(l+ix+iy-iz,1,1) + &
            dz * (bx(l+ix+iy+iz,1,1) - bx(l+ix+iy-iz,1,1)) - &
        g)
    ```

    Kode kedua lebih mudah dibaca karena panjang barisnya dibatasi maksimal 80 karakter dan memanfaatkan penggunaan indentasi yang bermakna.

* **Komentar**

    Sering kali saat kita harus membaca ulang kode yang kita tulis beberapa waktu lalu, kita kesulitan untuk memahami maksud dari kode tersebut. Penulisan komentar yang deskriptif dan efisien dapat membantu kita untuk memahami kode.
