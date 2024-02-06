// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 10 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: Menentukan apakah suatu bilangan merupakan bilangan cantik

#include <stdio.h>

void bil_cantik(int a, int b);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    bil_cantik(a,b);

    return 0;
}

void bil_cantik(int a, int b){
    ((a+b)%4==0 || (a*b)%4==0) ? printf("Y\n") : printf("N\n");
}