#include <stdlib.h>
#include <stdio.h>

//node struct
typedef struct node{
    int value;
    struct node* next;
} node_t;


/*function that dynamically creates linked lists. 
  returns a node pointer*/

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;

    return result;
}

void printlist (node_t *head){
    node_t *temporary = head;

    //loop to print linked list
    while(temporary != NULL){
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert){
    //node_to_insert represents tmp
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert; 
}

void *insert_after_node(node_t *node_to_insert_after, node_t *newnode){
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value){
    node_t *tmp = head;

    while (tmp != NULL){
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }

    return NULL; 
}



int main(){
    node_t *head = NULL;
    node_t *tmp;

   /*for (int i = 0; i < 100; i++){
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
       
    } 
    printlist(head);
    */ 
    
   //the following code is an alternative to the above loop

   for (int i=0; i < 100;i++){
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
   }
    
   
    tmp = find_node(head, 24);
    printf("found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(75));
    
    printlist(head);

    /*tmp = create_new_node(24);
    head = tmp;
    tmp = create_new_node(32);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(45);
    tmp->next = head;
    head = tmp;
    */
    
    //printlist(head);
    return 0;

}