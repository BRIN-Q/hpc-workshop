---
layout: default
title: Visualisasi Untuk Publikasi
last_modified_date: 2023-09-07
usemathjax: true
---
# Visualisasi untuk Publikasi

Bagi peneliti, ada dua jenis visualisasi yang sering digunakan, yaitu visualisasi untuk eksplorasi data dan visualisasi untuk publikasi. Untuk eksplorisasi data, figur yang dihasilkan biasanya tidak perlu terlalu rapi mengingat tujuan utamanya adalah untuk memahami data. Akan tetapi, untuk visualisasi yang akan digunakan untuk publikasi, figur yang dihasilkan haruslah rapi dan sesuai dengan standar jurnal yang dituju.

Pada sesi kali ini, kita akan membahas beberapa hal yang perlu diperhatikan dalam pembuatan visualisasi untuk publikasi.

## Objek Figur

Untuk membuat figur yang mudah dikonfigurasi, sebaiknya kita menyimpan variabel-variabel yang berisi komponen figur. Misalnya untuk membuat plot sederhana, sering kali kita melakukan:

```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2*np.pi, 100)
y = np.sin(x)

plt.plot(x, y)
```

Kendala dari cara ini adalah kita tidak mudah untuk mengatur komponen dari figur. Cara yang lebih tepat adalah dengan menyimpan objek-objek plot yang dibuat secara manual. Misalnya:

```python
fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(x, y)
```

Dengan pendekatan ini, masing-masing komponen figur dapat diatur dengan mudah. Misalnya, apabila kita ingin mengubah skala sumbu $x$ pada menjadi logaritmik, kita dapat menggunakan `ax.set_xscale('log')`.

Figure dan Axes yang sedang aktif juga dapat diperoleh dengan menggunakan `fig = plt.gcf()` dan `ax = plt.gca()`.

## Pengaturan Dimensi Figur

Sesuai dengan hirarki komponen dalam Matplotlib, kita akan memulai dengan membahas parameter yang berkaitan dengan **Figure**. Untuk figur publikasi, biasanya terdapat dua jenis ukuran yang perlu diperhatikan, yaitu ukuran figur dan resolusi plot. Ukuran figur biasanya ditentukan dari ukuran kertas dan margin yang ditetapkan oleh jurnal, sedangkan resolusi plot cenderung lebih fleksibel. Selain itu, hal lain yang perlu diperhatikan adalah pengaturan ukuran *font* yang bergantung pada resolusi figur.

### Ukuran Figur

Ukuran figur dapat ditentukan dengan menggunakan parameter `figsize` yang menjadi salah satu input dari fungsi `plt.figure()`. Secara global, nilai dari parameter ini dapat diatur dengan mengganti nilai dari variabel `figure.figsize` di pengaturan `rcParams` dari Matplotlib. Parameter `figsize` dapat diatur dengan menggunakan *tuple* atau *list* yang berisi dua nilai, yaitu lebar dan tinggi figur dalam satuan **inci**. Biasanya ukuran figur yang diterima oleh jurnal dapat ditemukan di halaman *Author Guidelines* atau *Instruction for Authors*.

### Resolusi Figur

Sama seperti ukuran figur, resolusi dari figur dapat dubah dengan dengan menggunakan parameter `dpi` sebagai input dari fungsi `plt.figure()`. Nilai parameter ini secara global dapat diubah melalui variabel `figure.dpi` di pengaturan `rcParams` Matplotlib. Nilai dari `dpi` mengatur berapa banyak ***pixel*** per satuan inci dari ukuran figur yang diberikan.

{: .catatan }
> Ukuran figur dalam *pixel* dapat dihitung melalui:
>
> $$
> \begin{align}
> \text{Ukuran Figur (inci)} &= l \times w, \\
> \text{Ukuran Figur (pixel)} &= (l \times \text{dpi}) \times (w \times \text{dpi}).
> \end{align}
> $$

### Ukuran Font

Ukuran font dapat ditentukan dengan menggunakan angka dalam satuan **pt** atau dengan menggunakan nilai relatif terhadap ukuran figur dengan nilai: `{'xx-small', 'x-small', 'small', 'medium', 'large', 'x-large', 'xx-large'}`. Ukuran font dapat diatur secara global melalui variabel `font.size` di `rcParams` Matplotlib. Akan tetapi, banyak komponen turunan dari figur yang memiliki parameter `fontsize` sendiri baik dalam proses inisialisasi maupun di `rcParams`.

{: .catatan }
> Satuan **pt** untuk font memiliki asumsi `dpi` dengan nilai 72. Apabila nilai `dpi` figur telah berubah, ukuran font yang  *relatif* sama dapat diperoleh dengan mengalikan nilai `fontsize` dengan nilai `dpi` baru dan membaginya dengan 72.

### Pengaturan Margin

Untuk figur dengan banyak komponen, margin antar Axes dan margin ke ujung Figure patut diperhatikan. Secara umum nilai nominal margin diukur sebagai persentase dari ukuran figur. Nilai margin dapat diatur secara global melalui parameter `figure.subplot.{left|right|bottom|top|hspace|wspace}` di `rcParams` Matplotlib. Perlu dicatat nilai `right` dan `top` adalah batas lokasi Axes terhadap tepi Figure dan umumnya memiliki nilai mendekati 1.0 yang menyatakan ujung tepi Figure. Nilai `hspace` mengatur jarak vertikal antar Axes dalam satu Figure, sedangkan `wspace` mengatur jarak horizontal.

## GridSpec

**GridSpec** adalah objek pembantu yang dapat digunakan untuk mengatur figur dengan banyak Axes. Dibandingkan dengan penggunaan `fig.add_subplot(...)`, penggunaan GridSpec dapat memberikan fleksibilitas yang lebih dalam mengatur konfigurasi dan dimensi dari masing masing subplot. Contoh penggunaan GridSpec misalnya:

```python
from matplotlib.gridspec import GridSpec

fig = plt.figure()
gs = GridSpec(3, 3, figure=fig)
ax1 = fig.add_subplot(gs[0, :])
ax2 = fig.add_subplot(gs[1:, 0])
gs_sub = gs[1:, 1:].subgridspec(2, 2, width_ratios=[1, 2], height_ratios=[2, 1])
ax3 = fig.add_subplot(gs_sub[0, :])
ax4 = fig.add_subplot(gs_sub[1:, 0])
ax5 = fig.add_subplot(gs_sub[1:, 1:])
```

## Colorbar

Penambahan *colorbar* dan Axes-nya dapat dilakukan dengan beberapa cara. Untuk figur yang mudah direproduksi, Axes untuk *colorbar* sebaiknya dibuat secara eksplisit. Kita dapat dengan mudah mengatur ukuran dan dimensi Axes ini menggunakan GridSpec yang sudah kita bahas di [atas](#gridspec). Contoh penambahan *colorbar* yang benar sudah dapat dilihat di [sesi sebelumnya](/workshop_1/dasar_visualisasi.html).

Selain lokasi dan dimensi dari *colorbar* kita juga harus memperhatikan pemilihan skema warna untuk figur kita. Persepsi warna manusia sangat bergantung dari tingkat kecerahan warna. Skema warna pelangi yang sering kita jumpai dalam visualisasi data tiga dimensi sebenarnya dapat membuat kesalahan representasi data. Hal ini juga dapat diperburuk apabila figur tidak ditampilkan dengan seharusnya, misalnya saat dicetak secara hitam-putih.

Beberapa artikel yang dapat kalian baca untuk memahami pentingnya pilihan gradasi warna:

* [Dokumentasi dari `cmocean` (bagian dari `matplotlib`)](https://matplotlib.org/cmocean/)
* ["A Better Default Colormap for Matplotlib"](http://bids.github.io/colormap/)

Untuk pilihan opsi warna di `matplotlib` dapat dilihat [di sini](https://matplotlib.org/stable/tutorials/colors/colormaps.html).

## Penggunaan LaTeX

Kita dapat mudah menggunakan LaTeX sebagai sarana penulisan teks pada figur di Matplotlib. Untuk fitur ini, kita harus memastikan bahwa terdapat instalasi luring dari LaTeX di komputer kita:

* Windows: [MikTeX](https://miktex.org/download)
* Linux: [TeX Live](https://tug.org/texlive/)

Untuk mengaktifkan fitur ini, kita harus mengubah nilai `text.usetex` di `rcParams` menjadi `True`. Apabila instalasi berjalan dengan lancar, teks dengan format LaTeX `"$...$"` akan secara otomatis diubah menjadi persamaan. Perlu diingat bahwa tanda *backslash* `\` dalam LaTeX harus di-*escape* menjadi *double backslash* `\\` atau kita juga dapat menggunakan ***raw*** string `r"$...$"`.

Apabila kita ingin menggunakan package-package khsusus di LaTeX, kita dapat menambahkan package tersebut ke dalam `rcParams` dengan menggunakan `text.latex.preamble`.

{: .catatan }
> Kita dapat menggunakan **f-string** di Python untuk memasukkan nilai variabel ke dalam string LaTeX. Contoh:
>
> ```python
> t = 1.25368
> plt.title(rf"$t = {t:.2f}$")
> ```

## Penyimpanan Pengaturan

Pada sesi kali ini kita banyak menyebut penggunaan `rcParams` sebagai sarana
pengaturan Matplotlib. Kita dapat menyimpan berbagai jenis pengaturan `rcParams` dalam file `*.mplstyle` terpisah. Contoh file dapat dilihat di bawah ini:

```python
# Figure sizes
figure.dpi: 200
figure.subplot.left: 0.1125
figure.subplot.right: 0.975
figure.subplot.bottom: 0.1125
figure.subplot.top: 0.975
figure.subplot.hspace: 0.1
figure.subplot.wspace: 0.1

# Saving figure
savefig.dpi: 200
savefig.transparent: True

# Figure texts
text.usetex: True
# text.latex.preamble: \usepackage{xcolor}\usepackage{siunitx}

font.family: monospace

# Axes
axes.linewidth: 0.5
axes.labelsize: 8
axes.prop_cycle: cycler(color='bgrcmyk')

axes.formatter.limits: -2, 4
axes.formatter.offset_threshold: 3

# Ticks
xtick.top: True
xtick.labelsize: 7
xtick.major.size: 2.5
xtick.minor.size: 1.5
xtick.major.width: 0.5
xtick.minor.width: 0.3
xtick.direction: in
xtick.minor.visible: True

ytick.right: True
ytick.labelsize: 7
ytick.major.size: 2.5
ytick.minor.size: 1.5
ytick.major.width: 0.5
ytick.minor.width: 0.3
ytick.direction: in
ytick.minor.visible: True

# Legend
legend.edgecolor: k
legend.fancybox: False

# Animation
animation.html: html5
```

Konfigurasi ini kemudian dapat dijalankan dengan menggunakan `plt.style.use('nama_file')`.

{: .catatan }
> Untuk konfigurasi yang lebih kompleks, kalian dapat membuat file Python terpisah yang bertugas untuk mengatur `rcParams` dan melakukan pengaturan lain seperti *Ticker* atau definisi *color cycle* tertentu.
