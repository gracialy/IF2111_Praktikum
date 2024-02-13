#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct
	{
		ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} TabInt;

void MakeEmpty (TabInt *T);
void MakeEmpty (TabInt *T){
    (*T).Neff = 0;    
}

int NbElmt (TabInt T);
int NbElmt (TabInt T){
    return T.Neff;
}

ElType GetElmt (TabInt T, IdxType i);
ElType GetElmt (TabInt T, IdxType i){
	return T.TI[i];
}

/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
IdxType IdxMinTab (TabInt T);
IdxType IdxMinTab (TabInt T){
	int idx = IdxMin;
	for (int i=IdxMin+1; i<=NbElmt(T); i++){
		if (GetElmt(T, i) < GetElmt(T, idx)){
			idx = i;
		}
	}
	return idx;
}

int main(){
    TabInt T;
    MakeEmpty(&T);
    T.TI[1] = 2;
    T.TI[2] = 4;
    T.TI[3] = 3;
    T.Neff = 3;
    int min = IdxMinTab(T);
    return 0;
}