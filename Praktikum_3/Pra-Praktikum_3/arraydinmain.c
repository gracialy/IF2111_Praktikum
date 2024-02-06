#include <stdio.h>
#include "arraydin.h"

int main(){
    ArrayDin arr;
    arr=MakeArrayDin();
    if (IsEmpty(arr)){
        printf("- status neff/capacity abis malloc=%d/%d\n", Length(arr), GetCapacity(arr));
    }
    printf("- selanjutnya dilakukan insert at idx 1, 2, dan 4\n");
    InsertAt(&arr, 1, 1);
    InsertAt(&arr, 2, 2);
    InsertAt(&arr, 4, 4);
    printf("- status neff/capacity sekarang=%d/%d\n", Length(arr), GetCapacity(arr));
    printf("{%d %d %d %d %d}\n", Get(arr, 0), Get(arr, 1), Get(arr, 2), Get(arr, 3), Get(arr, 4));
    printf("- rn nilai %d at idx=3 is garbage values bc we never assign a real value to it\n", Get(arr, 3));
    printf("- secara lojik, nilai ke-3 harusnya %d pada idx=4 (karena urutan ke-3 dari yg udah di-assign)\n", Get(arr, 4));
    printf("tapi pas kita Get(array, 3) yang diprint nilai pada index fisik\n");
    DeleteAt(&arr, 2);
    printf("%d %d %d %d %d\n", Get(arr, 0), Get(arr, 1), Get(arr, 2), Get(arr, 3), Get(arr, 4));
    printf("%d/%d\n", Length(arr), GetCapacity(arr));
    DeallocateArrayDin(&arr);
    return 0;
}