//inserting a node at the nth position 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
//data represents the value to be inserted;n represents the position of insertion
void Insert(int data, int n){
    struct Node* temp1 = malloc(sizeof(struct Node*));
    temp1->data = data;
    temp1->next = NULL;
    //special case to deal with the first value
    if (n==1){
        temp1->next= head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head; 
    for(int i = 0;i<n-2;i++)
    {
        temp2 = temp2->next;

    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}
void Print(){
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL;//initially it is empty
    Insert(2,1);//List: 2
    Insert(3,2);//List:2, 3
    Insert(4,3);
    Insert(5,4);
    Print();

}