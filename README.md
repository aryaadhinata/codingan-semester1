# DasPro_KOMC3

Kumpulan latihan dan tugas mata kuliah Dasar-Dasar Pemrograman (DasPro) yang ditulis terutama dalam bahasa C. Repository ini berisi latihan harian, tugas praktikum, dan solusi latihan terstruktur.

## Struktur Repository

### Latihan harian

Folder `dasPro/day1` sampai `dasPro/day9` berisi program latihan per pertemuan. Topiknya mencakup dasar pemrograman C, percabangan dan perulangan, array dan string, fungsi/prosedur, rekursi, pengurutan dan pencarian, serta pengolahan arsip dan mesin karakter/kata.

Contoh materi yang tersedia:

- `day1`-`day2`: operasi dasar, kondisi, perulangan, dan latihan soal.
- `day3`-`day4`: array, string, struktur data sederhana, dan perulangan.
- `day5`: fungsi, prosedur, parameter referensi, dan rekursi.
- `day6`-`day7`: algoritma pengurutan, pencarian, dan tabel.
- `day8`-`day9`: pengolahan arsip serta mesin abstrak karakter dan kata.

### Tugas `compro`

Folder `dasPro/comproD1` sampai `dasPro/comproD9` berisi tugas dan latihan lanjutan. Isinya mencakup program C, berkas header pendukung, dan beberapa arsip tugas.

## Teknologi dan Berkas

- Program ditulis dalam bahasa C; berkas sumber umumnya berekstensi `.c` atau `.C`.
- Berkas header berekstensi `.h` digunakan untuk deklarasi dan komponen bersama.
- Beberapa latihan menggunakan berkas data teks atau arsip pendukung.
- Hasil kompilasi seperti `.exe`, `.o`, dan keluaran build lainnya tidak disimpan di Git; lihat aturan di [`dasPro/.gitignore`](dasPro/.gitignore).

## Menjalankan Program

Kompilasi file sumber yang ingin dijalankan menggunakan compiler C yang tersedia di sistem. Contoh dengan GCC:

```sh
gcc dasPro/day6/bubleSort.c -o bubleSort
./bubleSort
```

Untuk program yang terdiri dari beberapa file sumber atau menggunakan header, sertakan file-file terkait dalam perintah kompilasi. Beberapa program juga memerlukan berkas data yang berada di folder tugasnya, jadi jalankan dari folder yang sesuai.
