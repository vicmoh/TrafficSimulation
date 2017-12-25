/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*import library*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include "car.h"
#include "linkList.h"
#include "dummy.h"
#include "simulation.h"

#define GREEN_TIME 10
#define YELLOW_TIME 3
#define RED_TIME 14
#define SAFETY_TIME 1

#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2
#define RED_LIGHT 4
#define SAFETY_LIGHT 3

#define RIGHT_TIME 1
#define FORWARD_TIME 2
#define LEFT_TIME 2.5

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

/*main*/
int main( int argc, char **argv){
    /*declare var*/
    char const* const fileName = argv[1];
    FILE* filePointer;
    filePointer = fopen(fileName, "r");
    char carLocation, carDirection;
    int arrivalTime = 0;
    int numOfScan = 0;
    int numOfLine = 0;
    double timer = 1;

    /*if file doesnt exist*/
    if(filePointer == NULL) {
        printf("No such file\n");
        return 0;
    }/*end if*/

    /*create the four road intersection*/
    List * northList = initializeList(dummyPrint, dummyDelete, dummyCompare);
    List * southList = initializeList(dummyPrint, dummyDelete, dummyCompare);
    List * eastList = initializeList(dummyPrint, dummyDelete, dummyCompare);
    List * westList = initializeList(dummyPrint, dummyDelete, dummyCompare);
    List * sortedList = initializeList(dummyPrint, dummyDelete, dummyCompare);

    /*scan until end of file*/
    while(numOfScan != EOF){
        numOfLine = numOfLine + 1;
        numOfScan = fscanf(filePointer, "%c %c %d\n", &carLocation, &carDirection, &arrivalTime);
        //printf("Line %d: %c %c %d\n", numOfLine, carLocation, carDirection, arrivalTime);
        void * car = createCar(carLocation, carDirection, arrivalTime);
        insertBack(sortedList, car);
    }/*end while*/

    /*delete the weird random extra car at the end*/
    deleteNodeFromList(sortedList, getFromBack(sortedList));

    /*sort the list
    sortList(sortedList);
    printForward(sortedList);*/

    /*go throught the list and assign the car the road*/
    Node* tempList = sortedList->head;
    if(tempList != NULL) {
        while(tempList != NULL) {
            void* getTemp = tempList;
            if(getLocation(getTemp) == 'N'){
                carLocation = getLocation(getTemp);
                carDirection = getDirection(getTemp);
                arrivalTime = getTime(getTemp);
                void * car = createCar(carLocation, carDirection, arrivalTime);
                insertBack(northList, car);
            }else if(getLocation(getTemp) == 'S'){ 
                carLocation = getLocation(getTemp);
                carDirection = getDirection(getTemp);
                arrivalTime = getTime(getTemp);
                void * car = createCar(carLocation, carDirection, arrivalTime);
                insertBack(southList, car);
            }else if(getLocation(getTemp) == 'E'){
                carLocation = getLocation(getTemp);
                carDirection = getDirection(getTemp);
                arrivalTime = getTime(getTemp);
                void * car = createCar(carLocation, carDirection, arrivalTime);
                insertBack(eastList, car);
            }else if(getLocation(getTemp) == 'W'){
                carLocation = getLocation(getTemp);
                carDirection = getDirection(getTemp);
                arrivalTime = getTime(getTemp);
                void * car = createCar(carLocation, carDirection, arrivalTime);
                insertBack(westList, car);
            }
            tempList = tempList->next;
        }/*end while*/
    }/*end if*/

    /*print the car location
    printf("North road...\n");
    printForward(northList);
    printf("East road...\n");
    printForward(eastList);
    printf("South road...\n");
    printForward(southList);
    printf("West road...\n");
    printForward(westList);
    printf("******************************************************************\n");*/
    printf("Initial Vehicle\t\tArrival Time\t\tCompleted at Time\n");

    /*variable for the traffic light*/
    double completedTime = 0;
    int trafficTurn = NORTH;
    int exit = 0;
    List* currentList = northList;
    /*go through the traffic light*/
    while(exit < 4){
        if(trafficTurn == NORTH){
            currentList->head = northList->head;
            if (currentList->head != NULL){
                timer = trafficRun(currentList, completedTime, timer);
            }
            trafficTurn = EAST;
        }else if(trafficTurn == EAST){
            currentList->head = eastList->head;
            if (currentList->head != NULL){
                timer = trafficRun(currentList, completedTime, timer);
            }
            trafficTurn = SOUTH;
        }else if(trafficTurn == SOUTH){
            currentList->head = southList->head;
            if (currentList->head != NULL){
                timer = trafficRun(currentList, completedTime, timer);
            }
            trafficTurn = WEST;
        }else if(trafficTurn == WEST){
            currentList->head = westList->head;
            if (currentList->head != NULL){
                timer = trafficRun(currentList, completedTime, timer);
            }
            trafficTurn = NORTH;
        }/*end if*/

        exit++;

        if (northList->head == NULL && southList->head == NULL &&
            westList->head == NULL && eastList->head == NULL){
            exit = 5;
            break;
        }
    }/*end while*/
    return 0;
}/*end main*/ 