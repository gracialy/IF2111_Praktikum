// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 10 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: Membuat ketupat dengan panjang sisi miring n

#include <stdio.h>

void belah_ketupat(int n);
void space();
void star();

int main(){
    int n;
    scanf("%d", &n);

    belah_ketupat(n);
    return 0;
}

void belah_ketupat(int n){
    for (int i=0; i<n; i++){
        // space
        for (int j=0; j<(n-i-1); j++){
            space();
        }

        // star
        for (int k=0; k<(2*i+1); k++){
            star();
        }
        printf("\n");
    }

    for (int i=(n-1); i>=0; i--){
        // space
        for (int j=0; j<(n-i-1); j++){
            space();
        }

        // star
        for (int k=0; k<(2*i+1); k++){
            star();
        }
        printf("\n");
    }
}

void space(){
    printf(" ");
}

void star(){
    printf("*");
}