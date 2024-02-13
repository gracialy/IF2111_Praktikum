#include "mesinkarakter.h"
#include "hitungfrekuensi.h"
#include <stdio.h>

int hitungfrekuensi(){
    START();
    boolean ist = false;
    boolean isi = false;
    boolean isg = false;
    boolean isa = false;
    int count = 0;
    while (! IsEOP()){
        if (GetCC()=='t' || GetCC()=='T'){
            ist = true;
        }
        else if (ist==true & (GetCC()=='i' || GetCC()=='I')){
            isi = true;
        }
        else if (isi==true & (GetCC()=='g' || GetCC()=='G')){
            isg = true;
        }
        else if (isg==true & (GetCC()=='a' || GetCC()=='A')){
            isa = true;
        }
        else{
            ist = false; isi = false; isg = false; isa = false;
        }

        if (ist==true && isi==true && isg==true && isa==true){
            count+=1;
        }
        ADV();
    }
    
    return count;
}