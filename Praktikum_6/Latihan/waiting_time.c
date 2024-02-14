#include "circular_queue.h"

/**
 * Menghitung waktu tunggu x pada Q, yaitu berapa banyak elemen yang ada
 * di depan elemen x pada Queue Q tanpa mengubah isi dari Q.Tab
 */
    // TODO: Implementasi fungsi
    //   I.S. Q sudah dialokasi, bisa kosong
    //   F.S. integer yang berisi "waktu tunggu" seperti definisi di atas
    //        jika x tidak ada pada antrean Q, kembalikan -1
int WaitingTime(Queue Q, int x){
    int count;
    ElType val;
    boolean found = false;
    Queue* temp;
    CreateQueue(temp);

    while (!IsEmpty(Q) && found==false){
        val=dequeue(&Q);
        enqueue(temp, val);
        if (val!=x){
            count += 1;
        }
        else{
            found=true;
        }
    }

    while(!IsEmpty(*temp)){
        val=dequeue(temp);
        enqueue(&Q, val);
    }

    if (found){
        return count;
    }
    else{
        return -1;
    }
}