/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include "linkList.h"

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

/**
 *get the completed time of the car
 *@param carlist the list of the car
 *@param carNode the node of the car
 *@param complatedTime the current complated time
 *@param timer
 *@return the completed time of the calculation
 */
double getCompletedTime(List * carList, void * carNode, double completedTime, double timer);

/**
 *program that calculate the timer of the car
 *@param currentList
 *@param completedTime
 *@param timer
 *@return the new timer of the calculation
 */
int trafficRun(List * currentList, double completedTime, double timer);

#endif