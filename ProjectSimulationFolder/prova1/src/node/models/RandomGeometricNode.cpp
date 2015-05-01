/*
 * RandomGeometricNode.cpp
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#include <RandomGeometricNode.h>
#include <stdio.h>
#include <omnetpp.h>


Register_Class(RandomGeometricNode);

/*--------------- CONSTRUCTOR ---------------*/
RandomGeometricNode::RandomGeometricNode() {
    this->xPos = 0;
    this->yPos = 0;
    this->message = NULL;
}

/*--------------- DESTROYER ---------------*/
RandomGeometricNode::~RandomGeometricNode() {
    cancelAndDelete(event);
    delete message;
}

/*--------------- GETTER ---------------*/
double RandomGeometricNode::getXPos() const {
    return xPos;
}

double RandomGeometricNode::getYPos() const {
    return yPos;
}

/*--------------- SETTER ---------------*/
void RandomGeometricNode::setXPos(double xPos) {
    this->xPos = xPos;
}

void RandomGeometricNode::setYPos(double yPos) {
    this->yPos = yPos;
}

/*---------INITIALIZATION METHOD ----------*/
void RandomGeometricNode::initialize() {

    this->xPos = par("xPos");
    this->yPos = par("yPos");

    /*
     * il posizionamento grafico non è molto efficace in quanto
     * posiziona secondo pixel e non secondo presunte unità
     * di misura
     *
    char b[20];
    sprintf(b, "%lf", this->xPos);
    getDisplayString().setTagArg("p",0,b);

    sprintf(b, "%lf", this->yPos);
    getDisplayString().setTagArg("p",1,b);
    */

    event = new cMessage("aspetto");

    if(par("startTx")){
        this->message = new cMessage("ciao");
        scheduleAt(simTime()+3.0,event);
    }
}


/*---------OTHER METHODS ---------------*/

void RandomGeometricNode::handleMessage(cMessage *msg)
{
    if(msg == this->event){

        forwardMessage(this->message);

    }else if(this->message == NULL){

        EV << "["<<getIndex()<<"]gate index " <<msg->getArrivalGate()->getIndex()  <<endl;

        this->message = msg;

        int wait=intuniform(1,10);
        scheduleAt(simTime()+wait,event);
        EV<<"["<<getIndex()<<"]ASPETTO "<< wait << " secondi"<<endl;

    }else if(msg == this->message){
        delete msg;
    }
}


void RandomGeometricNode::forwardMessage(cMessage *msg)
{
    int nGate = gateSize("g");

    for(int i=0; i < nGate; i++){
        cMessage *msgCopy = msg->dup();
        send(msgCopy, "g$o", i);
    }
}
