#include "dividestack.h"
#include <stdio.h>

int main(){
    Stack s1;
    Stack s2;
    Stack s;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&s);

    int i=0;

    s.T[0] = 11;
    s.T[1] = 22;
    s.T[2] = 31;
    s.T[3] = 41;
    s.TOP  = 3;

    while(i <= s.TOP){
        printf("%d,", s.T[i]);
        i++;
    }
    printf("\n");

    divideStack(&s, &s1, &s2);

    i=0;
    while(i <= s1.TOP){
        printf("%d,", s1.T[i]);
        i++;
    }
    printf("\n");

    i=0;
    while(i <= s2.TOP){
        printf("%d,", s2.T[i]);
        i++;
    }
}