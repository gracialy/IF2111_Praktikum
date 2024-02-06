// Tanggal: 8 September 2023
// Topik: Pengenalan C
// Deskripsi: Menampilkan semua average ip mahasiswa

#include <stdio.h>

int main(){
    // Kamus
    double avg;
    int ip;
    int sum_mahasiswa = 0;
    int lulus = 0;
    int tidak_lulus = 0;
    float sum_ip = 0;

    scanf("%d", &ip);

    while (ip!=(-999)){
        if (ip<=4.00 && ip>=0.00){
            sum_mahasiswa += 1;
            sum_ip += ip;
            if (ip>=2.75){
                lulus += 1;
            } else{
                tidak_lulus += 1;
            }
            
        }
        scanf("%d", &ip);
    }

    if (sum_mahasiswa==0){
        printf("Tidak ada data");
    } else {
        avg = sum_ip/sum_mahasiswa;
        printf("Banyak mahasiswa = %d\n", sum_mahasiswa);
        printf("Banyak yang lulus = %d\n", lulus);
        printf("Banyak yang tidak lulus = %d\n", tidak_lulus);
        printf("Rata-rata = %.2f\n", avg);
    }
    
    return 0;
}