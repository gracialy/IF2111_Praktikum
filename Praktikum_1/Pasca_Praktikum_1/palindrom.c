// NIM/Nama: 18222035/Lydia Gracia
// Tanggal: 10 September 2023
// Topik Praktikum: Pengenalan C
// Deskripsi: Menentukan apakah suatu bilangan palindrom

#include <stdio.h>

// palindrom prima: bilangan prima, dibalik tetap dibaca sama

int isPrime(int a);
int isPalindrom(int a);

int main(){
    int n;
    scanf("%d", &n);

    int count=0;
    int num=1;
    while (count!=n){
        num+=1;
        if (isPrime(num) && isPalindrom(num)){
            count+=1;
        }
        // printf("n=%d, num=%d, count=%d\n", n, num, count);
    }

    printf("%d\n", num);
    
    return 0;
}

int isPrime(int a){
    int i=2;
    int loopbreak=0;

    while (i<a && loopbreak!=1){
        if (a%i==0){
            loopbreak+=1;
        }
        i+=1;
    }

    if (loopbreak==1){
        return 0;
    } else {
        return 1;
    }
}

int isPalindrom(int a){
    int temp=a;
    int reverse=0;

    while (temp!=0){
        reverse = (reverse*10)+(temp%10);
        temp = temp/10;
    }

    if (a==reverse){
        return 1;
    } else {
        return 0;
    }
}

// 1: 0