#include "listlinier.h"
#include <stdio.h>

int main(){
    List cache; CreateEmpty(&cache);

    int N; scanf("%d", &N);
    int Q; scanf("%d", &Q);

    for (int i=1; i<=N; i++){
        InsVLast(&cache, i);
    }

    for (int i=1; i<=Q; i++){
        int x; scanf("%d", &x);
        if (Search(cache, x)==Nil){
            printf("miss ");
            int del; DelVLast(&cache, &del);
        }
        else{
            printf("hit ");
            DelP(&cache, x);
        }
        InsVFirst(&cache, x);
        PrintInfo(cache);
    }
    return 0;
}