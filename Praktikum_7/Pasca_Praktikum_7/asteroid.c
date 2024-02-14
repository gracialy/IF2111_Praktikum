#include "asteroid.h"
#include <stdlib.h>
#include <stdio.h>

boolean isCollision(infotype a, infotype b){
    return (a>0 && b<0);
}
/* Mengirim true jika terjadi tabrakan */
/* yaitu ketika a > 0 dan b < 0 */

void collision(int n, infotype *asteroids, Stack *remaining){
    int val;

    Push(remaining, asteroids[0]);

    for (int i=1; i<n; i++){
        // printf("evaluate %d\n", asteroids[i]);
        if (!isCollision(InfoTop(*remaining), asteroids[i])){
            Push(remaining, asteroids[i]);
        }
        else{
            int push = 0;
            while(isCollision(InfoTop(*remaining), asteroids[i]) && !IsEmpty(*remaining)){
                if (abs(InfoTop(*remaining)) > abs(asteroids[i])){
                    break;
                }
                else if (abs(InfoTop(*remaining)) < abs(asteroids[i])){
                    Pop(remaining, &val);
                    push = 1;
                }
                else{
                    Pop(remaining, &val);
                    break;
                }
            }
            if (push){
                Push(remaining, asteroids[i]);
            }
        }
        // displayAsteroids(*remaining);
    }
}
/* Proses: Mengisi stack dengan asteroid yang tersisa setelah tabrakan. 
    Asteroid dengan ukuran lebih besar tidak akan hancur, dan apabila kedua asteroid ukurannya sama maka 
    akan sama-sama hancur.  */
/* I.S Array asteroids pasti terisi dengan elemen positif atau negatif, Stack remaining telah terbentuk */
/* F.S Stack remaining terisi oleh sisa asteroid yang tidak hancur */
/*
   Contoh simulasi:
   - Input: [5,10,-5]
     Output: [5,10]
     Penjelasan: 5(->) 10(->) -5(<-) Asteroid 5 dan 10 bergerak ke kanan, -5 ke kiri. Asteroid 10 lebih besar dari -5, sehingga -5 hancur.

   - Input: [-10,10]
     Output: [-10,10]
     Penjelasan: -10(<-) 10(->) Kedua asteroid bergerak ke arah berbeda dan tidak bertemu, jadi tidak ada yang hancur.

   - Input: [1,-2,10,5]
     Output: [-2,10,5]
     Penjelasan: 1(->) -2(<-) akan bertabrakan, namun asteroid -2 lebih besar sehingga asteroid 1 hancur. Lalu, -2(<-) 10(->) tidak akan bertabrakan. 5 tetap melaju karena bergerak ke arah yang sama.
*/

void displayAsteroids(Stack S){
    if (IsEmpty(S)){
        printf("[]\n");
    }
    else{
        Stack copy;
        CreateEmpty(&copy);

        int val;
        while (!IsEmpty(S)){
            Pop(&S, &val);
            Push(&copy, val);
        } // copy berisi reverse S, S kosong

        Pop(&copy, &val);
        Push(&S, val);
        printf("[%d", val);

        while (!IsEmpty(copy)){
            Pop(&copy, &val);
            Push(&S, val);
            printf(",%d", val);
        } // S berisi reverse S
        printf("]\n");
    }
}
/* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
/* Jika Stack kosong : menulis [] */
/* Terdapat new line setelah kurung tutup */
/* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */