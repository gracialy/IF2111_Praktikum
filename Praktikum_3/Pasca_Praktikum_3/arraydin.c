#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

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
    if((*array).Neff == (*array).Capacity)
    {
        (*array).A         = realloc((*array).A, 2*((*array).Capacity)*sizeof(ElType));
        (*array).Capacity *= 2;
    }
    
    for(int j = (*array).Neff; j > i; j--)
    {
        ((*array).A)[j] = ((*array).A)[j-1];
    }
    ((*array).A)[i] = el;
    (*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
// new
void InsertLast(ArrayDin *array, ElType el){
    InsertAt(array, el, Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
// new
void InsertFirst(ArrayDin *array, ElType el){
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    // migrasi ke depan
    for (int j=i; j<Length(*array)-1; j++){
        A(*array)[j]=A(*array)[j+1];
    }
    Neff(*array)-=1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
// new
void DeleteLast(ArrayDin *array){
    DeleteAt(array, Length(*array)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
// new
void PrintArrayDin(ArrayDin array){
    printf("[");
    for(int i = 0; i < array.Neff-1; i++)
    {
        printf("%d, ", array.A[i]);
    }
    if(array.Neff) printf("%d]\n", array.A[array.Neff-1]);
    else printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
// new
void ReverseArrayDin(ArrayDin *array){
    for(int i = 0; i < (*array).Neff/2; i++)
    {
        ElType temp = (*array).A[i];
        (*array).A[i] = (*array).A[(*array).Neff-i-1];
        (*array).A[(*array).Neff-i-1] = temp; 
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
// new
ArrayDin CopyArrayDin(ArrayDin array){
    return array;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    for(int i = 0; i < array.Neff; i++)
    {
        if(array.A[i] == el) return i;
    }
    return -1;
}