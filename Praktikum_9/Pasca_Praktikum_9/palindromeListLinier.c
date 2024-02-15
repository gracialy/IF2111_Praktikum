#include "palindromeListLinier.h"

boolean isPalindromeList(List l){
    List l2; CreateEmpty(&l2);
    address P = First(l);
    for (int i=0; i<NbElmt(l); i++){
        InsVLast(&l2, Info(P));
        P = P->next;
    }
    // PrintInfo(l2);
    InversList(&l2);
    // PrintInfo(l2);

    P = First(l);
    address Q = First(l2);
    for (int i=0; i<NbElmt(l); i++){
        if(P->info!=Q->info){
            return false;
        }
        P = P->next; Q = Q->next;
    }
    return true;
}

/*
    Diberikan sebuah list linier l,
    kembalikan true jika list tersebut merupakan palindrome dan false jika tidak.
    Contoh input/output:
    l: [1,2,3,4,5,4,3,2,1]
    expected return: true

    Di atas merupakan palindrome list linier karena jika dibaca dari kiri maupun kanan, tetap sama.

    l: [1,1,2,1]
    expected return: false

    Di atas bukan palindrome list linier karena jika dibaca dari kiri maupun kanan, berbeda. 1,1 dan 1,2.

    P.S. List linier kosong merupakan palindrome.
*/