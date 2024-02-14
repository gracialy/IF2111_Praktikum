#include "duplicates.h"

boolean hasDuplicate(int n, int *nums, int k){
    if (n==1 || n==0){
        return false;
    }
    else{
        HashMap M;
        CreateEmpty(&M);

        for (int i=0; i<=n-1; i++){
            if (Value(M, nums[i])==Undefined){
                Insert(&M, nums[i], i);
            }
            else{
                if (k>n){
                    return true;
                }
                else{
                    if (i-Value(M, nums[i])<=k){
                        return true;
                    }
                    else{
                        M.Elements[Hash(nums[i])].Value = i;
                    }
                }
            }
        }
    return false;
    }
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
