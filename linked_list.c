//Linked list:Inserting a node at beginning
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;//Want to create a linked list of ints
    struct Node* next;//Stores address of next node in linked list
};

struct Node* head;//Pointer to head node 

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;//used only when the list is empty
    head = temp;
}   

void Print()
{
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int  main(){
    head = NULL;  //empty list
    printf("How many numbers? \n"); //Asking user for number of items in linked list
    int n, i, x;
    scanf("%d",&n);//number of ints to be stored in linked lists
    for(i = 0; i<n;i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }


}