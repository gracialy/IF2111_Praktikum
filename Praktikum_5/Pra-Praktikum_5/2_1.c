#include <stdio.h>
#include "mesinkarakter.h"

int main(){
    char input;
    scanf("%c", &input);
    int count = 0;
    START();
    while (!IsEOP()){  
        printf("LOOP");  
        if ((GetCC() == 'a' || GetCC() == 'e' || GetCC() == 'i' || GetCC() == 'o' || GetCC() == 'u') && (GetCC() != input)){
            printf("%c", GetCC());
            count ++;
        }
        ADV();
    }
    if (count == 0){
        printf("0\n");
    }
    else{
        printf(" %d\n", count);
    }
    return 0;
}