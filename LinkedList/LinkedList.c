#include "LinkedList.h"


struct List_Tag{
    List_DataType Data;
    List_Type Next;
};

#if DEBUG == 11
    static void List_PrintListPointers(const List_Type const Head);
#endif // DEBUG


List_Type List_Create(void){
    #if DEBUG == 1
        printf("List_Create \n");
    #endif // DEBUG
    List_Type Head = NULL;

    return Head;
}

void List_InsertAtTheBeginning(List_Type * Head,List_DataType Data){
    #if DEBUG == 1
        printf("List_InsertAtTheBeginning Data = %u\n",Data);
    #endif // DEBUG

    /* Create New Node */
    List_Type Node = (List_Type) malloc(sizeof( * Node));
    Node->Data = Data;
    Node->Next = * Head;

    * Head = Node;
}

void List_InsertAtTheEnd(List_Type * Head,List_DataType Data){
    #if DEBUG == 1
        printf("List_InsertAtTheEnd Data = %u\n",Data);
    #endif // DEBUG
    List_Type Current_Node = * Head;

    /* Create New Node */
    List_Type Node = (List_Type) malloc(sizeof( * Node));
    Node->Data = Data;
    Node->Next = NULL;

    if(Current_Node == NULL){  // Check If Empty List
        * Head = Node;
    }
    else{
        while(Current_Node->Next != NULL){
            #if DEBUG == 1
                printf("Skipped Node With Data = %u \n",Current_Node->Data);
            #endif // DEBUG
            Current_Node = Current_Node->Next;
        }
        Current_Node->Next = Node;
    }
}

void List_InsertAfter_ith_Node(List_Type * Head,List_DataType Data,List_LengthType NodeNum){
    #if DEBUG == 1
        printf("List_InsertAfter_ith_Node Data = %u NodeNum = %u\n",Data,NodeNum);
    #endif // DEBUG

    List_Type Current_Node = * Head;
    List_LengthType count = NodeNum;
    if(Current_Node == NULL){
        printf("Empty List \n");  // return error Empty List
        return;
    }
    while(--count){
        Current_Node = Current_Node->Next;
        if(Current_Node == NULL){
            printf("List Length < (%u) NodeNum\n",NodeNum);
            return; //return error Short List
        }
    }
    /* Create New Node */
    List_Type Node = (List_Type) malloc(sizeof( * Node));
    Node->Data = Data;
    Node->Next = Current_Node->Next;
    Current_Node->Next = Node;
}

void List_DeletNodeByData(List_Type * Head,List_DataType Data){
    #if DEBUG == 1
        printf("List_DeletNodeByData Data = %u\n",Data);
    #endif // DEBUG

    List_Type Current_Node = * Head;
    List_Type Temp = NULL;
    if(Current_Node == NULL){
        printf("Empty List\n");  // return error Empty List
        return;
    }
    else if(Current_Node->Data == Data){
        Temp = Current_Node;
        * Head = Current_Node->Next;
        free(Temp);
    }
    else{
        while(Current_Node->Next != NULL && Current_Node->Next->Data != Data){
                #if DEBUG == 1
                    printf("Skipped Data Data = %u\n",Current_Node->Data);
                #endif // DEBUG
            Current_Node = Current_Node->Next;
        }

        if(Current_Node->Next != NULL){
            Temp = Current_Node->Next;
            Current_Node->Next = Current_Node->Next->Next;
            free(Temp);
        }
        else{
            printf("Data Not Found In The List\n");
            return;
        }
    }
}


void List_PrintData(const List_Type const Head){
    List_Type Current_Node = Head;
    #if DEBUG == 1
        printf("List_PrintData \n");
    #endif // DEBUG
    if(Current_Node == NULL){
        printf("Empty List \n");
        return;
    }
    while(Current_Node != NULL){
        printf("%u\t",Current_Node->Data);
        Current_Node = Current_Node->Next;
    }
    printf("\n");
}

void List_Reverse(List_Type * Head){
    List_Type Current_Node = * Head;
    if(Current_Node == NULL){
        printf("Empty List \n");
        return;
    }
    List_Type Prev_Node = NULL;
    List_Type Next_Node = Current_Node->Next;

    while(Current_Node->Next != NULL){
        Current_Node->Next = Prev_Node;
        Prev_Node = Current_Node;
        Current_Node = Next_Node;
        Next_Node = Current_Node->Next;
    }

    Current_Node->Next = Prev_Node;
    * Head = Current_Node;

    #if DEBUG == 1
        printf("List_Reverse \n");
        List_PrintData(*Head);
    #endif // DEBUG
}

List_LengthType List_CountNodes(const List_Type const Head){
    List_LengthType Length = 0;
    List_Type Current_Node = Head;
    while(Current_Node != NULL){
        Length++;
        Current_Node = Current_Node->Next;
    }
    return Length;
}

List_LengthType List_SearchForData(const List_Type const Head,const List_DataType Data){
    List_LengthType Node_Num = 0;
    List_Type Current_Node = Head;
    while(Current_Node != NULL){
        if(Current_Node->Data == Data){
             return ++Node_Num;
        }
        else{
            ++Node_Num;
            Current_Node = Current_Node->Next;
        }
    }

    return 0xFF;
}


#if DEBUG == 11
void List_PrintListPointers(const List_Type const Head){
    List_Type Current_Node = Head;
    printf("List_PrintListPointers \n");
    while(Current_Node != NULL){
        printf("0x%p\t",Current_Node);
        Current_Node = Current_Node->Next;
    }
    printf("\n");
}
#endif // DEBUG
