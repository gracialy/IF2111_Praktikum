#include "queue.h"

int main(){
    Queue* qtime;
    CreateQueue(qtime);

    int menu, time, count=0, min=0, max=0;
    scanf("%d", &menu);

    while (menu!=0){
        if (menu==1){
            scanf("%d", &time);

            if (time>0){
                enqueue(qtime, time);
            }
        }
        else if (menu==2){
            if (!isEmpty(*qtime)) {
                count ++;
                dequeue(qtime, &time);
                if (time<min){
                    min=time;
                }
                if (time>max){
                    max=time;
                }
            }
        }
        scanf("%d", menu);
    }
    printf("%d\n%d\n%d\n", count, min, max);
    return 0;
}