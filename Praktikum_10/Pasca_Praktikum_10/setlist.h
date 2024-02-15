#ifndef SETLIST_H
#define SETLIST_H

#include "boolean.h"
#include <stdlib.h>

/* MODUL Set
Deklarasi set yang diimplementasikan menggunakan list dengan struktur berkait
*/

#define Nil NULL

typedef int infotype;

typedef struct tElmtSet *address;
typedef struct tElmtSet
{
    infotype Info;
    address Next;
} ElmtSet;

typedef struct
{
    address First;
} Set;

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(S) ((S).First)

/* ********* Prototype ********* */

address Alokasi (infotype Elmt);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S);
/* Mengirim true jika Set S kosong*/

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

int Count(Set S);
/* Mengembalikan jumlah elemen/anggota di dalam S*/

#endif