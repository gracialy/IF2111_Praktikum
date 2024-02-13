#include <stdio.h>
#include <stdbool.h>
#include "boolean.h"

#define MaxEl 100
#define Mark -9999  /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int
#define ElType int

typedef struct {
	ElType A[MaxEl];  /* Memori tempat penyimpanan elemen (container) */
} List;

void Set(List *L, IdxType i, ElType v);
void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}

List MakeList();
List MakeList(){
    List L;
    for (int i=0; i<MaxEl; i++){
        L.A[i] = Mark;
    }
    return L;
}


ElType Get(List L, IdxType i);
ElType Get(List L, IdxType i){
    return L.A[i];
}

int Length(List L);
int Length(List L){
    int i=0;

    while (Get(L, i)!=Mark){
        i++;
    }

    return i;
}

void TulisIsi (List T);
void TulisIsi (List T){
    for (int i=0; i<6; i++){
        printf("%d, \n", Get(T, i));
    }
}

boolean IsEmpty(List L);
boolean IsEmpty(List L){
    return L.A[0] == Mark;
}

IdxType FirstIdx(List L);
IdxType FirstIdx(List L){
    return 0;
}

IdxType LastIdx(List L);
IdxType LastIdx(List L){
    return Length(L)-1;
}

boolean IsIdxValid (List L, IdxType i){
    return (i<MaxEl) && (i>=0);
}

List Concat(List L1, List L2);
List Concat(List L1, List L2){
    for (int i=0; i<Length(L2); i++){
        Set(&L1, i+Length(L2), Get(L2, i));
    }
    return L1;
}

boolean Search(List L, ElType X);
boolean Search(List L, ElType X){
    boolean found = false;
    int i = 0;
    while (!found && i<Length(L)){
        found = (Get(L, i) == X);
        i++;
    }
    return found;
}

int main(){
    List L1 = MakeList();
    List L2 = MakeList();
    
    TulisIsi(L1);
    int get = Get(L1, 0);
    int len = Length(L1);
    boolean isempty = IsEmpty(L1);
    int first = FirstIdx(L1);
    int last = LastIdx(L1);
    Set(&L1, 0, 0);
    Set(&L1, 1, 1);
    Set(&L2, 0, 3);
    Set(&L2, 1, 4);
    List cat = Concat(L1,L2);
    TulisIsi(cat);

    if (Search(L1, 1)){
        printf("Mamma\n");
    }
    if (Search(L2, 10)){
        printf("Mia\n");
    }

    


    return 0;
}