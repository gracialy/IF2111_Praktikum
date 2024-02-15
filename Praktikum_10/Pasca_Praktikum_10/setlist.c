#include "setlist.h"
#include <stdio.h>

/* MODUL Set
Deklarasi set yang diimplementasikan menggunakan list dengan struktur berkait
*/

// typedef int infotype;

// typedef struct tElmtSet *address;
// typedef struct tElmtSet
// {
//     infotype Info;
//     address Next;
// } ElmtSet;

// typedef struct
// {
//     address First;
// } Set;

// #define Info(P) (P)->Info
// #define Next(P) (P)->Next
// #define First(S) ((S).First)

/* ********* Prototype ********* */

address Alokasi (infotype Elmt){
    address P = (address) malloc (sizeof (ElmtSet));
    if (P != Nil){
        Info(P) = Elmt;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    First(*S) = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return First(S) == Nil;
}
/* Mengirim true jika Set S kosong*/

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    if (!IsMember(*S, Elmt)){
        address P = Alokasi (Elmt);
        if (P != Nil){
            if (IsEmpty(*S)){
                First(*S) = P;
            }
            else{
                address Last = First(*S);
                while (Next(Last) != Nil){
                    Last = Next(Last);
                }
                Next(Last) = P;
            }
        }
    }
}
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    if (IsMember(*S, Elmt)){
        address P = First(*S);
        address Prec = Nil;
        // printf("%d\n", Info(P)); //
        if (Info(P) == Elmt){
            First(*S) = Next(P);
            Dealokasi(&P);
        }
        else{
            Prec = P; 
            P = Next(P);
            // boolean found = false;
            while (P != Nil){
                if (Info(P) == Elmt){
                    Next(Prec) = Next(P);
                    Dealokasi(&P);
                    break;
                }
                Prec = P;
                P = Next(P);
            }
        }
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    if (!IsEmpty(S)){
        address P = First(S);
        while (P != Nil){
            if (Info(P) == Elmt){
                return true;
            }
            P = Next(P);
        }
    }
    return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */

int Count(Set S){
    int count = 0;
    if (!IsEmpty(S)){
        address P = First(S);
        do{
            count ++;
            P = Next(P);
        } while (P != Nil);
    }
    return count;
}
/* Mengembalikan jumlah elemen/anggota di dalam S*/