#include <iostream>
#include <stdlib.h>
using namespace std;

/* SINGLY LINKED LIST INSERTION OPERATION :
1. Insert Node at first place
2. Insert Node at End.
3. Insert Node between any node.
4. Delete First Node
5. Delete Last Node
6. Delete at any point.
*/

struct Node
{
    int data;
    Node *next;
};

//Display list
void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "-> ";
        ptr = ptr->next;
    }
    cout << "NULL" <<endl;
}

// Insert at first index;
struct Node *AtFirst(struct Node *start, int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = value;
    newNode->next = start;
    return newNode;
}

// Insert at between any node.
struct Node *AtBetween(struct Node *start, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *ptr = start;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return start;
}

// Insert at the end.
struct Node *AtEnd(struct Node *start, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;

    struct Node *ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->next = NULL;
    ptr->next = newNode;
    return start;
}

// 1. Delete First Node
struct Node* DeleteFirstNode(struct Node* start){
    struct Node* ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

// 2. Delete last Node
struct Node* DeleteLastNode(struct Node* start){
    struct Node* ptr = start;
    struct Node* p = start->next;
    
    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next;
        
    }
    ptr->next = p->next;
    free(p);
    return start;
}
// 3. Delete Node at any point.
struct Node* DleteAnyPoint(struct Node* start, int index)
{
    struct Node* ptr = start;
    struct Node* temp = start->next;
    
   for(int i = 0; i< index-1 ; i++){
       ptr = ptr->next;
       temp = temp -> next;
   }
    ptr ->next = temp -> next; // ptr link to next node of temp.
    free(temp);
    return start;
    
}

int main()
{
    struct Node *start;
    start = (struct Node *)malloc(sizeof(struct Node *));
    start = AtFirst(start, 9);
    start = AtFirst(start, 9);
    start = AtBetween(start,10,2);
    start = AtEnd(start,15);
    Traverse(start);

    
    start = DleteAnyPoint(start,1);
    Traverse(start);
    
    start = DeleteLastNode(start);
    Traverse(start);
    
    return 0;
}