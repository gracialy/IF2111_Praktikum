// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 19 September 2023
// Topik: ADT, Pointer, dan Array Dinamik
// Deskripsi: Implementasi panjangString.h

#include <stdio.h>
#include "panjangstring.h"

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int panjangString(char* str){
    int i=-1;
    char* cc=str;

    while (*cc!='\0'){
        // printf("%c\n", *cc);
        cc++;
        i++;
    }
    return i+1;
}