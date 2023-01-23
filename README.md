# Tucil1_13521144
> Tugas Kecil 1 IF2211 - Strategi Algoritma menugaskan mahasiswa untuk membuat sebuah program sederhana untuk mencari solusi dari permainan klasik 24 dengan algoritma bruteforce. Permainan 24 sendiri adalah permainan yang memainkan empat buah kartu yang kemudian nilai dari kartu tersebut akan dilaksanakan operasi penjumlahan, pengurangan, perkalian, atau pembagian untuk menghasilkan angka 24 dari keempat kartu tersebut.

## Struktur Folder
- `bin` berisikan executable file (.exe karena dikompilasi pada os windows)
- `doc` berisikan laporan tugas kecil
- `src` berisikan source code dari program dalam bahasa c++
- `test` berisikan hasil output dari pengujian program sesuai dengan pengujian pada laporan

## Program Environment
- MINGW64_NT-10.0-22621 version 3.3.6-341.x86_64
- MSYS_NT-10.0-22621 version 3.3.6-341.x86_64
- gcc version 11.3.0

## Cara Mengompilasi Program
1. Arahkan terminal pada direktori utama
2. Jalankan perintah `g++ -o main src/main.cpp src/ioHandler.cpp src/solver.cpp`

## Cara Menjalankan Program
1. Arahkan terminal pada direktori yang terdapat file hasil kompilasi program (contoh: folder bin yang memiliki file main.exe)
2. Jalankan perintah `./main`

## Cara Menggunakan
1. Pertama pengguna akan ditanya apakah ingin memasukkan kartu atau diambil kartu secara acak oleh program
2. Pengguna memasukkan `user` bila ingin memasukkan kartu secara manual
3. Pengguna memasukkan `random` bila ingin kartu diambil secara acak oleh program
4. Apabila pengguna ingin memasukkan kartu secara manual, maka pengguna memasukkan empat kartu yang dipisahkan dengan spasi, contoh: `A J 10 K` (perlu diperhatikan masukan menggunakan simbol kartu bukan nilai kartu)
5. Kemudian pengguna akan ditanya apakah ingin menyimpan solusi yang didapatkan dari empat kartu yang dimainkan
6. Pengguna memasukkan `y` atau `Y` bila ingin menyimpannya dalam suatu file (nama file akan ditanyakan nanti)
7. Pengguna memasukkan `n` atau `N` bila tidak ingin menyimpannya dalam suatu file

## Kontributor
1. [13521144 - Bintang Dwi Marthen](https://github.com/Marthenn)
