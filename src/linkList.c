/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*Standard Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "car.h"

List *initializeList(void (*printFunction)(void *toBePrinted), 
                     void (*deleteFunction)(void *toBeDeleted),
                     int (*compareFunction)(const void *first,const void *second)){
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->printNode = printFunction;
    list->compare = compareFunction;
    list->deleteNode = deleteFunction;
    return list;
}/*end if*/

Node *initializeNode(void *data){
    Node* node = malloc(sizeof(Node));
    node->data  = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}/*end if ini node*/

void insertBack(List * list, void *toBeAdded){
    Node* temp = list->head;
    Node* node = toBeAdded;
    if(list->head == NULL) {
        list->head = node;
    }else{
        /*Go To last Node*/
        while(temp->next != NULL){
            temp = temp->next;
        }/*end while*/
        temp->next = node;
        node->prev = temp;
        /*assign tail*/
        list->tail = node->prev;
        /*printCar(list->tail);*/
    }/*end else*/
}/*end of insert front*/

void insertFront(List *list, void *toBeAdded){
    Node* node = toBeAdded;
    if(list->head == NULL) {
        list->head = node;
    }else{
        node->prev = node;
        node->next = list->head; 
        list->head = node;
    }/*end if*/
}/*end func*/

void deleteListNode(void *toBeDeleted){
   Node* temp;
   Node* node = toBeDeleted;
   temp = node;
   node = node->next;
   free(temp);
}/*end delete list*/

void deleteList(List *list){
   Node* temp;
   Node* node = list->head;
   while (node != NULL){
       temp = node;
       node = node->next;
       free(temp);
    }/*end while*/
}/*end function*/

int deleteNodeFromList(List *list, void *toBeDeleted){
    Node* deleting = toBeDeleted;

    if(list->head != NULL && deleting != NULL){

        if(list->head == deleting){
            list->head = deleting->next;
        }
        if(deleting->next != NULL){
            deleting->next->prev = deleting->prev;
        }
        if(deleting->prev != NULL){
            deleting->prev->next = deleting->next;     
        }
        return 1;
    }else if (list->head == NULL){
        printf("List is empty\n");
        deleting = NULL;
        return 0; 
    }else if (deleting == NULL){
        printf("Node is empty");
        deleting = NULL;
        return -1;
    }/*end if*/

    free(deleting);    
    return 0;
}/*end func*/

void *getFromFront(List *list){
    if (list->head != NULL){
        return list->head;  
    }else{
        return list->head = NULL;
    }
}/*end if*/

void *getFromBack(List *list){
    if (list->tail != NULL){
        return list->tail;
    }else{
        return list->tail = NULL;
    }
}/*end if*/

/* To sort the linked list */
void sortList(List * list){
    /*decalare var*/
    Node *start = list->head;
    Node *move;
    Node *min;
    Node* temp;
    /*loop throu the list*/
    while(start->next){
        min = start;
        move = start->next;
        while(move){
            /*Find minimum value in the lisr*/ 
            if( min->data > move->data ){
                min = move;
            }/*end if*/
            move = move->next;
        }/*end while*/
        /*swap the list*/
        temp = start->data;
        start->data = min->data;
        min->data = temp;
        start = start->next;
    }/*end while*/
}/*end func*/

void insertSorted(List *list, void *toBeAdded){
    sortList(list);
    insertBack(list, toBeAdded);
}/*end func*/

void printForward(List * list){
    Node* temp = list->head;
    if(temp != NULL) {
        /*move forwawrd using next pointer*/
        printf("Print forward... \n");
        while(temp != NULL) {
            printCar(temp);
            printf("\n");
            temp = temp->next;
        }/*end while*/
        printf("\n");
    }/*end if*/
}/*end moving car*/

void printBackwards(List * list){
    Node* temp = list->tail;
    if(temp != NULL) {
        /*move backward using prev pointer*/
        printf("Print backward... \n");
        while(temp != NULL) {
            printCar(temp);
            printf("\n");
            temp = temp->prev;
        }/*end while*/
        printf("\n");
    }/*end if*/
}/*end moving car*/