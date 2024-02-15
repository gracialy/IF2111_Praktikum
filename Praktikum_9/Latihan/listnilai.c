#include "listlinier.h"
#include <stdio.h>

int CopyList(List L1, List *L2){
    address P = First(L1);
    while (P != Nil){
        InsVLast(L2, Info(P));
        P = Next(P);
    }
}

int main(){
    List nilai; CreateEmpty(&nilai);
    int x; scanf("%d", &x);

    while (x>=0 && x<=100){
        InsVFirst(&nilai, x);
        scanf("%d", &x);
    }

    if (IsEmpty(nilai)){
        printf("Daftar nilai kosong\n");
    }
    else{
        printf("%d\n", NbElmt(nilai));
        printf("%d\n", Max(nilai));
        printf("%d\n", Min(nilai));
        printf("%.2f\n", Average(nilai));
        List reverse; CreateEmpty(&reverse);
        CopyList(nilai, &reverse);
        InversList(&reverse);
        PrintInfo(reverse);
        PrintInfo(nilai);
    }
}