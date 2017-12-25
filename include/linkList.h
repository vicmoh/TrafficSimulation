/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

#ifndef LINKLIST_H
#define LINKLIST_H

/**
 *create the node for the linklist
 */
typedef struct listNode{
    void *data;
    struct listNode *prev;
    struct listNode *next;
} Node;

/**
 *create the linklist
*/
typedef struct listHead{
    Node *head;
    Node *tail;
    void (*deleteNode)(void *toBeDeleted);
    int (*compare)(const void *first,const void *second);
    void (*printNode)(void *toBePrinted);
} List;

/**
 *initialize the linklist
 *@param printFuntion
 *@param deleteFunction
 *@param compareFunction
 */
List *initializeList(void (*printFunction)(void *toBePrinted), 
                     void (*deleteFunction)(void *toBeDeleted),
                     int (*compareFunction)(const void *first,const void *second));

/**
 *init the node
 *@param data
 *@return the node
 */
Node *initializeNode(void *data);

/**
 *insert the node to the back of the list
 *@param list
 *@param toBeAdded the node to be added
 */
void insertBack(List *list, void *toBeAdded);

/**
 *insert the node to the front of the list
 *@param list
 *@param toBeAdded which is the node to be added
 */
void insertFront(List *list, void *toBeAdded);

/**
 *get the node from the head
 *@param list
 */
void *getFromFront(List *list);

/**
 *get the node from the tail
 *@param list
 */
void *getFromBack(List *list);

/**
 *delete Node from the list
 *@param list
 *@param toBeDeleted the node to be deleted
 *@return the condition of the deletion
 */
int deleteNodeFromList(List *list, void *toBeDeleted);

/**
 *delete node on the list
 *@param toBeDeleted
 */
void deleteListNode(void *toBeDeleted);

/**
 *delete the whole list
 *@param list to be deleted
 */
void deleteList(List *list);

/**
 *sort the list
 *@param list
 */
void sortList(List * list);

/**
 *insert the list sorted
 *@param list
 *@param toBeAdded
 */
void insertSorted(List *list, void *toBeAdded);

/**
 *print the list forward
 *@param list
 */
void printForward(List * list);

/**
 *print backwards
 *@param list
 */
void printBackwards(List * list);

#endif