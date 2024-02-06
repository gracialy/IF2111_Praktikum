// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 6 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: menerima inputan bilangan bulat positif n dan menampilkan n baris bilangan bulat dari 1 sampai n

#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    int i=1;
    while(i<=n){
        if (i%3==0 && i%5==0){
            printf("RilNyata\n");
        }
        else if (i%3==0){
            printf("Nyata\n");
        }
        else if (i%5==0){
            printf("Ril\n");
        }
        else {printf("%i\n", i);}
        i++;
    }
    return 0;
}