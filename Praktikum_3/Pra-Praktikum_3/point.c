// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 19 September 2023
// Topik: ADT, Pointer, dan Array Dinamik
// Deskripsi: Implementasi point.h

// HEADER
#include <stdio.h>
#include <math.h>
#include "point.h" // include file header
        
// IMPLEMENTASI PROTOTIPE
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    // KAMUS
    POINT P;
    // ALGORITMA
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

// *P: output, means writing to preserve outside the procedure 
// P: input   
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                              
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    // KAMUS
    float x, y;
    
    // ALGORITMA
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
// Note: Prosedur tulisPOINT mengeluarkan output dengan 2 desimal, TANPA diakhiri new line
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
    // ALGORITMA
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return !((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    // ALGORITMA
    return ((Absis(P)==0) && (Ordinat(P)==0));
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P)==0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    if (Absis(P)>0 && Ordinat(P)>0){
        return 1;
    }
    else if (Absis(P)<0 && Ordinat(P)>0){
        return 2;
    }
    else if (Absis(P)<0 && Ordinat(P)<0){
        return 3;
    }
    else if (Absis(P)>0 && Ordinat(P)<0){
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    *P = PlusDelta(*P, deltaX, deltaY);
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
    return (sqrt(pow(Absis(P1)-Absis(P2), 2) + pow(Ordinat(P1)-Ordinat(P2), 2)));
}