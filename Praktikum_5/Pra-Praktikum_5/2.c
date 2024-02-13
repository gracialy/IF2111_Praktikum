#include <stdio.h>

int main(){
    // input sebuah variabel char
    char banned;
    scanf("%c", &banned);
    char pita[80];
    scanf("%s", pita);

    int count = 0;
    int i = 0;
    while (pita[i]!='.'){
        if ((pita[i]=='a' || pita[i]=='e' || pita[i]=='i' || pita[i]=='o' || pita[i]=='u') && (pita[i]!=banned)){
            printf("%c", pita[i]);
            count ++;
        }
        i++;
    }
    if (count!=0){
        printf(" ");
    }
    printf("%d\n", count);
    return 0;
}