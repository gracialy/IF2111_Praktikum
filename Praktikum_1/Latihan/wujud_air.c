// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 8 September 2023
// Topik: Pengenalan C
// Deskripsi: Menampilkan wujud air berdasarkan suhu

#include <stdio.h>

int main(){
    // Kamus
    int suhu;

    // Input
    scanf("%d", &suhu);

    // Algoritma
    if (suhu<0){
        printf("PADAT\n");
    } else if (suhu==0){ // logic checker equals: ==
        printf("PADAT-CAIR\n");
    } else if (suhu>0 && suhu<100){
        printf("CAIR\n");
    } else if (suhu==100){
        printf("CAIR-GAS\n");
    } else {
        printf("GAS\n");
    }

    return 0;
}