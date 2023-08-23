#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void Linkedlist_traversial(struct Node* Head)   // It will Print the linkedlist elements.
{
    struct Node* ptr = Head;
    do{
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }while (ptr != Head);

}
struct Node* InsertAtBeginning(struct Node* Head, int data) // It will create a new node and it will add it at the beginning.
{
    struct Node *ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    
    struct Node* p = Head -> next;
    while(p -> next != Head){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = Head;
    Head = ptr;
    return Head;
}
struct Node* InsertAtSpecificIndex(struct Node* Head, int data, int index)// It will create a new node and it will add it at Specified Index.
{
    struct Node *ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;

    struct Node* p = Head;
    int i = 0;
    while( i != index - 1){
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return Head;
}
struct Node* InsertAtLast(struct Node* Head, int data)// It will create a new node and it will add it at the Last.
{
    struct Node *ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;

    struct Node* p = Head -> next;
    while(p -> next != Head){
        p = p -> next;
    }

    ptr -> next = Head;
    p -> next = ptr;

    return Head;

}
int main()
{
    // Creation Of Nodes:
    struct Node *Head, *Second, *Third, *Fourth;
    // Allocating Memory For Each Nodes:
    Head = (struct Node*)malloc(sizeof(struct Node));
    Second = (struct Node*)malloc(sizeof(struct Node));
    Third = (struct Node*)malloc(sizeof(struct Node));
    Fourth = (struct Node*)malloc(sizeof(struct Node));
    // Assigning Data To Each Nodes:
    Head -> data = 3;
    Second -> data = 7;
    Third -> data = 8;
    Fourth -> data = 10;
    // Building Linkages:
    Head -> next = Second;
    Second -> next = Third;
    Third -> next = Fourth;
    Fourth -> next = Head;

    
    Linkedlist_traversial(Head);
    
    printf("Now we are inserting one node at the beginning:\n");
    Head = InsertAtBeginning(Head, 80);
    Linkedlist_traversial(Head);

    printf("Now we are inserting one node at a specified index:\n");
    Head = InsertAtSpecificIndex(Head, 76, 2);
    Linkedlist_traversial(Head);

    printf("Now we are inserting one node at the last:\n");
     Head = InsertAtLast(Head, 20);
    Linkedlist_traversial(Head);

    return 0;
}