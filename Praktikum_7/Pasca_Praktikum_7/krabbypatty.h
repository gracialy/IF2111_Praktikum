#ifndef KRABBY_PATTY_H
#define KRABBY_PATTY_H

#include "stack.h"

void krabbyPatty(Stack *ingredients, Stack *burger);
/*
Membuat satu Krabby Patty dari tumpukan bahan

~ CONTOH 1 ~
Awal:
ingredients -> [7, 1, 9, 2, 3, 4, 3, 0, 1, 2]
burger -> []

Akhir:
ingredients -> [7, 1]
burger -> [0, 2, 3, 4, 3, 1, 2, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- keju
- patty
- selada
- bawang
- selada
- keju
- roti bawah

Sisa bahan di tumpukan bahan:
- patty
- saus

~ CONTOH 2 ~
Awal:
ingredients -> [0, 2, 9, 3, 4, 3, 7, 0, 9, 9]
burger -> []

Akhir:
ingredients -> [0, 2, 9, 3, 4, 3, 7]
burger -> [0, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- roti bawah

Sisa bahan di tumpukan bahan:
- saus
- selada
- bawang
- selada
- roti atas
- keju
- roti bawah

~ CONTOH 3 ~
Awal:
ingredients -> [1, 3, 8, 5, 7, 9]
burger -> []

Akhir:
ingredients -> []
burger -> []

Terjemahan:
Krabby Patty tidak dapat dibuat

Tidak ada bahan tersisa di tumpukan bahan
*/

#endif