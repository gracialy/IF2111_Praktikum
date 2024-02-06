/* *** ADT LAIN YANG DIPAKAI *** */
#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "garis.h"

/**
 * Perhatian:
Mohon baca instruksi pada file header, pastikan output sama persis seperti yang diminta
Input/output merupakan bilangan riil
Untuk ouput "Garis tidak valid" terdapat newline
*/

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
   /** POINT P1, P2;
   scanf("%d %d", &Absis(P1), &Ordinat(P1));
   scanf("%d %d", &Absis(P2), &Ordinat(P2));

   // tle
   while (Absis(P1)==Absis(P2) || Ordinat(P1)==Ordinat(P2)){
        printf("Garis tidak valid\n");
        scanf("%d %d", &Absis(P1), &Ordinat(P1));
        scanf("%d %d", &Absis(P2), &Ordinat(P2));
   }*/

    float x1, y1; scanf("%f %f", &x1, &y1);
    float x2, y2; scanf("%f %f", &x2, &y2);
    POINT P1 = MakePOINT(x1, y1), P2 = MakePOINT(x2, y2);
    while(EQ(P1, P2)) 
    {
        printf("Garis tidak valid\n");
        scanf("%f %f", &x1, &y1);
        scanf("%f %f", &x2, &y2);
        P1 = MakePOINT(x1, y1);
        P2 = MakePOINT(x2, y2);
    }
   MakeGARIS(P1, P2, L);
}

void TulisGARIS (GARIS L){
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
/* Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
    float x1, x2, y1, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));

    printf("((%.2f,%.2f),(%.2f,%.2f))", x1, y1, x2, y2);
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
/* Menghitung panjang garis L : berikan rumusnya */
// sqrt [(x2-x1)^2 + (y2-y1)^2] //
    float x1, x2, y1, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));

    return (sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
}

float Gradien (GARIS L){
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
    float x1, x2, y1, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));

    return ((y2-y1)/(x2-x1));
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
    return (Gradien(L1)*Gradien(L2)==-1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
    return (Gradien(L1)==Gradien(L2));
}