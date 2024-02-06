// Topik: Pengenalan C
// Deskripsi: Menampilkan bilangan armstrong

#include <stdio.h>

int Digit (int n);
int Power (int x, int y);
int isArmstrong (int n);

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    for (x; x<=y; x++){
        if (isArmstrong(x)==1){
            printf("%d\n", x);
        }
    }

    //printf("%d\n", isArmstrong(70));
    return 0;
}

int isArmstrong (int n){
    int temp = n;
    int sum = 0;

    while (temp!=0){
        sum = sum + Power(temp%10, Digit(n));
        temp=temp/10;
    }

    if (sum==n){
        return 1;
    }
    return 0;
}

int Digit (int n){
    int digit=0;

    if (n==0){
        return 1;
    }

    while (n!=0){
        digit+=1;
        n=n/10;
    }
    return digit;
}

int Power (int x, int y){
    int power=x;
    int ori=x;

    for (int i=2; i<=y; i++){
        power = power*ori;
    }
    return power;
}