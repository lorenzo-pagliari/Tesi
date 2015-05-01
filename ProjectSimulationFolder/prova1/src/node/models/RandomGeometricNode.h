/*
 * RandomGeometricNode.h
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#ifndef RandomGeometricNode_H_
#define RandomGeometricNode_H_

#include <csimplemodule.h>

class RandomGeometricNode: public cSimpleModule {

private:
    double xPos,yPos;
    cMessage *message;
    cMessage *event;

public:
    //Constructor
    RandomGeometricNode();
    //Destroyer
    virtual ~RandomGeometricNode();

    //Getters
    double getXPos() const;
    double getYPos() const;

    //Setters
    void setXPos(double xpos);
    void setYPos(double ypos);

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
};

#endif /* RandomGeometricNode_H_ */
