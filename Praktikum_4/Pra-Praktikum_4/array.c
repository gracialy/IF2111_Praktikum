#include "boolean.h"
#include "array.h"
#include <stdio.h>

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
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
void MakeEmpty (TabInt *T){
    (*T).Neff = 0;    
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
// Mengirimkan banyaknya elemen efektif tabel 
// Mengirimkan nol jika tabel kosong 
int NbElmt (TabInt T){
    return T.Neff;
}

/* *** Daya tampung container *** */
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
int MaxNbEl (TabInt T){
    return IdxMax;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetFirstIdx (TabInt T){
	return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
IdxType GetLastIdx (TabInt T){
	return (T.Neff);
}

/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
ElType GetElmt (TabInt T, IdxType i){
	return T.TI[i];
}


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetTab (TabInt Tin, TabInt *Tout){
	(*Tout).Neff = Tin.Neff;
	for (int i=1; i<=Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetEl (TabInt *T, IdxType i, ElType v){
	(*T).TI[i] = v;	
	if (i>(*T).Neff){
		// if you're using SetNeff primitive, this will somehow be recursive and causing RTE
		(*T).Neff ++;
	}
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void SetNeff (TabInt *T, IdxType N){
	(*T).Neff = N;
}


/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxValid (TabInt T, IdxType i){
	return (i<=IdxMax && i>=IdxMin);
}

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
boolean IsIdxEff (TabInt T, IdxType i){
	return (i<=T.Neff && i>=IdxMin);
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
boolean IsEmpty (TabInt T){
	return T.Neff==0;
}

/* *** Test tabel penuh *** */
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
boolean IsFull (TabInt T){
	return T.Neff==IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
1:1
2:2
3:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
void TulisIsi (TabInt T){
	if (NbElmt(T)==0){
		printf("Tabel kosong\n");
	}
	else{
		for (int i=IdxMin; i<=T.Neff; i++){
			printf("%d:%d\n", i, T.TI[i]);
		}
	}
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt T;
	MakeEmpty(&T);

	T.Neff = T1.Neff;
	for (int i=1; i<=T1.Neff; i++){
		T.TI[i] = T1.TI[i] + T2.TI[i];
	}
	return T;
}

/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt T;
	MakeEmpty(&T);

	T.Neff = T1.Neff;
	for (int i=1; i<=T1.Neff; i++){
		T.TI[i] = T1.TI[i] - T2.TI[i];
	}
	return T;
}

/* ********** NILAI EKSTREM ********** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMax (TabInt T){
	return GetElmt(T, IdxMaxTab(T));
	/** int max;
	max = GetElmt(T, IdxMin);
	// jika ganti model, bisa jadi perubahan di IdxMin (?)
	for (int i=GetFirstIdx+1; i<=GetLastIdx(T); i++){
		if(GetElmt(T, i)>max){
			max = GetElmt(T, i);
		}
	}
	return max;
	*/
}


/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
ElType ValMin (TabInt T){
	return GetElmt(T, IdxMinTab(T));
	/** int min;
	min = GetElmt(T, IdxMin);
	// jika ganti model, bisa jadi perubahan di IdxMin (?)
	for (int i=GetFirstIdx+1; i<=GetLastIdx(T); i++){
		if(GetElmt(T, i)<min){
			min = GetElmt(T, i);
		}
	}
	return min;
	*/
}


/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
IdxType IdxMaxTab (TabInt T){
	int idx = IdxMin;
	for (int i=2; i<=NbElmt(T); i++){
		if (GetElmt(T, i) > GetElmt(T, idx)){
			idx = i;
		}
	}
	return idx;
}


/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
IdxType IdxMinTab (TabInt T){
	int idx = IdxMin;
	for (int i=IdxMin+1; i<=NbElmt(T); i++){
		if (GetElmt(T, i) < GetElmt(T, idx)){
			idx = i;
		}
	}
	return idx;
}
