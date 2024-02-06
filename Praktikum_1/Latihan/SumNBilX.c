// Tanggal: 8 September 2023
// Topik: Pengenalan C
// Deskripsi: Mengonversi notasi algortmik dalam bahasa C

#include <stdio.h>

int main(){
    // Kamus
    int i = 1;
    int sum = 0;
    int x;

    scanf("%d", &x);
    while(x!=9999){
        sum += x;
        i += 1;
        scanf("%d", &x);
    }
    
    printf("Jumlah: %d\n", sum);
    printf("Banyak bilangan: %d\n", i-1);
    return 0;
}