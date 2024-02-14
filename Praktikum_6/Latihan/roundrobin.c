#include "circular_queue.h"
/*
Soal 2 - Round Robin
Pandanglah queue pada soal nomor 1 sebagai antrian pekerjaan dengan id adalah nomor
identifikasi pekerjaan dan “cost” adalah cost waktu penyelesaian pekerjaan (time cost).

Dengan memanfaatkan queue pada soal nomor 1, buatlah procedure roundRobin yang
memproses queue secara Round Robin, yaitu memroses dengan waktu terbatas T:
• Jika elemen pada HEAD memiliki cost ≤ T, elemen tersebut dihapus dari queue.
• Jika elemen pada HEAD memiliki cost > T, maka elemen tersebut dihapus dari
queue dan disisipkan kembali sebagai Tail dengan cost yang berkurang sebesar T.
*/

// let the Eltype be int as cost
void roundRobin (Queue* q, int t){
    ElType cost;
    cost = dequeue(q);
    if (cost>=t){
        printf("<%d> telah selesai diproses\n", cost);
    }
    else if (cost>t){
        enqueue(q, cost-t);
    }
}
/*
{Proses: memproses elemen antrian q secara round robin}
{IS: q tidak kosong, t adalah waktu yang tersedia untuk memproses setiap elemen}
{FS: elemen e pada posisi HEAD dihapus dari q.

Jika cost e ≤ t maka ditampilkan “<id> telah selesai diproses”.
Jika cost e > t maka e disisipkan kembali sebagai tail q
dengan cost berkurang sebesar t }
*/