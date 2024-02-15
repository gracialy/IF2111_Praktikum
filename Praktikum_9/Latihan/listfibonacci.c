#include "listlinier.h"
#include <stdio.h>

int main(){
    List fibonacci; CreateEmpty(&fibonacci);
    int n;
    int a;
    scanf("%d", &n);

    if (n == 0){
        // ("[]\n");
    }
    else if (n==1){
        scanf("%d", &a);
        InsVLast(&fibonacci, a);
        // ("[%d]\n", a);
    }
    else{
        for (int i=1; i<=2; i++){
            scanf("%d", &a);
            InsVLast(&fibonacci, a);
        }

        address Prec2 = First(fibonacci);
        address Prec1 = Next(Prec2);

        for (int i=3; i<=n; i++){
            int c = Prec1->info + Prec2->info;
            InsVLast(&fibonacci, c);
            Prec2 = Prec1;
            Prec1 = Next(Prec1);
        }
    }
    PrintInfo(fibonacci);
    return 0;
}