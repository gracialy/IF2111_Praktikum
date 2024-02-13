#include "mesinkarakter.h"

#ifndef LARI_H
#define LARI_H


void Running();
/*
Fungsi ini untuk menjalankan lari. Dalam fungsi ini akan menerima input energy dan menerima bentuk track.

Setelah mendapatkan track, dilakukan pengecekan tiap current character dan melakukan sesuai dengan instruksi hingga kondisi berahkir.

Ketika berakhir keluarkan output "FINISH" bila berhasil dan "FAIL" bila gagal. Selain itu keluarkan juga sisa ENERGY. "ENERGY 0"

Contoh output:
FAIL
ENERGY -1

NOTE:
1. Kondisi berakhir adalah:
  - Pelari sampai ke garis finish (current character berada di '.' atau EOP )
  - Pelari tidak bisa melewati BLOCK (energy = -1)
  - Pelari kehabisan energy
*/

void IsBlock(char currentChar);
/*
Fungsi mengecek apakah current character '#'.
Apabila iya maka:
1. Jika memiliki skill PUNCH:
  - dapat melewati block dengan memukulnya
  - skill punch digunakan sehingga sudah tidak memiliki skill punch
  - energy berkurang 1
2. Jika tidak, energy menjadi -1.
*/

void IsPunch(char currentChar);
/*
Fungsi mengecek apakah current character '@'.
Apabila iya maka:
1. mendapatkan skill punch
2. energy berkurang 1

NOTE:
PUNCH tidak stack.
*/

void IsPokari(char currentChar);
/*
Fungsi mengecek apakah current character '>'.
Jika iya, maka menambahkan energy 1.


CONTOH 1:
ENERGY 2
TRACK ->-.

EXPLAIN:
1. - Energy berkurang 1, current energy 1
2. > Energy bertambah 1, current energy 2
3. - Energy berkurang 1, current energy 1
4. . Energy berkurang 1, current energy 0


CONTOH 2:
ENERGY 2
TRACK ->>-.

EXPLAIN:
1. - Energy berkurang 1, current energy 1
2. > Energy bertambah 1, current energy 2
3. > Energy bertambah 1, current energy 3
4. - Energy berkurang 1, current energy 2
5. . Energy berkurang 1, current energy 1
*/


void IsPath(char currentChar);
/*
Fungsi mengecek apakah current character '-'
Jikya iya maka:
1. energy berkurang 1.
*/


#endif