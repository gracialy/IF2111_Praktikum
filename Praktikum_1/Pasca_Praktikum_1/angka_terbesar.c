// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 10 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: mencari bilangan terbesar diantara tiga input angka

#include <stdio.h>

int biggest(int a, int b, int c);

int main(){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, biggest(a, b, c));

    return 0;
}

int biggest(int a, int b, int c){
    if (a>=b && a>=c) {
        return a;
    } else if (b>=c && b>=a) {
        return b;
    } else {
        return c;
    }
}