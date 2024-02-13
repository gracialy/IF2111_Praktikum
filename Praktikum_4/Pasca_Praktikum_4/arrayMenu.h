#include "boolean.h"

#ifndef ARRAY_H
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
	char *nama;
	char *tipe;
	int harga;
} ElType;

typedef struct
	{
		ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} TabMenu;

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
void MakeEmpty (TabMenu *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = 0;

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMenu T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
/* *** Daya tampung container *** */
int MaxNbEl (TabMenu T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMax - IdxMin + 1;
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMin;
IdxType GetLastIdx (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabMenu T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.TI[i];

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMenu Tin, TabMenu *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
/* Assignment THsl -> Tin */
// (*Tout).Neff = Tin.Neff;
// for(int i = IdxMin; i <= Tin.Neff; i++){
// 	(*Tout).TI[i] = Tin.TI[i];
// }
void SetEl (TabMenu *T, IdxType i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).TI[i] = v;
// if ((*T).Neff < i){
// 	(*T).Neff = i;
// }
void SetNeff (TabMenu *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = N;

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMenu T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return ((i >= IdxMin) && (i <= IdxMax));
boolean IsIdxEff (TabMenu T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMenu T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return (T.Neff == 0);
/* *** Test tabel penuh *** */
boolean IsFull (TabMenu T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return (T.Neff == IdxMax);

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMenu T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh
Nasi goreng - Makanan - 15000
Nasi goreng spesial - Makanan - 20000
Jus Mangga - Minuman - 10000
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** KONSTRUKTUR MENU ********** */
ElType MakeMenu (char *nama, char *tipe, int harga);
/* Membuat sebuah Menu dengan komponen-komponennya */
/* I.S. Nama, Tipe, dan Harga terdefinisi */
/* F.S. Terbentuk Menu baru */

/* ********** NILAI EKSTREM ********** */
int MenuMax (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum harga menu */

int MenuMin (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum harga menu */

int MakananCount (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu makanan */

int MinumanCount (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu minuman */

void MenuData (TabMenu T);
/* Prekondisi : Tabel T tidak kosong */
/* Menampilkan data menu */
/* Contoh */
/* Jumlah Menu Makanan: 10 */
/* Jumlah Menu Minuman: 3 */
/* Harga Menu Termahal: Rp.30000 */
/* Harga Menu Termurah: Rp.10000 */

#endif