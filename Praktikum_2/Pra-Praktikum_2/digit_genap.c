// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 2023
// Topik: Pengenalan C
// Deskripsi: Menghitung banyak angka yang memiliki BANYAK digit genap

#include <stdio.h>

int banyak_digit(int num);

int main(){
    int n;
    scanf("%d", &n);

    int banyak=0;
    int num;
    for (int i=0; i<n; i++){
        scanf("%d", &num);

        if (banyak_digit(num)%2==0){
            banyak ++;
        }
    }

    printf("%d\n", banyak);
    return 0;
}

int banyak_digit(int num){
    int digit=0;

    while (num!=0){
        digit ++;
        num = num/10;
    }

    return digit;
}