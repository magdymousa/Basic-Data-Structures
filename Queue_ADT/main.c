#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void){
    int i = 0;
    Queue_t * uart_queue;
    uart_queue = Queue_Creat();
    for(i = 0;i < 110;i++){
        Queue_Insert(uart_queue,i);
    }

    for(i = 0;i < 99;i++){
        printf("%d\t",Queue_Remove(uart_queue));
    }

    return 0;
}
