#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
    CreateEmpty(Odd); CreateEmpty(Even);
    address P = First(L);
    for(int i = 0; i<NbElmt(L); i++){
        if(Info(P) % 2 == 0){
            InsVLast(Even, Info(P));
        }else{
            InsVLast(Odd, Info(P));
        }
        P = Next(P);
    }
    
    // sort
    if (!IsEmpty(*Odd)){
        P = First(*Odd);
        for (int i = 0; i<NbElmt(*Odd)-1; i++){
            boolean swapped = 0;
            address Q = Next(P);
            for (int j = 0; j<NbElmt(*Odd)-i-1; j++){
                if (Info(P) > Info(Q)){
                    infotype temp = Info(P);
                    Info(P) = Info(Q);
                    Info(Q) = temp;
                    swapped = 1;
                }
                Q = Next(Q);
            }
            if (!swapped){
                break;
            }
            P = Next(P);
        }
    }
    
    if(!IsEmpty(*Even)){
        P = First(*Even);
        for (int i = 0; i<NbElmt(*Even)-1; i++){
            boolean swapped = 0;
            address Q = Next(P);
            for (int j = 0; j<NbElmt(*Even)-i-1; j++){
                if (Info(P) > Info(Q)){
                    infotype temp = Info(P);
                    Info(P) = Info(Q);
                    Info(Q) = temp;
                    swapped = 1;
                }
                Q = Next(Q);
            }
            if (!swapped){
                break;
            }
            P = Next(P);
        }
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
