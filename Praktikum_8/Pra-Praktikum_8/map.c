#include "map.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
// #define Nil 0
// #define MaxEl 10
// #define Undefined -999

// // typedef int bool;
// typedef int keytype;
// typedef int valuetype;
// typedef int address;

// typedef struct {
// 	keytype Key;
// 	valuetype Value;
// } infotype;

// typedef struct {
// 	infotype Elements[MaxEl];
// 	address Count;
// } Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
    (*M).Count = Nil;

}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M){
    return (M).Count==0;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
    return (M).Count==MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
    int i = 0;
    while(i < M.Count){
        if(M.Elements[i].Key == k){
            return M.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v){
    if(!IsMember(*M, k)){
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
    if(IsMember(*M, k)){
        int i = 0;
        while((*M).Elements[i].Key != k){
            i++;
        }
        while(i < (*M).Count){
            (*M).Elements[i].Key = (*M).Elements[i+1].Key;
            i++;
    }
    (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
    int i = 0;
    while(i < M.Count){
        if(M.Elements[i].Key == k){
            return true;
        }
        i++;
    }
    return false;
}
/* Mengembalikan true jika k adalah member dari M */