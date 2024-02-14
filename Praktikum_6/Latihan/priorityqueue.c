/*
Soal 3 - Priority queue
a. Dengan memodifikasi queue alternatif 2 pada slide materi kuliah, definisikan
(algoritmik) struktur data yang merepresentasi queue yang menggambarkan antrian
pekerjaan (job shop). Setiap elemen queue bertipe ElType yang terdiri atas ⟨id:
integer, cost: integer⟩. id menunjukkan nomor identifikasi unik dari
pekerjaan yang dikelola queue, dan elemen queue terurut membesar berdasarkan
“cost” waktu memproses pekerjaan.
b. Buatlah prosedur enqueue
c. Buatlah prosedur dequeue
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct 
{
    int id;
    int cost;
} ElType;

typedef struct alt2
{
    ElType buffer[CAPACITY]; // { penyimpanan elemen }
    int idxHead; // { indeks elemen terdepan }
    int idxTail; // { indeks elemen terakhir }
} Queue;


void enqueue (Queue* q, ElType val){
    if (isEmpty(*q)){
        q->buffer[0] = val;
        q->idxHead=0;
        q->idxTail=0;
    }
    else{
        if (q->idxTail==CAPACITY-1){
            q->buffer[q->idxHead-1] = val;
            int i = q->idxHead;
            while (val.cost > q->buffer[i].cost && i<=q->idxTail){
                q->buffer[i-1] = q->buffer[i];
                q->buffer[i] = val;
                i++;
            }
            q->idxHead --;
        }
        else{
            q->buffer[q->idxTail+1] = val;
            int i = q->idxTail;
            while (val.cost < q->buffer[i].cost && i>=q->idxHead){
                q->buffer[i+1] = q->buffer[i];
                q->buffer[i] = val;
                i--;
            }
            q->buffer[q->idxTail+1] = val;
            q->idxTail ++;
        }
    }
}
/*
{Proses: menambahkan val sebagai elemen baru di q, dengan
memperhatikan lamanya waktu pekerjaan tsb dapat
diselesaikan, yaitu pekerjaan yang lebih cost diletakkan
lebih akhir. Jika ada 2 pekerjaan yang cost waktunya sama,
pekerjaan terakhir yang baru datang disisipkan lebih
belakang}
{IS: q mungkin kosong, q tidak penuh}
{FS: val menjadi elemen q yang baru dengan urutan waktu pekerjaan
membesar}
*/

void dequeue (Queue* q, ElType* val){
    *val = q->buffer[q->idxHead];
    if (q->idxHead == q->idxTail){
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    }
    else{
        q->idxHead = q->idxHead + 1;
    }
}
/*
{Proses: menyimpan IDX_UNDEF head q pada val dan menghapus head dari q}
{IS: q tidak kosong}
{FS: elemen pada HEAD dihapus, dan disimpan nilainya pada val}
*/

#endif