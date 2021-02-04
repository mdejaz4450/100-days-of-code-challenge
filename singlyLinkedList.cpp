#include<iostream>
using namespace std;

/*Single Linked List
Some operations we will perform here.
1. Traversing
2. 
*/

class SinglyLinkedList
{
    public:
    int data;
    SinglyLinkedList* Next; // Next refrence of node of class type.    
};

 void PrintList(SinglyLinkedList* head){
     printf("WELCOME TO THE 100 DAYS OF CODE CHALLENGE!\n");

     while (head != NULL)
     {
         cout<<head->data<<" ";
         head = head->Next;
     }
           
}

int main(){
    SinglyLinkedList* head = NULL;
    SinglyLinkedList* second = NULL;
    SinglyLinkedList* third = NULL;


    // allocate memory using new keyword in C++.
    head = new SinglyLinkedList();
    second = new SinglyLinkedList();
    third = new SinglyLinkedList();


    //Dynamic Memory allocation in C language using malloc function.
   // third = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList*));

   head->data = 8;
   head-> Next = second;

   second ->data = 7;
   second ->Next = third;

   third ->data = 4;
   third ->Next = NULL; // Here linked list is terminated.

   PrintList(head);
   return 0;
}

