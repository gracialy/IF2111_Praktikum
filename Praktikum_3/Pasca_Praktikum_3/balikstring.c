#include "balikstring.h"
#include <string.h>

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch){
    int i=-1;

    while (*ch!='\0'){
        // printf("%c\n", *cc);
        ch++;
        i++;
    }
    return i+1;
}

// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str){
    int len = panjangString(str);
    char temp;

    for (int i=0; i<len/2; i++){
        temp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=temp;
    }
}