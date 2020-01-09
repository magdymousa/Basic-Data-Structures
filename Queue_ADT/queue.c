#include "queue.h"



typedef enum{FALSE, TRUE} Bool_t;

static void Queue_Init(Queue_t * const queue);
static Bool_t Queue_IsFull(const Queue_t * const queue);
static Bool_t Queue_IsEmpty(const Queue_t * const queue);

static void Queue_Init(Queue_t * const queue){
	queue->size = 0;
	queue->Tail = 0;
	queue->Head = 0;
}

Queue_t * Queue_Creat(void){
	Queue_t * queue = (Queue_t *)malloc(sizeof(* queue));
	if(queue != NULL){
		// error Msg;
		Queue_Init(queue);
	}
	return queue;
}



void Queue_Insert(Queue_t * const queue,Queue_DataSize_t data){
	if(!Queue_IsFull(queue)){
		queue->Data[queue->Tail] = data;
		++(queue->size);
		queue->Tail = (queue->Tail + 1) % QUEUE_MAX_SIZE;
	}
}


Queue_DataSize_t Queue_Remove(Queue_t * const queue){
	Queue_DataSize_t data;
	if(!Queue_IsEmpty(queue)){
		data = queue->Data[queue->Head];
		queue->size--;
		queue->Head = (queue->Head + 1) % QUEUE_MAX_SIZE;
	}
	return data;
}

Queue_DataSize_t Queue_Head(Queue_t * const queue){
    Queue_DataSize_t data;
    if(!Queue_IsEmpty(queue)){
        data = queue->Data[queue->Head];
        //queue->size--;
        //queue->Head = (queue->Head + 1) % QUEUE_MAX_SIZE;
    }
    return data;

}

Queue_Length_t Queue_GetSize(const Queue_t * const queue){
		return queue->size;
}

Bool_t Queue_IsFull(const Queue_t * const queue){
	Bool_t is_full = FALSE;
	if( ((queue->Tail + 1) % QUEUE_MAX_SIZE)  == queue->Head ){
		is_full = TRUE;
		#if debug == 1
            printf("queue full\n");
            printf("head= %d,Tail = %d,Size = %d\n",queue->Head,queue->Tail,queue->size);
		#endif // debug
	}
	else{
		is_full = FALSE;
        #if debug == 1
            printf("queue not full\n");
            printf("head= %d,Tail = %d,Size = %d\n",queue->Head,queue->Tail,queue->size);
		#endif // debug
	}
	return is_full;
}

Bool_t Queue_IsEmpty(const Queue_t * const queue){
	Bool_t is_empty = FALSE;
	if( queue->Tail == queue->Head){
		is_empty = TRUE;
        #if debug == 1
            printf("queue empty\n");
            printf("head= %d,Tail = %d,Size = %d\n",queue->Head,queue->Tail,queue->size);
		#endif // debug
	}
	else{
		is_empty = FALSE;
        #if debug == 1
            printf("queue not empty\n");
            printf("head= %d,Tail = %d,Size = %d\n",queue->Head,queue->Tail,queue->size);
		#endif // debug
	}

	return is_empty;
}


void Queue_CleanUp(Queue_t * const queue){
	//put default data or zeros
}

void Queue_Destroy(Queue_t * const queue){
	if(queue != NULL){
		Queue_CleanUp(queue);
		free(queue);
	}
}
