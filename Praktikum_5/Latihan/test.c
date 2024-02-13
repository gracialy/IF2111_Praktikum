#include <stdio.h>
#include "mesinkarakter.h"

int main(){
    printf("START\n");
    START();
    printf("=====\n");
    boolean ist = false;
    boolean isi = false;
    boolean isg = false;
    boolean isa = false;
    int count = 0;
    printf("%c\n", GetCC());
    while (! IsEOP()){
        printf("LOOP\n");
        if (GetCC()=='t' || GetCC()=='T'){
            ist = true;
            printf("check %c = %d\n", GetCC(), ist);
        }
        else if (ist==true & (GetCC()=='i' || GetCC()=='I')){
            isi = true;
            printf("check %c = %d %d\n", GetCC(), ist, isi);
        }
        else if (isi==true & (GetCC()=='g' || GetCC()=='G')){
            isg = true;
            printf("check %c = %d %d %d\n", GetCC(), ist, isi, isg);
        }
        else if (isg==true & (GetCC()=='a' || GetCC()=='A')){
            isa = true;
            printf("check %c = %d %d %d %d\n", GetCC(), ist, isi, isg, isa);
        }
        else{
            ist = false; isi = false; isg = false; isa = false;
            printf("check %c = %d %d %d %d\n", GetCC(), ist, isi, isg, isa);
        }

        if (ist==true && isi==true && isg==true && isa==true){
            count+=1;
        }
        ADV();
    }
    printf("%d\n", count);
}