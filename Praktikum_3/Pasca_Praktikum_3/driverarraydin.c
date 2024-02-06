#include "arraydin.h"
#include <stdio.h>

int main(){
    ArrayDin AD;
    AD = MakeArrayDin();
    for (int i=0; i<GetCapacity(AD); i++){
        InsertAt(&AD, i, i);
    }
    printf("%d\n", Get(AD, 0));
    printf("%d\n", Get(AD, 1));
    PrintArrayDin(AD);
    ReverseArrayDin(&AD);
    PrintArrayDin(AD);
    printf("%d\n",SearchArrayDin(AD, 2));
    InsertAt(&AD, 2, 2);
    PrintArrayDin(AD);
    printf("%d\n",SearchArrayDin(AD, 2));

    return 0;
}