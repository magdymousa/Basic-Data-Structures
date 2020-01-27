#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG  0

typedef uint16_t List_DataType;
typedef uint16_t List_LengthType;



typedef struct List_Tag * List_Type;

List_Type List_Create(void);
void List_InsertAtTheBeginning(List_Type * Head,List_DataType Data);
void List_InsertAtTheEnd(List_Type * Head,List_DataType Data);
void List_InsertAfter_ith_Node(List_Type * Head,List_DataType Data,List_LengthType NodeNum);
void List_DeletNodeByData(List_Type * Head,List_DataType Data);
void List_PrintData(const List_Type const Head);
List_LengthType List_CountNodes(const List_Type const Head);
List_LengthType List_SearchForData(const List_Type const Head,const List_DataType Data);
void List_Reverse(List_Type * Head);


#endif // LINKEDLIST_H
