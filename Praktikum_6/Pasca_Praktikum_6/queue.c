#include "queue.h"
#include <stdio.h>
// alt 2

void CreateQueue(Queue *q){
    q->idxHead=IDX_UNDEF;
    q->idxTail=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

boolean isEmpty(Queue q){
    return q.idxHead==IDX_UNDEF && q.idxTail==IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q){
    return length(q) == CAPACITY;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else if (IDX_HEAD(q)<=IDX_TAIL(q)){
        return q.idxTail - q.idxHead + 1;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else if (IDX_TAIL(*q)==CAPACITY-1){
        int a = IDX_HEAD(*q);
        for(int i = a; i <= CAPACITY; i++)
        {
            (*q).buffer[i-a] = (*q).buffer[i]; 
        }
        IDX_HEAD(*q) -= a;
        IDX_TAIL(*q) -= (a-1);
    }
    else{
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (length(*q)==1){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)++;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    Queue output = q;
    printf("[");
    while (!isEmpty(output))
    {
        int cur; dequeue(&output, &cur);
        printf("%d", cur); 
        if(!isEmpty(output)){
            printf(",");
        }
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
