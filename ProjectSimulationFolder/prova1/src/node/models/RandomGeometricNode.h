/*
 * RandomGeometricNode.h
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#ifndef RandomGeometricNode_H_
#define RandomGeometricNode_H_

#include <csimplemodule.h>
#include <ProtocolManager.h>
#include <BatteryManager.h>
#include <BTFsaManager.h>
#include <BTMessageGenerator.h>

class RandomGeometricNode: public cSimpleModule{

private:
    double xCoord;
    double yCoord;
    bool busy;
    int gateBinded;
    int advCounter;
    int txCounter;
    ProtocolManager *protocolManager;
    BTFsaManager *btFsaManager;
    BTMessage *message;
    cMessage *timer;
    cMessage *periodicActionsTimer;
    BatteryManager *batteryManager;


public:
    //Constructor
    RandomGeometricNode();
    //Destroyer
    virtual ~RandomGeometricNode();

    //GETTERS
    double getXcoordinate();
    double getYcoordinate();

    //SETTERS
    void setXcoordinate(double);
    void setYcoordinate(double);

private:
    void nodeInitializazion();

    //Trasmission & Receive methods
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *);
    virtual void forwardMessage(cMessage *);
    virtual void forwardMessage(cMessage *, int);
    void broadcastMessage(cMessage *);

    //=====UTILITY METHODS
protected:
    void updateDisplayString(const char *,int,const char *);
    void updateIconDisplayString();
    void updateTagDisplayString();

private:
    //FSA METHOD
    void switchState(BTState);

    //====PROTOCOL METHODS
protected:
    //fake method only for start the simulation
    void start();
    //real fsa state methods
    void standby();
    void advertising();
    void initiating();
    void connectionMaster();
    void connectionSlave();

    void periodicActions();
};

#endif /* RandomGeometricNode_H_ */
