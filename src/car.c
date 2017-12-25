/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*Standard Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"

Car* createCar(char location, char direction, int time){
    Car* car = malloc(sizeof(Car));
    car->location  = location;
    car->direction = direction;
    car->time  = time;
    return car;
}//end car

char getLocation( Car * car ) { 
    return car->location;
}//end func

char getDirection( Car * car ) { 
    return car->direction;
}//end func

int getTime( Car * car ) { 
    return car->time;
}//end func

void printCar( void * car ) {
    printf("%c %c %d \t\t", getLocation(car), getDirection(car), getTime(car));
}//end print