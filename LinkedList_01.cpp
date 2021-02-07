#include <iostream>
#include <stdlib.h>
using namespace std;

/* SINGLY LINKED LIST INSERTION OPERATION :
1. Insert Node at first place
2. Insert Node at End.
3. Insert Node between any node.
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
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "->NULL";
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

int main()
{
    struct Node *start;
    start = (struct Node *)malloc(sizeof(struct Node *));
    start = AtFirst(start, 9);
    start = AtFirst(start, 9);
    start = AtBetween(start,10,2);
    start = AtEnd(start,15);
    Traverse(start);
    return 0;
}