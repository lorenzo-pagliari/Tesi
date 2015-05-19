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
#include "btmessage_m.h"

class RandomGeometricNode: public cSimpleModule{

public:
    enum State { SCANNING, STANDBY, ADVERTISING, INITIATING, CONNECTION_MASTER, CONNECTION_SLAVE, START};

private:
    double xCoord;
    double yCoord;
    //cMessage *message;
    BTMessage *message;
    cMessage *timer;
    State state;
    int advCounter;
    int txCounter;
    int advLimit;
    int dynamicFanout;
    bool busy;
    int gateBinded;

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

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *);
    virtual void forwardMessage(cMessage *);
    virtual void forwardMessage(cMessage *, int);
    void broadcastMessage(cMessage *);

    //=====UTILITY METHODS
protected:
    void updateDisplayString();


    //====FSA METHODs
private:
    bool validStateTransition(State);
protected:
    void stateInitializazion();
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
    //stato di comodo per la partenza
    void start();
    //altri stati reali
    void standby();
    void advertising();
    void initiating();
    void connectionMaster();
    void connectionSlave();
};

#endif /* RandomGeometricNode_H_ */
