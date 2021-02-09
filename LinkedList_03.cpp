#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Display data
void Display(struct Node* start)
{
    struct Node* p = start;
    
    do{
        cout<<p->data<< " -> ";
        p = p->next;
        
    }while(p != start);
    cout<<"NULL"<<endl;
}

// insert Node at last in Circular list
struct Node* insertAtLast(struct Node* start, int data)
{
    struct Node* ptr, *p;
    ptr = (struct Node*)malloc(sizeof(struct Node*));
    
    ptr->data = data;
    p = start;
    
    while(p->next != start)
    {
        p = p-> next;
    }
    p-> next = ptr;
    ptr->next = start;
    
    return start;
}

// insert Linked List at first ;

struct Node* AtFirst(struct Node* start, int data)
{
    struct Node* ptr, *p;
    ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr->data = data;
    
    p = start->next;
    
    while(p-> next != start)
    {
        p = p->next;
    }
    p-> next = ptr;
    ptr->next = start;
    start = ptr;
    return start;
}

int main ()
{
  cout <<"------------------------- Circular Linked List -------------------------"<<endl;
  struct Node* start; // (struct Node*)malloc(sizeof(struct Node*));
  struct Node* second; //= (struct Node*)malloc(sizeof(struct Node*));
  struct Node* third;//= (struct Node*)malloc(sizeof(struct Node*));
  struct Node* fourth; 
  
  // memory allocation in heap
  start = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  fourth = (struct Node*)malloc(sizeof(struct Node));
  
  start->data = 12;
  start -> next = second;
  
  second->data = 15;
  second-> next = third;
  
  third->data = 25;
  third-> next = start;

  Display(start);
  start = insertAtLast(start,45);
  Display(start);
  
  start = AtFirst(start,60);
  Display(start);
  return 0;
}

