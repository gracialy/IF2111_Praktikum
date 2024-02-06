// NIm/Nama : 18222035/Lydia Gracia
// Tanggal  : 15 September 2023
// Topik    : Pengenalan C
// Deskripsi: Program yang menjumlahkan semua digit bilangan dalam suatu integer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    int digit=0;
    while (n!=0){
        digit+=n%10;
        n=n/10;
    }

    printf("%d", digit);
    return 0;
}