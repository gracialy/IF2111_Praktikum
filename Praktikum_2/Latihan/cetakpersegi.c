// NIm/Nama : 18222035/Lydia Gracia
// Tanggal  : 15 September 2023
// Topik    : Pengenalan C
// Deskripsi: Program yang mencetak sebuah persegi berdasarkan masukkan n, dimana panjang dari sisi persegi adalah 2n-1 dan dibentuk dengan pola O dan X secara selang-seling

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    for (int i=0; i<(2*n+1); i++){
        for (int j=0; j<(2*n+1); j++){
            if (i%2==0){
                if (j%2==1){
                    printf("X");
                }
                else {
                    printf("O");
                }
            }
            else {
                if (j%2==1){
                    printf("O");
                }
                else {
                    printf("X");
                }
            }
        }
        printf("\n");
    }
    return 0;
}