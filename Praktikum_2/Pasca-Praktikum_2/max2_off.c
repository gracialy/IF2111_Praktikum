#include <stdio.h>

int main(){
    int n;
    int val;
    int terbesar_pertama=0;
    int terbesar_kedua=0;
    int i;

    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%d", &val);
        if (i==0){
            terbesar_pertama=val;
        } else if (i==1){
            if (val>terbesar_pertama){
                terbesar_kedua=terbesar_pertama;
                terbesar_pertama=val;
            } else{
                terbesar_kedua=val;
            }
        } else{
            if (val>terbesar_pertama){
                terbesar_kedua=terbesar_pertama;
                terbesar_pertama=val;
            } else if (val>terbesar_kedua && val!=terbesar_pertama){
                terbesar_kedua=val;
            }
        }
    }
    printf("%d\n", terbesar_kedua);
    return 0;
}