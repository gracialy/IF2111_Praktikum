// Nama/NIM: Lydia Gracia/18222035
// Tanggal: 19 September 2023
// Topik: ADT, Pointer, dan Array Dinamik
// Deskripsi: Implementasi arraydin.h

#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

// Boolean
/**
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxType;
typedef int ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ArrayDin;
*/

/* *** Notasi Akses: Selektor ArrayDin *** */
#define A(AD) (AD).A
#define Cap(AD) (AD).Capacity
#define Neff(AD) (AD).Neff

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin AD;
    A(AD) = (ElType*) malloc (InitialSize*sizeof(ElType));
    Cap(AD) = InitialSize;
    Neff(AD) = 0;
    return AD;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free(A(*array));
    Cap(*array)=0;
    Neff(*array)=0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return (Neff(array)==0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return Neff(array);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return A(array)[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return Cap(array);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if (Length(*array)<Cap(*array)){
        // migrasi ke belakang
        for (int j=Length(*array); j>i; j--){
            A(*array)[j]=A(*array)[j-1];
        }
        A(*array)[i]=el;
        Neff(*array)+=1;
    }
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    // migrasi ke depan
    for (int j=i; j<Length(*array); j++){
        A(*array)[j]=A(*array)[j+1];
    }
    Neff(*array)-=1;
}