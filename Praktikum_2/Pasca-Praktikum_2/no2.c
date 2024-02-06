#include <stdio.h>
//1a 1b 2c 3d 5e 8a 13b 21c 34d 55e  
int main(){
    int n, total=0;
    long int fib=0, fib2=1, fib3=1;

    scanf("%d", &n);
    if(n<=0 || n>50){
        printf("%d\n", -1);
        return 0;
    }

    for(int i=0; i<n-2; i++){
        fib = fib2+fib3;
        fib3 = fib2;
        fib2 = fib;
        if(fib%2 == 0){
            total += fib;
        }
    }
    printf("%d\n",total);
    return 0;
}
