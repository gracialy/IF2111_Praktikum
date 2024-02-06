// Topik: Pengenalan C
// Deskripsi: Menampilkan hasil penjumlahan semua suku barisan Fibonacci yang bernilai genap

#include <stdio.h>

int fib_genap(int n);

int main(){
    int n;
    scanf("%d/n", &n);
    printf("%d\n", fib_genap(n));

    return 0;
}

int fib_genap(int n){
    int first=1;
    int sec=1;
    int next, sum=0;

    if (n<1 || n>50){
        return (-1);
    }

    for (int i=3; i<=n; i++){
        next = first+sec;
        
        if (next%2==0){
            sum += next;
        }

        first=sec;
        sec=next;
    }

    return sum;
}