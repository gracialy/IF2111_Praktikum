#include <stdio.h>
#include "arrayMenu.h"


/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabMenu, cara deklarasi dan akses: */
/* Deklarasi : T : TabMenu */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = 0;
void MakeEmpty (TabMenu *T)
{
    (*T).Neff = 0;
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
int NbElmt (TabMenu T)
{
    return T.Neff;
}


/* *** Daya tampung container *** */
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMax - IdxMin + 1;
int MaxNbEl (TabMenu T)
{
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMin;
IdxType GetFirstIdx (TabMenu T)
{
    return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
IdxType GetLastIdx (TabMenu T)
{
    return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.TI[i];
ElType GetElmt (TabMenu T, IdxType i)
{
    return T.TI[i];
}


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
/* Assignment THsl -> Tin */
// (*Tout).Neff = Tin.Neff;
// for(int i = IdxMin; i <= Tin.Neff; i++){
// 	(*Tout).TI[i] = Tin.TI[i];
// }
void SetTab (TabMenu Tin, TabMenu *Tout)
{
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).TI[i] = v;
// if ((*T).Neff < i){
// 	(*T).Neff = i;
// }
void SetEl (TabMenu *T, IdxType i, ElType v)
{
    (*T).TI[i] = v;
    if ((*T).Neff < i)
    {
        (*T).Neff = i;
    }    
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = N;
void SetNeff (TabMenu *T, IdxType N)
{
    (*T).Neff = N;
}

/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return ((i >= IdxMin) && (i <= IdxMax));
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMenu T, IdxType i)
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
boolean IsIdxEff (TabMenu T, IdxType i)
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return (T.Neff == 0);
boolean IsEmpty (TabMenu T)
{
    return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return (T.Neff == IdxMax);
boolean IsFull (TabMenu T)
{
    return (T.Neff == IdxMax);
}



/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh
Nasi goreng - Makanan - 15000
Nasi goreng spesial - Makanan - 20000
Jus Mangga - Minuman - 10000
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
// START
void TulisIsi (TabMenu T)
{
    if(IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%s - %s - Rp.%d\n", T.TI[i].nama, T.TI[i].tipe, T.TI[i].harga);
        }
    }
}

/* ********** KONSTRUKTUR MENU ********** */
/* Membuat sebuah Menu dengan komponen-komponennya */
/* I.S. Nama, Tipe, dan Harga terdefinisi */
/* F.S. Terbentuk Menu baru */
ElType MakeMenu (char *nama, char *tipe, int harga)
{
    ElType menu;
    menu.nama = nama;
    menu.tipe = tipe;
    menu.harga = harga;
    return menu;
}



/* ********** NILAI EKSTREM ********** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum harga menu */
int MenuMax (TabMenu T)
{
    int maks = T.TI[GetFirstIdx(T)].harga;
    for(int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].harga > maks)
        {
            maks = T.TI[i].harga;
        }
    }
    return maks;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum harga menu */
int MenuMin (TabMenu T)
{
    int mins = T.TI[GetFirstIdx(T)].harga;
    for(int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].harga < mins)
        {
            mins = T.TI[i].harga;
        }
    }
    return mins;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu makanan */
int MakananCount (TabMenu T)
{
    int makanan = 0;
    for(int i =  GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].tipe[1] == 'a') {makanan++;}
    }
    return makanan;
}


int MinumanCount (TabMenu T)
{
    int minuman = 0;
    for(int i =  GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].tipe[1] == 'i') {minuman++;}
    }
    return minuman;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu minuman */

void MenuData (TabMenu T){
    printf("Jumlah Menu Makanan: %d\n", MakananCount(T));
    printf("Jumlah Menu Minuman: %d\n", MinumanCount(T));
    printf("Harga Menu Termahal: Rp.%d\n", MenuMax(T));
    printf("Harga Menu Termurah: Rp.%d\n", MenuMin(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Menampilkan data menu */
/* Contoh */
/* Jumlah Menu Makanan: 10 */
/* Jumlah Menu Minuman: 3 */
/* Harga Menu Termahal: Rp.30000 */
/* Harga Menu Termurah: Rp.10000 */