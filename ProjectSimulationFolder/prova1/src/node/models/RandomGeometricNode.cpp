/*
 * RandomGeometricNode.cpp
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#include <RandomGeometricNode.h>
#include <stdio.h>
#include <omnetpp.h>
#include <OPCode.h>

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
        message = new cMessage("MESSAGGIO1");
        //advertising();

        //stato di partenza
        start();
        scheduleAt(simTime()+1.0,timer);
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
    //PRECEDENTE
/*
    if(msg == this->timer){
        setState(RandomGeometricNode::CONNECTION_MASTER);
        forwardMessage(this->message);

    }else if(this->message == NULL){
        setState(RandomGeometricNode::CONNECTION_SLAVE);

        this->message = msg;

        int wait=intuniform(1,10);
        scheduleAt(simTime()+wait,timer);
        EV<<"["<<getIndex()<<"]ASPETTO "<< wait << " secondi"<<endl;

    }else if(strcmp(msg->getName(),this->message->getName())==0){
        setState(RandomGeometricNode::INITIATING);
        EV<<"FINITO"<<endl;
        delete msg;
    }
*/

/*
    switch(state)
    {
    case INITIATING:
        EV << "["<<getIndex()<<"] dentro initiating"<<endl;
        if(msg == this->timer){
                forwardMessage(this->message);

            }else if(this->message == NULL){

                this->message = msg;

                int wait=intuniform(1,10);
                scheduleAt(simTime()+wait,timer);
                EV<<"["<<getIndex()<<"]ASPETTO "<< wait << " secondi"<<endl;

            }else if(strcmp(msg->getName(),this->message->getName())==0){
                EV<<"FINITO"<<endl;
                delete msg;
            }
        break;
    case ADVERTISING:
        EV << "["<<getIndex()<<"] dentro advertising"<<endl;
        if(msg == this->timer){
                forwardMessage(this->message);

            }else if(this->message == NULL){

                this->message = msg;

                int wait=intuniform(1,10);
                scheduleAt(simTime()+wait,timer);
                EV<<"["<<getIndex()<<"]ASPETTO "<< wait << " secondi"<<endl;

            }else if(strcmp(msg->getName(),this->message->getName())==0){
                EV<<"FINITO"<<endl;
                delete msg;
            }
        break;

    }
*/
/*
    cEnum *e = cEnum::get("RandomGeometricNode");
    EV << "["<<getIndex()<<"] stato: "<<state <<"/"<<e->getStringFor(state)<<endl;
*/


    cMessage *temp = NULL;
    char *name = NULL;
    char *pdu = NULL;

    name = (char*)msg->getName();

    switch(state)
    {
        case STANDBY: EV <<"dentro standby"<<endl; break;
        case SCANNING: EV <<"dentro scanning"<<endl;break;
        case ADVERTISING:

            if(msg == timer){
                //nessuno a risposto all'ADV_IND
                //rispammo
                if(advCounter < advLimit){
                    advertising();
                }else{
                    standby();
                }
            }else{
                pdu = strtok(name,".");

                //controllo che sia un CONN_REQ
                if(strcmp(pdu,"2")==0){
                    //controllo che la richiesta combaci col messaggio
                    pdu = strtok(NULL,".");

                    if(this->message!=NULL && strcmp(pdu,this->message->getName())==0){
                        //la richiesta è confermata, passo in connection slave

                        advCounter = 0;
                        gateBinded = msg->getArrivalGate()->getIndex();
                        delete msg;
                        connectionSlave();
                    }else{
                        //Richiesta non confermata, scarto il messaggio
                        delete msg;
                    }
                }
            }

            break;

       case INITIATING:

            pdu = strtok(name,".");

            //controllo che sia un ADV_IND
            if(strcmp(pdu,"1")==0){
                //controllo se il messaggio l'ho già ricevuto
                pdu = strtok(NULL,".");
                if(this->message==NULL || strcmp(pdu,this->message->getName())!=0){
                    //non ho il messaggio e mando la richiesta di connessione
                    //mando una conn_req

                    temp = createMessage(2,pdu);
                    forwardMessage(temp,msg->getArrivalGate()->getIndex());

                    delete temp;
                    connectionMaster(msg->getArrivalGate()->getIndex());
                }
            }

            break;

        case CONNECTION_MASTER:

            if(msg == timer){
                //nessuno a risposto alla CONN_REW
                //mi rimetto in ascolto
                initiating();
            }else{
                if(this->message==NULL || msg!=this->message){
                    //salva il messaggio
                    this->message = msg->dup();
                    //mando l'ack di fine
                    forwardMessage(createMessage(OPCode::ACK,(char*)OPCode::FINE),msg->getArrivalGate()->getIndex());
                    delete msg;
                    advertising();
                 }else{
                    //Messaggio già arrivato e salvato, scarto il messaggio appena arrivato
                    delete msg;
                 }
            }

            break;

        case CONNECTION_SLAVE:

            if(!busy || msg->getArrivalGate()->getIndex() == gateBinded){
                busy = true;
                pdu = strtok(name,".");

                //controllo che sia un ACK
                if(strcmp(pdu,"0")==0){

                    pdu = strtok(NULL,".");

                    if(strcmp(pdu,OPCode::INIZIO)==0){
                        //invio il messaggio al richidente
                        temp = createMessage(3,(char*)message->getName());
                        forwardMessage(temp,msg->getArrivalGate()->getIndex());
                        delete temp;
                        txCounter++;
                        //timout per la ristrasmissione
                        //timer = createTimeout(msg->getArrivalGate()->getIndex());
                        //scheduleAt(simTime()+2.0,timer);
                    }else if(strcmp(pdu,OPCode::FINE)==0){
                        //trasmissione terminata
                        delete msg;
                        busy = false;
                        gateBinded = -1;
                        if(txCounter<dynamicFanout){
                            advertising();
                        }else{
                            //giusto sarebbe initiating ma visto che il messaggio è solo 1 li fermo in standby
                            //initiating();
                            standby();
                        }
                    }
                }else{
                    EV << "["<<getIndex()<<"]scarto perchè not ack" <<endl;
                }

            }else{
                EV << "["<<getIndex()<<"]scarto perchè busy" <<endl;
            }

            break;

        case START:
            EV << "["<< getIndex()<<"] START !!!" << endl;
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
        case START: color = "red"; break;
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


//================ MESSAGE METHODS =======================

cMessage *RandomGeometricNode::createMessage(int c, char *pdu){
    char buff[50];
    cMessage *m;

    switch(c){
        //ACK
        case OPCode::ACK:
            sprintf(buff, "%d.%s", OPCode::ACK,pdu);
            m = new cMessage(buff);
            break;
        //ADV_IND
        case OPCode::ADV_IND:
            sprintf(buff, "%d.%s", OPCode::ADV_IND,pdu);
            m = new cMessage(buff);
            break;
        //CONN_REQ
        case OPCode::CONN_REQ:
            sprintf(buff, "%d.%s", OPCode::CONN_REQ,pdu);
            m = new cMessage(buff);
            break;

        case OPCode::DATA:
            sprintf(buff, "%d.%s", OPCode::DATA,pdu);
            m = new cMessage(buff);
            break;
        default: throw cRuntimeError("Unknown opcode");
    }
    return m;
}


cMessage* RandomGeometricNode::createTimeout(int gate){
    char buff[50];
    cMessage *m;

    sprintf(buff, "%d",gate);
    m = new cMessage(buff);
    return m;
}

//================ PROTOCOL METHODS =======================
void RandomGeometricNode::start(){
    setState(RandomGeometricNode::START);
}

void RandomGeometricNode::standby(){
    setState(RandomGeometricNode::STANDBY);
}

void RandomGeometricNode::advertising()
{
    if(getState() != RandomGeometricNode::ADVERTISING){
        setState(RandomGeometricNode::ADVERTISING);
    }

    cMessage *temp= createMessage(1,(char*)this->message->getName());
    broadcastMessage(temp);
    delete temp;
    advCounter++;
    cancelEvent(timer);
    scheduleAt(simTime()+2.0,timer);
}

void RandomGeometricNode::initiating()
{
    if(getState() != RandomGeometricNode::INITIATING){
        setState(RandomGeometricNode::INITIATING);
    }
}

void RandomGeometricNode::connectionMaster(int gateSource)
{
    if(getState() != RandomGeometricNode::CONNECTION_MASTER){
        setState(RandomGeometricNode::CONNECTION_MASTER);
    }
    cMessage *ack = createMessage(0,(char*)OPCode::INIZIO);
    forwardMessage(ack,gateSource);
    delete ack;
    scheduleAt(simTime()+7.0,timer);
}

void RandomGeometricNode::connectionSlave()
{
    if(getState() != RandomGeometricNode::CONNECTION_SLAVE){
        setState(RandomGeometricNode::CONNECTION_SLAVE);
    }
}
