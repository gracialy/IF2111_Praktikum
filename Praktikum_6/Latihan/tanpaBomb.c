#include "tanpaBomb.h"
#include "queue.h"

Queue tanpaBomb(Queue queue, ElType bomb){
    Queue* temp;
    CreateQueue(temp);

    ElType* val;
    while(!isEmpty(queue)){
        dequeue(&queue, val);
        enqueue(temp, val);
    }
    while(!isEmpty(*temp)){
        dequeue(temp, val);
        if (val!=bomb){
            enqueue(&queue, val);   
        }
    }
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/