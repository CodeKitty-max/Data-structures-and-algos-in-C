#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
    //info to add later
} person;


//hash table
person *hash_table[TABLE_SIZE];

//HASH ALGO
unsigned int hash(char* name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i<length; i++){
        hash_value += name[i];//summation of ascii characters
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
} 

//initializing empty hash table 
void init_hash_table(){
    for (int i = 0;i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    
}

//Prints the values present in the hash table 
void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("_________________________________\n");
}

//Function to insert a person into a table
bool hash_table_insert(person *p){
    //true if we successfully insert a person and false if we don't
    if(p == NULL) return false;
    int index = hash(p->name);

    //removing collisions
    for (int i=0; i< TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            hash_table[try] = p;
            return true;
        }
    }    
    /*
    //chech if pointer isn't NULL in order to add a person
    if(hash_table[index] != NULL){
        return false;
    }
    //if spot is available, we point to the new person
    hash_table[index] = p;
    */
    
    return false;

}
//Check if a person is in the table using their name
person *hash_table_lookup (char *name){
    //computing hash on the name
    int index = hash(name);
    
    //if the person at that index exists and the names match the searched name
    if(hash_table[index] != NULL &&
       strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
        return hash_table[index];
       } else {
        return NULL;
       }


}

person *hash_table_delete(char *name){
    //computing hash on the name
    int index = hash(name);
    
    //if the person at that index exists and the names match the searched name
    if(hash_table[index] != NULL &&
       strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
       } else {
            return NULL;
       }
}

//understanding how name above works
unsigned int und_name(char* name){
    int length = strnlen(name, MAX_NAME);
    for(int i= 0; i<length; i++){
        printf("%d\n", name[i]);
    }
}

int main(){
    //initializing empty table
    init_hash_table();

    //printing the values that are in the tabke
    print_table();

    //making some people
    person Jacob = {.name = "Jacob", .age = 43};
    person Nat = {.name = "Nat", .age = 3};
    person Sara = {.name = "Sara", .age = 36};

    hash_table_insert(&Jacob);
    hash_table_insert(&Nat);
    hash_table_insert(&Sara);


    print_table();

    int jacob_index = hash(&Jacob);
    printf("j_i: %d\n", jacob_index);

    //checking for the existence of a person in the table
    person *tmp = hash_table_lookup(&Jacob); // inputting the string of the name("Jacob") also works
    
    if (tmp == NULL){
        printf("Not found!\n");
    }else{
        printf("Found: %s\n", tmp->name);
    }
    

    /*
    printf("Jacob => %u\n", und_name("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    */
    
    return 0;
}