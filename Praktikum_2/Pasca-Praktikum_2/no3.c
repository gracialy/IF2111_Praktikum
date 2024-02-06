#include <stdio.h>

int len(int x){
    int length=0;
    while(x!=0){
        x/=10;
        length++;
    }
    return length;
}

int power(int x, int len){
    int total=1;
    for(int i=0; i<len; i++){
        total *= x;
    }
    return total;
}

int main(){
    int x, y, temp, num;
    scanf("%d %d", &x, &y);

    for(int i=x; i<=y; i++){
        num = i;
        temp = 0;
        while(num > 0){
            temp += power((num%10), len(i));
            num /= 10;
        }
        if(i==temp){
            printf("%d\n", i);
        }
    }

    return 0;
}