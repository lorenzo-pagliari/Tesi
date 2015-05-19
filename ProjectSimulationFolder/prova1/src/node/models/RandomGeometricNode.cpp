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
                                    RandomGeometricNode::CONNECTION_MASTER, RandomGeometricNode::CONNECTION_SLAVE,
                                    RandomGeometricNode::START));
Define_Module(RandomGeometricNode);

/*--------------- CONSTRUCTOR ---------------*/
RandomGeometricNode::RandomGeometricNode() {
    this->message = NULL;
    this->timer = NULL;
    advCounter = 0;
    txCounter = 0;
    advLimit = 2;
    dynamicFanout = 2;
    busy = false;
    gateBinded = -1;
}

/*--------------- DESTROYER ---------------*/
RandomGeometricNode::~RandomGeometricNode() {
    if(timer!=NULL) cancelAndDelete(timer);
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

    stateInitializazion();

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

    timer = new cMessage("timeout");

    if(par("startTx")){
        message = createDataMessage("Oggi piove !!");

        //starting state
        //is equivalent to the call to advertising(),
        //but in this way is possible to see the visual
        //effect of the first broadcasting
        start();

    }else{
        initiating();
    }

/*
    if(par("startTx")){
        message = new cMessage("CIAO");
        setState(RandomGeometricNode::ADVERTISING);
        scheduleAt(simTime()+3.0,timer);
    }else{
        initiating();
    }
*/
}


/*---------OTHER METHODS ---------------*/

void RandomGeometricNode::handleMessage(cMessage *msg)
{

    BTMessage *btmsg = NULL;
    BTMessage *temp = NULL;
/*
    EV<<"["<<getIndex()<<"]precast iniziale" <<endl;

    EV<<"["<<getIndex()<<"]ricevuto " <<msg <<endl;
    EV<<"["<<getIndex()<<"]ricevuto *" <<dynamic_cast<BTMessage * >(msg) <<"*"<<endl;
*/
    if(dynamic_cast<BTMessage * >(msg) != NULL){
        btmsg = check_and_cast<BTMessage *>(msg);

        //EV<<"["<<getIndex()<<"]ricevuto " <<btmsg <<"/"<<btmsg->getTag()<<"/"<<btmsg->getPdu() <<endl;
    }

    switch(state)
    {
        case STANDBY: delete btmsg; break;
        case SCANNING: delete btmsg; break;
        case ADVERTISING:

            if(msg == timer){
                //no reply to ADV_IND
                //re-broadcast
                if(advCounter < advLimit){
                    advertising();
                }else{
                    standby();
                }

            }else{

                //CONN_REQ check
                if(btmsg->getOpcode() == OPCode::CONN_REQ &&
                    this->message!=NULL && strcmp(btmsg->getPdu(),this->message->getTag())==0){

                    //request confermed, reset timer
                    cancelEvent(timer);
                    advCounter = 0;
                    gateBinded = btmsg->getArrivalGate()->getIndex();

                    //delete btmsg;
                    connectionSlave();
                }

                //Request no confermed, msg discarded.
                delete btmsg;
            }
            break;

       case INITIATING:

            //check ADV_IND
            if(btmsg->getOpcode()==OPCode::ADV_IND){

                //check if message has already been received
                if(this->message==NULL || strcmp(btmsg->getPdu(),this->message->getTag())!=0){

                    //have not the message, send a CONN_REQ
                    temp = createConnReqMessage(btmsg->getPdu());
                    forwardMessage(temp,btmsg->getArrivalGate()->getIndex());



                    gateBinded = btmsg->getArrivalGate()->getIndex();

                    delete temp;
                    delete btmsg;

                    connectionMaster();
                }
            }

            break;

        case CONNECTION_MASTER:

            if(msg == timer){
                //no response to CONN_REQ
                //switch back to initiating mode
                busy = false;
                gateBinded = -1;
                initiating();

            }else{

                //check is not busy and if the message came from the correct node
                if(!busy || btmsg->getArrivalGate()->getIndex() == gateBinded){

                    //check if is DATA and the message is not been received yet
                    if(btmsg->getOpcode()==OPCode::DATA && (this->message==NULL || btmsg!=this->message)){
                        busy = true;
                        cancelEvent(timer);

                        //massage saved
                        this->message = btmsg->dup();

                        temp = createAckMessage("");

                        //send the ACK
                        forwardMessage(temp,gateBinded);

                        delete btmsg;
                        delete temp;

                     }else if(btmsg->getOpcode()==OPCode::TERMINATE_TX){

                         //trasmission ended
                         temp = createTerminateTxMessage("");
                         forwardMessage(temp,gateBinded);

                         delete temp;
                         delete btmsg;
                         busy = false;
                         gateBinded = -1;
                         advertising();
                     }
                }
            }

            break;

        case CONNECTION_SLAVE:

            if(!busy || btmsg->getArrivalGate()->getIndex() == gateBinded){
                busy = true;

                //chech if is START TX packet
                if(btmsg->getOpcode() == OPCode::START_TX){

                    //send the message
                    forwardMessage(message,gateBinded);

                    delete btmsg;

                    txCounter++;

                    //retrasmission timeout
                    //timer = createTimeout();
                    //scheduleAt(simTime()+2.0,timer);

                }else if(btmsg->getOpcode() == OPCode::ACK){

                    //the whole message is arrived
                    //(no more pkts to send)
                    //send Terminate Tx command
                    temp = createTerminateTxMessage("");
                    forwardMessage(temp,gateBinded);

                    delete temp;
                    delete btmsg;

                }else if(btmsg->getOpcode() == OPCode::TERMINATE_TX){

                    //trasmission ended

                    delete btmsg;
                    busy = false;
                    gateBinded = -1;

                    //if dynamic fanout is not reached, continue on advertise
                    if(txCounter<dynamicFanout){
                        advertising();
                    }else{
                        //the correct state switch is initiating, but because the message is only one
                        //the fsa is putted in standby state.

                        //initiating();
                        standby();
                    }
                }
            }

            break;

        //VIRTUAL STATE USED ONLY FOR THE INITIALIZATION OF THE FIRST SENDER
        //USED ONLY FOR VISUAL EFFECT DURING THE SIMULATION
        case START:
            advertising();
            break;

        default: throw cRuntimeError("Unknown status");
    }
}


//==========PROVVISORIA
void RandomGeometricNode::forwardMessage(cMessage *msg)
{
    int nGate = gateSize("gate");

    for(int i=0; i < nGate; i++){
        cMessage *msgCopy = msg->dup();
        send(msgCopy, "gate$o", i);
    }
}
//=========================


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
}


void RandomGeometricNode::setState(State s)
{
    this->state = s;
    updateDisplayString();
}

bool RandomGeometricNode::validStateTransition(State s)
{
    return true;
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
        case START: color = "red"; break;
        default: throw cRuntimeError("Unknown status");
    }

    getDisplayString().setTagArg("i",1,color);
}


//================ MESSAGE METHODS =======================
/*
cMessage *RandomGeometricNode::createMessage(int c, char *pdu){
    char buff[50];
    cMessage *m;

    switch(c){
        //ACK
        case OPCode::ACK:
            sprintf(buff, "%d.%s", OPCode::ACK,pdu);
            m = new cMessage(buff,0); //0=colore rosso
            break;
        //ADV_IND
        case OPCode::ADV_IND:
            sprintf(buff, "%d.%s", OPCode::ADV_IND,pdu);
            m = new cMessage(buff,4); //4=colore giallo
            break;
        //CONN_REQ
        case OPCode::CONN_REQ:
            sprintf(buff, "%d.%s", OPCode::CONN_REQ,pdu);
            m = new cMessage(buff,2); //2=colore blu
            break;

        case OPCode::DATA:
            sprintf(buff, "%d.%s", OPCode::DATA,pdu);
            m = new cMessage(buff,6); //5=colore rosa
            break;
        default: throw cRuntimeError("Unknown opcode");
    }
    return m;
}
*/

const char *RandomGeometricNode::createTag(cMessage *m){

    char buff[50];
    sprintf(buff, "%s%ld",m->getName(),m->getId());

    std::string s(buff);

    return s.c_str();
}


BTMessage *RandomGeometricNode::createMessage(int oc,const char *pdu){

    BTMessage *m;

    switch(oc){
        //ACK
        case OPCode::ACK:
            m = new BTMessage("ACK",0); //0=red color
            break;

        //ADV_IND
        case OPCode::ADV_IND:
            m = new BTMessage("ADV_IND",4); //4=yellow color
            break;

        //CONN_REQ
        case OPCode::CONN_REQ:
            m = new BTMessage("CONN_REQ",2); //2=blue color
            break;

        //DATA
        case OPCode::DATA:
            m = new BTMessage("DATA",6); //6=pink color
            break;

        //START_TX
        case OPCode::START_TX:
            m = new BTMessage("START_TX",5); //0=red color
            break;

        //TERMINATE_TX
        case OPCode::TERMINATE_TX:
            m = new BTMessage("TERMINATE_TX",5); //0=red color
            break;

        default: throw cRuntimeError("Unknown Operational Code");
    }

    m->setOpcode(oc);
    m->setTag(createTag(m));
    m->setPdu(pdu);

    return m;
}

BTMessage *RandomGeometricNode::createAckMessage(const char *pdu){

    return createMessage(OPCode::ACK, pdu);
}

BTMessage *RandomGeometricNode::createAdvIndMessage(const char *pdu){

    return createMessage(OPCode::ADV_IND, pdu);
}

BTMessage *RandomGeometricNode::createConnReqMessage(const char *pdu){

    return createMessage(OPCode::CONN_REQ, pdu);
}

BTMessage *RandomGeometricNode::createDataMessage(const char *pdu){

    return createMessage(OPCode::DATA, pdu);
}

BTMessage *RandomGeometricNode::createStartTxMessage(const char *pdu){

    return createMessage(OPCode::START_TX, pdu);
}

BTMessage *RandomGeometricNode::createTerminateTxMessage(const char *pdu){

    return createMessage(OPCode::TERMINATE_TX, pdu);
}


//================ PROTOCOL METHODS =======================
void RandomGeometricNode::start(){
    setState(RandomGeometricNode::START);

    scheduleAt(simTime()+1.0,timer);
}

void RandomGeometricNode::standby(){
    setState(RandomGeometricNode::STANDBY);
}

void RandomGeometricNode::advertising()
{
    if(getState() != RandomGeometricNode::ADVERTISING){
        setState(RandomGeometricNode::ADVERTISING);
    }

    BTMessage *temp= createAdvIndMessage(message->getTag());
    broadcastMessage(temp);

    delete temp;

    advCounter++;
    cancelEvent(timer);
    scheduleAt(simTime()+2,timer);
}

void RandomGeometricNode::initiating()
{
    if(getState() != RandomGeometricNode::INITIATING){
        setState(RandomGeometricNode::INITIATING);
    }
}

void RandomGeometricNode::connectionMaster()
{
    if(getState() != RandomGeometricNode::CONNECTION_MASTER){
        setState(RandomGeometricNode::CONNECTION_MASTER);
    }

    BTMessage *start = createStartTxMessage("");
    forwardMessage(start,gateBinded);

    delete start;

    scheduleAt(simTime()+0.5,timer);
}

void RandomGeometricNode::connectionSlave()
{
    if(getState() != RandomGeometricNode::CONNECTION_SLAVE){
        setState(RandomGeometricNode::CONNECTION_SLAVE);
    }
}
