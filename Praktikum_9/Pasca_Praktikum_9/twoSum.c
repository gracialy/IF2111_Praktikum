#include "twoSum.h"

int twoSum(List L1, List L2){
    InversList(&L1);
    InversList(&L2);

    int a = 0, b = 0;
    address P = First(L1);
    for (int i=0; i<NbElmt(L1); i++){
        a = a*10 + Info(P);
        P = P->next;
    }
    P = First(L2);
    for (int i=0; i<NbElmt(L2); i++){
        b = b*10 + Info(P);
        P = P->next;
    }
    return a + b;
}
/* I.S. Masing-masing elemen dari L1 dan L2 merupakan angka dan */
/* L1 maupun L2 tidak kosong */
/* F.S. Menghasilkan angka hasil penjumlahan dua buah list L1 dan L2 */

/* Contoh */
/* L1 = 1 -> 2 -> 3  = 321 */ 
/* L2 = 5 -> 4 = 45 */
/* maka hasilnya adalah */
/* 321 + 45 = 366 */

/* L1 = 1 -> 9 -> 9 */
/* L2 = 9 */
/* maka hasilnya adalah */
/* 991 + 9 = 1000 */