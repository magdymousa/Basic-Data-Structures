#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define debug 0

typedef int32_t Queue_DataSize_t;
typedef uint8_t Queue_Length_t;

#define QUEUE_MAX_SIZE 				(Queue_Length_t)100
#define QUEUE_DEFAULT_VALUE 	(Queue_DataSize_t)-9999



typedef struct{
	Queue_DataSize_t Data[QUEUE_MAX_SIZE];
	Queue_Length_t Head;
	Queue_Length_t Tail;
	Queue_Length_t size;


}Queue_t;


Queue_t *Queue_Creat(void);
void Queue_Insert(Queue_t * const queue,Queue_DataSize_t data);
Queue_DataSize_t Queue_Remove(Queue_t * const queue);
Queue_Length_t Queue_GetSize(const Queue_t * const queue);
void Queue_CleanUp(Queue_t * const queue);
void Queue_Destroy(Queue_t * const queue);
Queue_DataSize_t Queue_Head(Queue_t * const queue);

#endif //QUEUE_H
