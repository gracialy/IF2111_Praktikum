#include "circular_queue.h"
#include <stdio.h>

int main(){
    // n: jumlah lagu
    // m: jumlah playlist

    /*
    `1`: Memutar lagu selanjutnya dari queue.
    `2`: Mengaktifkan/menonaktifkan fitur loop.
    `3 `: Menambahkan lagu ke queue berdasarkan ID-nya.
    `4 `: Menambahkan lagu dari playlist ke queue.
    `0`: Keluar dari program.

    - Saat memutar lagu: `Play lagu `
    - Saat queue kosong: `Tidak ada lagu`
    - Saat loop diaktifkan: `Looping lagu`
    - Saat loop dinonaktifkan: `Tidak looping lagu`
    - Saat queue penuh saat mencoba menambahkan lagu: `Queue penuh`
    */
    
    int n, m, val;
    scanf("%d %d", &n, &m); // jumlah lagu, jumlah playlist
    
    // matriks playlist
    int arr[m][3];
    for (int i=0; i<m; i++){
        for (int j=0; j<3; j++){
            scanf("%d", &arr[i][j]);
            // handling invalid id
            // Jika terdapat playlist yang memiliki lagu yang tidak ada, (id_lagu < 0 atau id_lagu > N - 1) maka keluarkan `Playlist tidak valid` dan berhentikan program tanpa memproses masukan lainnya.
            if (arr[i][j]<0 || arr[i][j]>n-1){
                printf("Playlist tidak valid\n");
                exit(0); //
            }
        }
    }

    Queue q;   
    CreateQueue(&q); 

    int input;
    scanf("%d", &input);
    int loop=0;

    while (input){
        if (input==1){
            if (IsEmpty(q)){
                printf("Tidak ada lagu\n");
            }
            else{
                int np = dequeue(&q);
                printf("Play lagu %d\n", np);
                if (loop){
                    enqueue(&q, np);
                }
            }
        }
        else if (input==2){
            if (loop){
                printf("Tidak looping lagu\n");
                loop = 0;
            }
            else{
                printf("Looping lagu\n");
                loop = 1;
            }
        }
        else if (input==3){
            int idlagu;
            scanf("%d", &idlagu);
            if (IsFull(q)){
                printf("Queue penuh\n");
            }
            else{
                enqueue(&q, idlagu);
            }
        }
        else if (input==4){
            int idpl;
            scanf("%d", &idpl);
            for(int i=0; i<3; i++){
                if (IsFull(q)){
                    printf("Queue penuh\n");
                    break;
                }
                else{
                    enqueue(&q, arr[idpl][i]);
                }
            }
        }
        scanf("%d", &input);
    }
    return 0;
}