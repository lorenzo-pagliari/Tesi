/*
 * RandomGeometricNode.h
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#ifndef RandomGeometricNode_H_
#define RandomGeometricNode_H_

#include <csimplemodule.h>

class RandomGeometricNode: public cSimpleModule{

public:
    enum State { SCANNING, STANDBY, ADVERTISING, INITIATING, CONNECTION_MASTER, CONNECTION_SLAVE};

private:
    double xCoord;
    double yCoord;
    cMessage *message;
    cMessage *event;
    State state;

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
    /*
    // The following redefined virtual function holds the algorithm.
    virtual cMessage *generateNewMessage();
    virtual void sendCopyOf(cMessage *msg);
    virtual void handleMessage(cMessage *msg);
    */
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
    bool validStateTransition(State s);
protected:
    void stateInitializazion();
public:
    void setState(State s);
    virtual State getState() const { return state; }


    //====PROTOCOL METHODS
protected:
    void advertising();
    void initiating();
};

#endif /* RandomGeometricNode_H_ */
