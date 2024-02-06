#include <stdio.h>

int isPrime(int a);
int isPalindrom(int a);

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

int main(){
    printf("%d", isPalindrom(2));
    return 0;
}