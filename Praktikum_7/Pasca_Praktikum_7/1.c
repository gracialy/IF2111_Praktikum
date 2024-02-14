#include "stack.h"
#include <stdio.h>

int main(){
    int n; scanf("%d", &n);

    char lagu[n][20];
    for (int i = 0; i < n; i++){
        scanf("%s", lagu[i]); // lagu tidak mengandung whitespace
    }

    int x; scanf("%d", &x);

    Stack S; CreateEmpty(&S);

    for (int i=0; i<x; i++){
        int op; scanf("%d", &op);
        if(op==1){
            int idx; scanf("%d", &idx);
            Push(&S, idx);
            printf("Playing: %s\n", lagu[idx]);
        } 
        else if (op==2){
            if(IsEmpty(S)){
                printf("No music is played\n");
            }
            else{
                int val; Pop(&S, &val);
                if(IsEmpty(S)){
                    printf("No music is played\n");
                }
                else{
                    printf("Playing: %s\n", lagu[Top(S)]);
                }
            }
        }
    }
    
    return 0;
}