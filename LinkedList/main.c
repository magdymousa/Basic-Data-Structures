#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(void){
    unsigned ListOPeration = 0;
    List_DataType ListData = 0;
    List_LengthType ListNode = 0;

    List_Type Head;
    Head = List_Create();

    do{
        printf("0: Print List Items\n1: Insert Item At The Beginning\n2: Insert Item At The End"
               "\n3: Insert Item After Node\n4: Delete Node\n5: Reverse List"
               "\n6: List Nodes Count\n7: Exit\n");
        scanf("%u",&ListOPeration);

        switch(ListOPeration){
            case 0:
                List_PrintData(Head);
                break;
            case 1:
                printf("Enter Data \n");
                scanf("%hu",&ListData);
                List_InsertAtTheBeginning(&Head,ListData);
                break;
            case 2:
                printf("Enter Data \n");
                scanf("%hu",&ListData);
                List_InsertAtTheEnd(&Head,ListData);
                break;
            case 3:
                printf("Enter Data \n");
                scanf("%hu",&ListData);
                printf("Enter Node Number \n");
                scanf("%hu",&ListNode);
                List_InsertAfter_ith_Node(&Head,ListData,ListNode);
                break;
            case 4:
                printf("Enter Data \n");
                scanf("%hu",&ListData);
                List_DeletNodeByData(&Head,ListData);
                break;
            case 5:
                List_Reverse(&Head);
                break;
            case 6:
                printf("List Nodes Count = %u\n",List_CountNodes(Head));
                break;
            case 7:
                printf("Exit\n");
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }


    }while( ListOPeration != 7);


     return 0;
}
