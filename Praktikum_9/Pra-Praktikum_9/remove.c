#include "remove.h"

void RemoveDuplicates(List *L){
    address P = First(*L);

    while (P != Nil){
        address Q = P;
        while (Q->next != Nil){
            if (Q->next->info == P->info){
                address R = Q->next;
                Q->next = R->next;
                free(R);
            } else {
                Q = Q->next;
            }
        }
        P = P->next;
    }
}

List removeDuplicate(List l) {
	// KAMUS LOKAL
	List L;
	address last, p;
	// ALGORITMA
	CreateEmpty(&L);
	last = First(l);
	while (last != Nil) {
		p = Search(L, Info(last));
		if (p == Nil) InsVLast(&L, Info(last));
		last = Next(last);
	}
	return L;
}

/*
I.S. Variable L sudah terisi dengan nilai
Melakukan penghapusan apabila terdapat nilai yang sama

Contoh:
Input: [1,1,2,3]
Output: [1,2,3]

Input: [1,2,3,1]
Output: [1,2,3]
*/
