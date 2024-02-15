#include <stdio.h>
#include "listsirkuler.h"

int elemenken(List L, int n){
    if (IsEmpty(L)){
        printf("List kosong\n");
    }
    else{
        int i=0; address P = First(L);
        while (i<n){
            P = Next(P);
            i++;
        }
        printf("%d\n", Info(P));
    }
}

int main(){
    List L; CreateEmpty(&L);
    int X;
    do{
        scanf("%d", &X);
        if (X != 0){
            InsVLast(&L, X);
        }
    } while (X != 0);
    int n; scanf("%d", &n);
    elemenken(L, n);
}