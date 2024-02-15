#include "listlinier.h"
#include <stdio.h>

int main(){
    List lagu; CreateEmpty(&lagu);
    int n; scanf("%d", &n);

    while (n!=-99){
        if (Search(lagu, n) == Nil){
            InsVLast(&lagu, n);
        }
        scanf("%d", &n);
    }

    // copy
    List remaining; CreateEmpty(&remaining);
    address P = First(lagu);
    for (int i=0; i<NbElmt(lagu); i++){
        InsVLast(&remaining, Info(P));
        P = P->next;
    }
    // PrintInfo(lagu); PrintInfo(remaining); //

    // tebak
    int tebak; scanf("%d", &tebak);
    boolean found = Search(lagu, tebak) != Nil;
    while (found && NbElmt(remaining)!=0){
        if (Search(remaining, tebak) != Nil){
            DelP(&remaining, tebak);
        }
        // PrintInfo(remaining); //
        
        if (NbElmt(remaining)!=0){
            scanf("%d", &tebak);
            found = Search(lagu, tebak) != Nil;
        }
    }

    if (!found){
        printf("Poser! %d tidak ada di dalam album\n", tebak);
    }
    else{
        printf("Berhasil menebak %d lagu\n", NbElmt(lagu));
    }
    return 0;
}