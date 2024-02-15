#include <stdio.h>
#include "listsirkuler.h"

int SumList(List L){
    int sum = 0;
    if (!IsEmpty(L)){
        address P = First(L);
        do{
            sum += Info(P);
            P = Next(P);
        } while (P != First(L));
    }
    return sum;
}

int NbElmt(List L){
    int count = 0;
    if (!IsEmpty(L)){
        address P = First(L);
        do{
            count ++;
            P = Next(P);
        } while (P != First(L));
    }
    return count;
}

int main(){
    List L; CreateEmpty(&L);

    int TQ; scanf("%d", &TQ);
    while (TQ<=0){
        scanf("\n%d", &TQ);
    }

    char op; scanf("\n%c", &op); // if input is in newline
    while (op != 'F'){
        if (op == 'A'){
           int TA; scanf("%d", &TA);
           InsVFirst(&L, TA);
        }
        else if (op == 'D'){
            if (IsEmpty(L)){
                printf("List kosong\n");
            }
            else{
                int process;
                DelVLast(&L, &process);
                if (process > TQ){
                    printf("%d\n", TQ);
                    InsVFirst(&L, process - TQ);
                }
                else{
                    printf("%d\n", process);
                }
            }
        }
        else{
            printf("Kode salah\n");
        }

        scanf("\n%c", &op); // \n
    }

    if (IsEmpty(L)){
        printf("Proses selesai\n");
    }
    else{
        printf("%.2f\n", (float) SumList(L)/NbElmt(L)); // casting
    }
    return 0;
}