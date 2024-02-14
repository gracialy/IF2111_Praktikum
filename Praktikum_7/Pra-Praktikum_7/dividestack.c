#include "dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    int val;
    Pop(s, &val);
    if (!IsEmpty(*s)){
        divideStack(s, oddS, evenS);
    }
    if (val%2 == 0){
        Push(evenS, val);
    }
    else{
        Push(oddS, val);
    }
}
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS: 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/

