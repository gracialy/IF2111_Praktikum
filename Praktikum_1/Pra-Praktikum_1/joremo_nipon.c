// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 6 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: mengalikan digit-digit bukan 0 dan memberi banyak digit bukan 0 pada hasil perkalian

#include <stdio.h>

int main()
{
    // bilangan bulat positif
    // Input
    long int n;
    scanf("%ld", &n);

    long int kali=1;
    while(n>0){
        if (n%10!=0){
            kali = kali * (n%10);
        }
        n = n/10;
    }

    long int hitung_digit=kali;
    long int banyak=0;
    while(hitung_digit>0){
        if (hitung_digit%10!=0){
            banyak = banyak + 1;
        }
        hitung_digit = hitung_digit/10;
    }

    // Output
    printf("%ld %ld\n", kali, banyak);
    return 0;
}