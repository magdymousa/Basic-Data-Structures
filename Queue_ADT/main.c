#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void){
    int queries = 0;
    int command = 0;
    Queue_DataSize_t data = 0;
    scanf("%d",&queries);
    Queue_t * queue;
    queue = Queue_Creat();
    while(queries--){
        scanf("%d",&command);
        switch(command){
            case 1:
                scanf("%ld",&data);
                Queue_Insert(queue,data);
                break;
            case 2:
                data = Queue_Remove(queue);
                break;
            case 3:
                printf("%ld\n",Queue_Head(queue));
                break;
            default:

                break;
        }

    }
    return 0;
}
