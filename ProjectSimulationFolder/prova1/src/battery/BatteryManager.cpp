/*
 * BatteryManager.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <battery/BatteryManager.h>

BatteryManager::BatteryManager() {
    batteryLevel = 100;
}

BatteryManager::BatteryManager(int value) {
    batteryLevel = value;
}

BatteryManager::~BatteryManager() {
}


void BatteryManager::setBatteryLevel(int level){
    batteryLevel = level;
}


void BatteryManager::updateIdleBatteryLevel(){
    batteryLevel = batteryLevel - 2;
}


void BatteryManager::updateTxBatteryLevel(){
    batteryLevel = batteryLevel - 5;
    checkValue();
}

void BatteryManager::checkValue(){
    if(!isPositive())
        batteryLevel = 0;
}

bool BatteryManager::isPositive(){
    if(batteryLevel > 0)
        return true;
    else
        return false;
}
