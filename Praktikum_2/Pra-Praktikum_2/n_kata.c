// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 2023
// Topik: Pengenalan C
// Deskripsi: Menghitung banyak kata dari kalimat yang dipisahkan oleh spasi

#include <stdio.h>
#include <string.h>

int main(){
    char kalimat[100];
    
    fgets(kalimat, 100, stdin);
    // scanf("%[^\n]s", &kalimat);

    int kata=1;
    for (int i=0; i<strlen(kalimat); i++){
        if (kalimat[i]==' '){
            kata++;
        }
    }

    printf("%d\n", kata);
    return 0;
}

// 1: 0 --> missing new line as termination
// 2: 0 --> missing new line as termination