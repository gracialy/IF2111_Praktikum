#include "boolean.h"
#include "linkdummy.h"

/* Definisi Type Data */
// typedef int ElType;
// typedef struct tNode *address;
// typedef struct tNode {
//     ElType info;
//     address next;
// } Node;
// typedef struct {
//     address First;
//     address Last;
// } List;

/* Definisi list: */
/* List kosong: First(L) = Last(L) = dummy@ */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen dummy terletak pada last */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/

boolean IsEmpty(List L){
    return (First(L) == Last(L));
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L){
    address dummy = Alokasi(0);
    First(*L) = dummy; 
    Last(*L) = dummy;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X){
    address P = (address*) malloc(sizeof(ElType));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X){
    address P = First(L);
    if (IsEmpty(L)){
        return Nil;
    } else {
        while (Info(P) != X){
            P = Next(P);
        }
        if (P == Last(L)){
            return Nil;
        }
        else{
            return P;
        }
    }
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X){
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            address dummy = Alokasi (0);
            Last(*L) = dummy;
        } else {
            Next(P) = First(*L);
        }
        First(*L) = P;
    }
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X){
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            address dummy = Alokasi (0);
            First(*L) = P;
            Next(P) = dummy;
        } else {
            address Prec = First(*L);
            while (Next(Prec) != Last(*L)){
                Prec = Next(Prec);
            }
            Next(Prec) = P;
            Next(P) = Last(*L);
        }
    }
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X){
    address P = First(*L);
    if (Next(First(*L)) == Last(*L)){
        First(*L) = Last(*L);
    }
    else{
        First(*L) = Next(First(*L));
        Next(P) = Last(*L);
    }
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X){
    address P;
    if (Next(First(*L)) == Last(*L)){
        P = First(*L);
        First(*L) = Last(*L);
    } else {
        address Prec = First(*L);
        while (Next(Next(Prec)) != Last(*L)){
            Prec = Next(Prec);
        }
        P = Next(Prec);
        Next(Prec) = Last(*L);
    }
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */