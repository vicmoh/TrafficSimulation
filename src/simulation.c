/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*import library*/
#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"
#include "linkList.h"
#include "car.h"

double getCompletedTime(List * carList, void * carNode, double completedTime, double timer){
    /*if the car time is the same as the timer*/
    if(getTime(carNode) <= timer){
        if(getDirection(carNode) == 'F'){
            completedTime = timer + FORWARD_TIME;  
        }else if(getDirection(carNode) == 'L'){
            completedTime = timer + LEFT_TIME;
        }else if(getDirection(carNode) == 'R'){
            completedTime = timer + RIGHT_TIME;
        }/*end if*/
        printCar(carNode);
        printf("\t %d \t\t\t %.2f\n", getTime(carNode), completedTime);
        deleteNodeFromList(carList, carNode);
    }/*end if*/
    return completedTime;
}/*end function*/

int trafficRun(List * currentList, double completedTime, double timer){
    int x;
    for(x=0; x<GREEN_TIME;x++){
        if (currentList->head != NULL){
            completedTime = getCompletedTime(currentList, getFromFront(currentList), completedTime, timer);
            //printf("Time: %d\n", timer);
        }
        timer++;
    }/*end for*/

    for(x=0; x<YELLOW_TIME;x++){
        if (currentList->head != NULL){
            /*if the car time is the same as the timer*/
            if(getTime(getFromFront(currentList)) <= timer){
                /*if the car is going left on yello*/
                if(getDirection(getFromFront(currentList)) == 'L'){
                    completedTime = timer + LEFT_TIME;  
                    x=YELLOW_TIME+1;
                }/*end if */
                printCar(getFromFront(currentList));
                printf("\t %d \t\t\t %.2f\n", getTime(getFromFront(currentList)), completedTime);
                deleteNodeFromList(currentList, getFromFront(currentList));
            }/*end if*/
            //printf("Time: %d\n", timer);
        }
        timer++;
    }/*end for*/
    return timer;
}/*end func*/