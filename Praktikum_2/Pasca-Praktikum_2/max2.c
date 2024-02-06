#include <stdio.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d\n", &n);

    int max=INT_MIN, max2=INT_MIN, temp;
    for (int i=1; i<=n; i++){
        scanf("%d", &temp);

        if(temp>max){
            max2=max;
            max=temp;
        }
        else if (temp>max2 && temp!=max){
            max2=temp;
        }
        //printf("max: %d, max2: %d\n", max, max2);
    }
    printf("%d\n", max2);
    return 0;
}

// 95