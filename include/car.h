/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

#ifndef CAR_H
#define CAR_H

/**
 *instance variable for the car
 */
typedef struct car{
    char location;
    char direction;
    int time;
} Car;

/**
 *a constructor for the car to be created
 *@param location of the car
 *@param direction of the car
 *@param time the car arrived
 *@return the created car
 */
Car* createCar(char location, char direction, int time);

/**
 *get the location of the car
 *@param car
 *@return the location of the car
 */
char getLocation( Car * car );

/**
 *get the direction of the car
 *@param car
 *@retun the direction of the car
 */
char getDirection( Car * car );

/**
 *get the arrival time of the car
 *@param car
 *@return the time of the arrival car
 */
int getTime( Car * car );

/**
 *a toString for the output of the car
 *@param car
 *@return void
 */
void printCar( void * car );

#endif