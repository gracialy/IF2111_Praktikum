// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 8 September 2023
// Topik: Pengenalan C
// Deskripsi: Menampilkan hasil a pangkat b

#include <stdio.h>
#include <math.h>

int main(){
    // Kamus
    // float
    double a, b;

    // Algoritma
    scanf("%lf", &a); // scanf("%<type>", &<var>);
    scanf("%lf", &b);

    double result = pow(a,b);
    printf("%.2lf\n", result);

    // integer
    int c, d;

    // Algoritma
    scanf("%d", &c); // scanf("%<type>", &<var>);
    scanf("%d", &d);

    int result_d;
    result_d = (int)(pow(c, d)); // typecast (int) or (round)
    printf("%d", result_d);

    return 0;
}