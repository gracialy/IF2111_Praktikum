// #include "deret.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int aritmatika(int a, int b, int n);
int aritmatika(int a, int b, int n){
    return a + b * (n-1);
}

int geometri(int a, int r, int n);
int geometri(int a, int r, int n){
    return a * pow(r, n-1);
}

void deret_aritmatika(int a, int b, int n, int *result);
void deret_aritmatika(int a, int b, int n, int *result){
    for (int i=0; i<n; i++){
        result[i] = aritmatika(a, b, i+1);
    }
}

void deret_geometri(int a, int r, int n, int *result);
void deret_geometri(int a, int r, int n, int *result){
    for (int i=0; i<n; i++){
        *(result+i) = geometri(a, r, i+1);
    }
}

void segitiga_pascal(int n, int *result);
void segitiga_pascal(int n, int *result){
    int line = n-1;

    for (int entry=0; entry<=line; entry++){
        int temp = 1;
        int mirror = entry;

        // the entry per line is mirrored, use smaller one for efficiency
        if (mirror > line-entry){
            mirror = line - entry;
        }
        for (int i=0; i<mirror; i++){
            temp = temp * (line - i) / (i + 1);
        }       
        *(result+entry) = temp;
    }
}

int main(){
    //printf("%d\n", aritmatika(1, 2, 5));
    // 1 + 2*4 = 9
    //printf("%d\n", geometri(1, 2, 3));
    // 1 * 2**2 = 4

    int* result;
    result = (int*)malloc(10 * sizeof(int));
    /** deret_aritmatika(1, 2, 5, result);
    for (int i=0; i<5; i++){
        printf("%d\n, ", result[i]);
    }
    */
    
    /**deret_geometri(1, 2, 3, result);
    for (int i=0; i<3; i++){
        printf("%d, \n", *(result+i));
    }
    */
    
    segitiga_pascal(5, result);
    for (int i=0; i<5; i++){
        printf("%d, \n", *(result+i));
    }
    return 0;
}