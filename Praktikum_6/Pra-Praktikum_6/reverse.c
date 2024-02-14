#include "circular_queue.h"
#include "reverse.h"
#include <stdio.h>

void transferReverse(Queue* q1, Queue* q2){
    // transfer q1 to q2
    int i=Length(*q1);
    while (i>0){
        enqueue(q2, dequeue(q1));
        i--;
    }

    ElType temp;
    int ihead=0;
    int itail=Length(*q2)-1;
    while (ihead<itail){
        temp = q2->Tab[ihead];
        q2->Tab[ihead] = q2->Tab[itail];
        q2->Tab[itail] = temp;
        
        ihead++; itail--;
    }
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik



