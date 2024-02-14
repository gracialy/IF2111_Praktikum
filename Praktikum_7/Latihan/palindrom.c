#include "stack.h"
#include <stdio.h>

int main(){
    Stack s1, temp, s2;
    CreateEmpty(&s1);
    CreateEmpty(&temp);
    CreateEmpty(&s2);
    
    int val;
    scanf("%d", &val);

    if (val==0){
        printf("Stack kosong\n");
    }
    else{
        do{
            Push(&s1, val);
            Push(&temp, val);
            scanf("%d", &val);
        } while (val!=0);

        // make an inverse of the input sequence
        while(!IsEmpty(temp)){
            Pop(&temp, &val);
            Push(&s2, val);
        }

        // compare s1 with its inverse s2
        boolean diff = false;
        while(!IsEmpty(s1) && !diff){
            if (s1.T[s1.TOP]!=s2.T[s2.TOP]){
                diff = true;
            }
            Pop(&s1, &val);
            Pop(&s2, &val);
        }

        if (diff){
            printf("Bukan Palindrom\n");
        }
        else{
            printf("Palindrom\n");
        }
    }
    return 0;
}