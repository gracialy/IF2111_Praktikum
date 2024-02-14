#include "duplicate.h"

Set arrToSet(int* arr, int arrSize){
    Set arrset;
    CreateEmpty(&arrset);
    for (int i=0; i<arrSize; i++){
        Insert(&arrset, arr[i]);
    }
    return arrset;
}
/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/

void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
    Set arrset;
    CreateEmpty(&arrset);

    arrset = arrToSet(arr, arrSize);
    *arrResSize = arrset.Count;

    for (int i=0; i<(*arrResSize); i++){
        arrRes[i] = arrset.Elements[i];
    }

    // sort algorithm
    for (int i=0; i<(*arrResSize); i++){
        boolean swapped = false;
        for (int j = i; j<(*arrResSize); j++){
            if (arrRes[i]<arrRes[j]){
                swapped = true;
                int temp = arrRes[i];
                arrRes[i] = arrRes[j];
                arrRes[j] = temp;    
            }
        }
        if (!swapped){
            break;
        }
    }
}
/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/