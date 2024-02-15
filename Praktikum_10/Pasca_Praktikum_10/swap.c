#include "swap.h"
#include <stdio.h>

address AddressAtIndex(List L, infotype x){
    int i = 1;
    address P = First(L);
    while (i<x){
        P = Next(P);
        i++;
    }
    // printf("%d: %d\n", i, Info(P)); //
    return P;
}
/* 
Mencari address suatu node pada element ke- X
*/
void Swap(List *L1){
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (b<a){
        int temp = b;
        b = a;
        a = temp;
    }

    address P = AddressAtIndex(*L1, a);
    address Q = AddressAtIndex(*L1, b);

    address prevP = Prev(P);
    address nextP = Next(P);
    address prevQ = Prev(Q);
    address nextQ = Next(Q);
    // printf("%d Prev:%d Next: %d\n", Info(P), Info(prevP), Info(nextP)); //
    // printf("%d Prev:%d Next: %d\n", Info(Q), Info(prevQ), Info(nextQ)); //

    if (b-a != 1){
        Next(prevP) = Q;
        Prev(nextP) = Q;
        Prev(P) = prevQ;
        Next(P) = nextQ;

        Next(prevQ) = P;
        Prev(nextQ) = P;
        Prev(Q) = prevP;
        Next(Q) = nextP;
    }
    else{
        Next(prevP) = Q;
        Prev(nextQ) = P;

        Prev(P) = Nil; Prev(Q) = Nil;
        Next(P) = Nil; Next(Q) = Nil;

        Prev(P) = Q; Prev(Q) = prevP;
        Next(P) = nextQ; Next(Q) = P;

        // int dummy = Info(P);
        // Info(P) = Info(Q);
        // Info(Q) = dummy;
    }
}
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/