/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

// #define Nil NULL

// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;
// typedef struct {
// 	address First;
// } List;

// /* Definisi list : */
// /* List kosong : First(L) = Nil */
// /* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
// /* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P = First(L);
    while (P != Nil && Info(P) != X){
        P = Next(P);
    }
    return P;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            First(*L) = P;
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address Last = First(*L);
    address PrecLast = Nil;
    while (Next(Last) != Nil){
        PrecLast = Last;
        Last = Next(Last);
    }
    *X = Info(Last);
    if (PrecLast == Nil){
        First(*L) = Nil;
    } else {
        Next(PrecLast) = Nil;
    }
    Dealokasi(&Last);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil; // apakah perlu?
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    address P = First(*L);
    address Prec = Nil;
    while (P != Nil && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != Nil){
        if (Prec == Nil){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = Nil; //
        Dealokasi(&P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    address Last = First(*L);
    address PrecLast = Nil;
    while (Next(Last) != Nil){
        PrecLast = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (PrecLast == Nil){
        First(*L) = Nil;
    } else {
        Next(PrecLast) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P = First(L);
    printf("[");
    while (P != Nil){
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil){
            printf(",");
        }
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L){
    int count = 0;
    address P = First(L);
    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    infotype max = Info(First(L));
    address P = Next(First(L));
    while (P != Nil){
        if (Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
    address max = First(L);
    address P = Next(First(L));
    while (P != Nil){
        if (Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
    infotype min = Info(First(L));
    address P = Next(First(L));
    while (P != Nil){
        if (Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
    address min = First(L);
    address P = Next(First(L));
    while (P != Nil){
        if (Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
    float sum = 0;
    int count = 0;
    address P = First(L);
    while (P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return sum / count;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address P = First(*L);
    address Prec = Nil;
    address NextP = Nil;
    while (P != Nil){
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
    First(*L3) = First(*L1);
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address Last = First(*L3);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
