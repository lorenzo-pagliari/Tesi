/*
 * DynamicFanout.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <DynamicFanout.h>
#include <math.h>

DynamicFanout::DynamicFanout() {

}

DynamicFanout::~DynamicFanout() {

}

//====================BOUND METHOD===================
void DynamicFanout::updateValue(cSimpleModule *node,BatteryManager *battery){

    int numNeighborDevice = node->gateSize("gate");
    double batFactor;
    double result;

    /*
     * This formula is:
     *
     *      x = battery % (10-100)
     *
     *      y= RAD.Q(0.2*x -1.9)/10
     */
    batFactor = ceil(sqrt(0.2*((double)battery->getBatteryLevel())-1.9)/10);

    /*
     * The total formula is
     *
     *              x = number of devices linked
     *
     *      new fanout = -0.0000004x^4 + RADQ(0.2*battery -1.9)/10
     */
    result = batFactor * numNeighborDevice - 0.0000004 * pow(numNeighborDevice,4);

    value = ceil(result);

    checkValue();
}

void DynamicFanout::checkValue(){
    if(!isPositive())
        value=0;
}

bool DynamicFanout::isPositive(){
    if(value > 0)
        return true;
    else
        return false;
}
