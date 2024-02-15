#include "setlist.h"
#include <stdio.h>

void PrintInfo (Set L){
    address P = First(L);
    printf("[");
    while (P != Nil){
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil){
            printf(",");
        }
    }
    printf("]\n");
}

int main(){
    Set S; CreateEmpty(&S);
    printf("%d ", Count(S));
    PrintInfo(S);

    if(!IsEmpty(S)){
        printf("%d", IsMember(S, 1));
        printf("%d", IsMember(S, 2));
        printf("%d", IsMember(S, 3));
        printf("%d", IsMember(S, 10));
        printf("\n");
    }
    else{
        printf("empty\n");
    }

    Insert(&S, 2); Insert(&S, 2); Insert(&S, 3);
    Insert(&S, 4); Insert(&S, 5); Insert(&S, 6);
    
    if(!IsEmpty(S)){
        printf("%d", IsMember(S, 1));
        printf("%d", IsMember(S, 2));
        printf("%d", IsMember(S, 3));
        printf("%d", IsMember(S, 10));
        printf("\n");
    }
    else{
        printf("empty\n");
    }

    printf("%d ", Count(S));
    PrintInfo(S);

    Delete(&S, 2); 
    printf("%d ", Count(S));
    PrintInfo(S);

    Delete(&S, 4); 
    printf("%d ", Count(S));
    PrintInfo(S);

    Delete(&S, 6);
    printf("%d ", Count(S));
    PrintInfo(S);

    return 0;
}