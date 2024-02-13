#ifndef REPEAT_ELEM
#define REPEAT_ELEM

#include "list.h"

/*
Fungsi RepeatElem menerima satu buah argumen, yaitu sebuah pointer ke list L yang akan diperiksa bila ada anggotanya yang berulang.
Fungsi ini akan menghapus setiap pengulangan anggota yang sama pada L (jika ada) dan akan mengembalikan sebuah list baru L2 yang berisi
setiap anggota yang berulang tersebut (jika ada).
Jika ada anggota yang berulang lebih dari satu kali pada L, maka cukup isikan anggota tersebut satu kali saja ke L2 sehingga tidak ada
anggota yang berulang pada L2
*/
List RepeatElem(List *L);

#endif