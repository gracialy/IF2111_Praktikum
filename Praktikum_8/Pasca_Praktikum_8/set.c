#include "set.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define Nil 0
// #define MaxEl 100

// typedef int infotype;
// typedef int address;

// typedef struct
// {
//     infotype Elements[MaxEl];
//     address Count;
// } Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
        (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
        return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
        return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
        if (!IsMember(*S, Elmt)){
                (*S).Elements[(*S).Count] = Elmt;
                (*S).Count ++;
        }        
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
        if(IsMember(*S, Elmt)){
                int i = 0;
                while((*S).Elements[i] != Elmt){
                i++;
                }
                while(i < (*S).Count){
                (*S).Elements[i] = (*S).Elements[i+1];
                i++;
                }
                (*S).Count--;
        }   
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
        int i = 0;
        while(i < S.Count){
                if(S.Elements[i] == Elmt){
                return true;
                }
                i++;
        }
        return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2){
        Set setunion;
        CreateEmpty(&setunion);

        for (int i=0; i<s1.Count; i++){
                Insert(&setunion, s1.Elements[i]);
        }
        // full handler?
        int i=0;
        while (i<s2.Count && !IsFull(setunion)){
                Insert(&setunion, s2.Elements[i]);
                i++;
        }

        return setunion;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2){
        Set setintersect;
        CreateEmpty(&setintersect);

        for (int i=0; i<s1.Count; i++){
                if (IsMember(s2, s1.Elements[i])){\
                        Insert(&setintersect, s1.Elements[i]);
                }
        }

        return setintersect;
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2){
        Set setsd;
        CreateEmpty(&setsd);

        for (int i=0; i<s1.Count; i++){
                if (!IsMember(s2, s1.Elements[i])){\
                        Insert(&setsd, s1.Elements[i]);
                }
        }

        for (int i=0; i<s2.Count; i++){
                if (!IsMember(s1, s2.Elements[i])){\
                        Insert(&setsd, s2.Elements[i]);
                }
        }


        return setsd;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2){
        Set setsubs;
        CreateEmpty(&setsubs);

        for (int i=0; i<s1.Count; i++){
                if (!IsMember(s2, s1.Elements[i])){\
                        Insert(&setsubs, s1.Elements[i]);
                }
        }

        return setsubs;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]