#include "hashmap.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
*/

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
    /* I.S. sembarang */
    /* F.S. M kosong */
    M->Count = 0;
    for (int i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
    /* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
    return K % MaxEl;
}

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
    /* Menghasilkan nilai dari element dengan key K */
    /* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    address i = Hash(k);
    while (M.Elements[i].Key != k && M.Elements[i].Key != Undefined) {
        i = (i + 1) % MaxEl;
    }
    if (M.Elements[i].Key == k) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */

void Insert(HashMap *M, keytype k, valuetype v) {
    if (M->Count < MaxEl) {
        address i = Hash(k);
        while (M->Elements[i].Key != Undefined && M->Elements[i].Key != k) {
            i = (i + 1) % MaxEl;
        }
        if (M->Elements[i].Key == Undefined) {
            M->Elements[i].Key = k;
            M->Elements[i].Value = v;
            M->Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */