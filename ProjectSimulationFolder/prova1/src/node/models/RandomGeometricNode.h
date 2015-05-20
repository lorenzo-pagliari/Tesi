/*
 * RandomGeometricNode.h
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#ifndef RandomGeometricNode_H_
#define RandomGeometricNode_H_

#include <csimplemodule.h>
#include <OPCode.h>
#include <ProtocolManager.h>
#include "btmessage_m.h"
#include <BatteryManager.h>

class RandomGeometricNode: public cSimpleModule{

public:
    enum State { SCANNING, STANDBY, ADVERTISING, INITIATING, CONNECTION_MASTER, CONNECTION_SLAVE, START};

private:
    double xCoord;
    double yCoord;
    bool busy;
    int gateBinded;
    int advCounter;
    int txCounter;
    ProtocolManager *protocolManager;
    State state;
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

    //Trasmission methods
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
    void nodeInitializazion();

    //====FSA METHODs
private:
    bool validStateTransition(State);
public:
    void setState(State);
    virtual State getState() const { return state; }

    //====MESSAGE METHODS
protected:
    virtual const char *createTag(cMessage *);
    BTMessage *createMessage(int,const char *);
    BTMessage *createAckMessage(const char *);
    BTMessage *createAdvIndMessage(const char *);
    BTMessage *createConnReqMessage(const char *);
    BTMessage *createDataMessage(const char *);
    BTMessage *createStartTxMessage(const char *);
    BTMessage *createTerminateTxMessage(const char *);


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
