/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
#include <stdbool.h>
#include "list.h"
#include "boolean.h"

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
List MakeList(){
    List L;
	for (int i=0; i<MaxEl; i++) {
        L.A[i]=Mark;
    }
	return L;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
boolean IsEmpty(List L){
    return (L.A[0] == Mark);
}


/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
ElType Get(List L, IdxType i){
    return L.A[i];
}


/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int Length(List L){
    int i=0;
	while(Get(L,i)!=Mark){
		i++;
	}
	return i;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType FirstIdx(List L){
    return 0;
}


/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
IdxType LastIdx(List L){
    return (Length(L)-1);
}


/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
boolean IsIdxValid (List L, IdxType i){
    return (i>=0 && i<MaxEl);
}


/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean IsIdxEff (List L, IdxType i){
    return (i>=0 && i<Length(L));
}


/* ********** Operasi-operasi ********** */
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean Search(List L, ElType X){
    boolean found = false;
	int i=0;
	while(!found && i<Length(L))
	{
		if(Get(L,i)==X) {
            found=true;
        }
		i++;
	}
	return found;
}


/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
void InsertFirst(List *L, ElType X){
	for (int i=Length(*L)-1; i>=0; i--){
		Set(L, i+1, Get(*L,i));
	}
	Set(L, 0, X);
}


/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertAt(List *L, ElType X, IdxType i){
    for (int j=Length(*L)-1; j>=i; j--){
		Set(L, j+1, Get(*L,j));
	}
	Set(L, i, X);
}


/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void InsertLast(List *L, ElType X){
    Set(L, Length(*L), X);
}


/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteFirst(List *L){
	for (int i=0; i<Length(*L); i++){
		Set(L, i, Get(*L,i+1));
	}
}


/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAt(List *L, IdxType i){
    for (int j=i; j<Length(*L); j++){
		Set(L, j, Get(*L,j+1));
	}
}


/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void DeleteLast(List *L){
    Set(L, Length(*L)-1, Mark);
}


/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
List Concat(List L1, List L2){
    int j=0;
	for (int i=Length(L1); i<Length(L1)+Length(L2); i++){
		Set((&L1), i, Get(L2,j));
		j++;
	}
	return L1;
}