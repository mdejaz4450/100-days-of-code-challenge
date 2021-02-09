#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

//DOUBLY LINKED LIST:

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void linkedListTraversal(struct Node *head)
{
    while(head != NULL){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<" NULL"<<endl;
}

int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;
    head -> prev = NULL;

    second->data = 3;
    second->next = third;
    second -> prev = head;

    third->data = 6;
    third->next = fourth;
    third -> prev = second;

    fourth->data = 1;
    fourth->next = NULL;
    fourth ->prev = third;


    linkedListTraversal(head);
    return 0;
}