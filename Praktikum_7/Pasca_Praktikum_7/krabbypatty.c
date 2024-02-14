#include "krabbypatty.h"

void krabbyPatty(Stack *ingredients, Stack *burger){
    int val;
    Stack s; CreateEmpty(&s);

    int top = 0, bot = 0;
    while (!IsEmpty(*ingredients)){
        Pop(ingredients, &val);
        if (val == 0){
            bot = 1;
        }
        else if (val==9){
            top = 1;
        }
        else{
            Push(&s, val);
        }

        if (top*bot){
            break;
        }
    }

    if (top*bot){
        Push(burger, 0);
        while (!IsEmpty(s)){
            Pop(&s, &val);
            Push(burger, val);
        }
        Push(burger, 9);
    }
}
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