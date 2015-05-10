/*
 * RandomGeometricNode.cpp
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#include <RandomGeometricNode.h>
#include <stdio.h>
#include <omnetpp.h>

Register_Enum(RandomGeometricNode, (RandomGeometricNode::SCANNING, RandomGeometricNode::STANDBY,
                                    RandomGeometricNode::ADVERTISING, RandomGeometricNode::INITIATING,
                                    RandomGeometricNode::CONNECTION_MASTER, RandomGeometricNode::CONNECTION_SLAVE));
Define_Module(RandomGeometricNode);

/*--------------- CONSTRUCTOR ---------------*/
RandomGeometricNode::RandomGeometricNode() {
    this->message = NULL;
}

/*--------------- DESTROYER ---------------*/
RandomGeometricNode::~RandomGeometricNode() {
    cancelAndDelete(event);
    delete message;
}

//=============GETTERS========================
double RandomGeometricNode::getXcoordinate(){
    return this->xCoord;
}

double RandomGeometricNode::getYcoordinate(){
    return this->yCoord;
}

//==============SETTERS====================
void RandomGeometricNode::setXcoordinate(double x){
    this->xCoord = x;
}

void RandomGeometricNode::setYcoordinate(double y){
    this->yCoord = y;
}


/*---------INITIALIZATION METHOD ----------*/
void RandomGeometricNode::initialize() {

    this->xCoord = par("xCoord");
    this->yCoord = par("yCoord");

    //stateInitializazion();

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


    /*
    if(par("startTx")){
        this->message = new cMessage("MESSAGGIO 1");
        advertising();
    }else{
        initiating();
    }*/
/*
    event = new cMessage("aspetto");

    if(par("startTx")){
        this->message = new cMessage("ciao");
        scheduleAt(simTime()+3.0,event);
    }
*/
}


/*---------OTHER METHODS ---------------*/

void RandomGeometricNode::handleMessage(cMessage *msg)
{
    //PRECEDENTE


    if(msg == this->event){

        forwardMessage(this->message);

    }else if(this->message == NULL){
        setState(RandomGeometricNode::CONNECTION_SLAVE);

        EV << "class name: "<<msg->getClassName()<<endl;
        EV << "display string: "<<msg->getDisplayString()<<endl;
        EV << "name: "<<msg->getName() <<endl;


        EV << "["<<getIndex()<<"]gate index " <<msg->getArrivalGate()->getIndex()  <<endl;

        this->message = msg;

        int wait=intuniform(1,10);
        scheduleAt(simTime()+wait,event);
        EV<<"["<<getIndex()<<"]ASPETTO "<< wait << " secondi"<<endl;

    }else if(msg == this->message){
        setState(RandomGeometricNode::INITIATING);
        EV<<"FINITO"<<endl;
        delete msg;
    }



    /*

    // PARTE DI RISPOSTA A UN ADV
    switch(state)
    {
        case STANDBY: break;
        case SCANNING: break;
        case ADVERTISING: break;
        case INITIATING:
            //mando una conn_req
            forwardMessage(new cMessage("CONN_REQ"),msg->getArrivalGate()->getIndex());
            break;
        case CONNECTION_MASTER: break;
        case CONNECTION_SLAVE: break;
        default: throw cRuntimeError("Unknown status");
    }
    */

}

//PROVVISORIA
void RandomGeometricNode::forwardMessage(cMessage *msg)
{
    int nGate = gateSize("gate");

    for(int i=0; i < nGate; i++){
        cMessage *msgCopy = msg->dup();
        send(msgCopy, "gate$o", i);
    }
}

void RandomGeometricNode::forwardMessage(cMessage *msg, int gate)
{
    cMessage *msgCopy = msg->dup();
    send(msgCopy, "gate$o", gate);
}

void RandomGeometricNode::broadcastMessage(cMessage *msg)
{
    int nGate = gateSize("gate");

    for(int i=0; i < nGate; i++){
        cMessage *msgCopy = msg->dup();
        send(msgCopy, "gate$o", i);
    }
}

//================== FSA METHODS =================

void RandomGeometricNode::stateInitializazion()
{
    setState(RandomGeometricNode::STANDBY);
    //updateDisplayString();
}


void RandomGeometricNode::setState(State s)
{
    this->state = s;
    //updateDisplayString();
}

bool RandomGeometricNode::validStateTransition(State s)
{
    return false;
}
//===================UTILITY METHODS===============

void RandomGeometricNode::updateDisplayString()
{
    const char *color;

    switch(state)
    {
        case STANDBY: color = ""; break;
        case SCANNING: color = "yellow"; break;
        case ADVERTISING: color = "orange"; break;
        case INITIATING: color = "green"; break;
        case CONNECTION_MASTER: color = "blue"; break;
        case CONNECTION_SLAVE: color = "magenta"; break;
        default: throw cRuntimeError("Unknown status");
    }

    getDisplayString().setTagArg("i",1,color);

    /*
    cModule *node = getContainingNode(this);
    const char *myicon = state==UP ? origIcon.c_str() : icon;
    getDisplayString().setTagArg("i", 0, myicon);
    if (*icon)
        node->getDisplayString().setTagArg("i2", 0, icon);
    else
        node->getDisplayString().removeTag("i2");
    */
}



//================ PROTOCOL METHODS =======================

void RandomGeometricNode::advertising()
{
    if(getState() != RandomGeometricNode::ADVERTISING){
        setState(RandomGeometricNode::ADVERTISING);
    }
    broadcastMessage(new cMessage("adv"));
}

void RandomGeometricNode::initiating()
{
    if(getState() != RandomGeometricNode::INITIATING){
        setState(RandomGeometricNode::INITIATING);
    }
}
