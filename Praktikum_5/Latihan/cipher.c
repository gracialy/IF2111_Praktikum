#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>

int main(){
    int geser;
    STARTWORD();
    if (! EndWord){
        geser = currentWord.Length%26;
    }
    while (! EndWord){
        for (int i=0; i<currentWord.Length; i++){
            currentWord.TabWord[i] += geser;
            if (currentWord.TabWord[i]>90){
                currentWord.TabWord[i] -= 26;
            }
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        if (! EndWord){
            printf(" ");
        }
    }
    printf(".\n");
}
