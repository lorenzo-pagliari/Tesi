/*
 * AdvertiseLimit.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <AdvertiseLimit.h>

AdvertiseLimit::AdvertiseLimit() {

}

AdvertiseLimit::~AdvertiseLimit() {
}

//====================BOUND METHOD===================
void AdvertiseLimit::updateValue(cSimpleModule *node, BatteryManager *battery){

    int numNeighborDevice = node->gateSize("gate");
    double batFactor;
    double result;


    /*
     *  VERSION 0.1
     * This formula is:
     *
     *      x = battery % (10 - 100)
     *
     *      y= x/100
     *
     *
     * The total formula n°0.1 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = %battery*(-0.92^(x-20) +5)
     */
    //batFactor = (double)battery->getBatteryLevel()/(double)100;
    //result = batFactor * (-pow(0.92,numNeighborDevice-20) + 5);

    /*
     * VERSION 1
     * The total formula n°1 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = %battery*(ln(2x)+1)
     */
     //result = batFactor * (log(2*numNeighborDevice) + 1);

    /*
     * VERSION 2
     * The total formula n°2 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = ln(2x)+1
     */
    result = log(2*numNeighborDevice) + 1;

    /*
     * VERSION 3
     * The total formula n°3 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = ln(2x)+1 - log(2x)
     */
    //result = log(2*numNeighborDevice) + 1 log10(2*numNeighborDevice);


    value = ceil(result);

    checkValue();
}

void AdvertiseLimit::checkValue(){
    if(!isPositive())
        value=0;
}

bool AdvertiseLimit::isPositive(){
    if(value > 0)
        return true;
    else
        return false;
}
