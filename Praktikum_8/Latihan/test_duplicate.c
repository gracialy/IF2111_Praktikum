#include <stdio.h>
#include "duplicate.h"

void printArray(int* arr, int arrSize){
    printf("[");
    for (int i=0; i<arrSize; i++){
        printf("%d", arr[i]);
        if (i<arrSize-1){
            printf(", ");
        }
    }
    printf("]\n");
}

int main(){
    int arr1[] = {1, 1, 3};
    int arr1Size = 3;
    int arr1Res[2];
    int arr1ResSize;
    removeDuplicateDesc(arr1, arr1Size, arr1Res, &arr1ResSize);
    printf("Test 1:\n");
    printf("Expected: [3, 1]\n");
    printf("Actual: ");
    printArray(arr1Res, arr1ResSize);
    printf("\n");

    int arr2[] = {1, 1, 2, 3};
    int arr2Size = 4;
    int arr2Res[3];
    int arr2ResSize;
    removeDuplicateDesc(arr2, arr2Size, arr2Res, &arr2ResSize);
    printf("Test 2:\n");
    printf("Expected: [3, 2, 1]\n");
    printf("Actual: ");
    printArray(arr2Res, arr2ResSize);
    printf("\n");

    int arr3[] = {1, 2, 3};
    int arr3Size = 3;
    int arr3Res[3];
    int arr3ResSize;
    removeDuplicateDesc(arr3, arr3Size, arr3Res, &arr3ResSize);
    printf("Test 3:\n");
    printf("Expected: [3, 2, 1]\n");
    printf("Actual: ");
    printArray(arr3Res, arr3ResSize);
    printf("\n");

    int arr4[] = {1, 1, 1};
    int arr4Size = 3;
    int arr4Res[1];
    int arr4ResSize;
    removeDuplicateDesc(arr4, arr4Size, arr4Res, &arr4ResSize);
    printf("Test 4:\n");
    printf("Expected: [1]\n");
    printf("Actual: ");
    printArray(arr4Res, arr4ResSize);
    printf("\n");

    return 0;
}