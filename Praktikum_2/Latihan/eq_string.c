// NIm/Nama : 18222035/Lydia Gracia
// Tanggal  : 15 September 2023
// Topik    : Pengenalan C
// Deskripsi: Program yang memeriksa apakah kedua buah string memiliki panjang dan huruf yang sama

#include <stdio.h>
#include <stdlib.h>

int main(){
    char str1[100], str2[100];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    if (sizeof(str1)==sizeof(str2)){
        for (int i=0; i<sizeof(str1); i++){
            if (!(str1[i]==str2[i]) && !((abs)((int) str1[i] - (int) str2[i])==32)){
                // capital and lower ascii difference is 32
                printf("Tidak\n");
                return 0;
            }
        printf("Ya\n");
        return 0;
        }
    }
    
    printf("Tidak\n");
    return 0;
}

