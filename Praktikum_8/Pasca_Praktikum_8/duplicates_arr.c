#include "duplicates.h"

boolean hasDuplicate(int n, int *nums, int k){
    if (n==1 || n==0){
        return false;
    }
    else{
        if (k>n){
            for (int i=0; i<n; i++){
                for (int j=i+1; j<n; j++){
                    // printf("evaluate %d %d\n", nums[i], nums[j]); //
                    if (nums[i]==nums[j]){
                        return true;
                    }
                }
            }
        }
        else{
            for (int i=0; i<n-1; i++){
                for (int j=1; j<=k; j++){
                    // printf("evaluate %d %d\n", nums[i], nums[i+j]); //
                    if (nums[i]==nums[i+j]){
                        return true;
                    }
                    if(i+j==n-1){
                        break;
                    }
                }
            }
        }
    }
    return false;
}
/* I.S Array nums bisa kosong, n merupakan panjang array nums, k merupakan integer positif */
/* F.S Mengembalikan boolean apabila terdapat duplicate number pada rentang k di array nums. 
Apabila nums kosong atau hanya 1 elemen maka mengembalikan nilai false */
/* 
  Contoh:
- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 4

  return: true
  Penjelasan: Elemen 6 berulang dengan jarak 4 yang mana <= k

- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 2

  return: false
  Penjelasan: Tidak ada elemen berulang dengan jarak k = 2
*/
