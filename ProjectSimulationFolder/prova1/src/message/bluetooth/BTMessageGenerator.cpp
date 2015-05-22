/*
 * BTMessageGenerator.cpp
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#include <BTMessageGenerator.h>
#include <math.h>

//=============CREATE TAG & CREATE MESSAGE=====================================
const char * BTMessageGenerator::createTag(cMessage *m){

    char buff[50];
    sprintf(buff, "%s%ld",m->getName(),m->getId());

    std::string s(buff);

    return s.c_str();
}


BTMessage * BTMessageGenerator::createMessage(OPCode oc, const char *pdu){

    BTMessage *m;
    int nByteHandF = 1 + 4 + 3;
    int nBytePdu = 2;
    int nPck = 1;
    int totByte;

    switch(oc){
        //ACK
        case ACK:
            m = new BTMessage("ACK",0); //0=red color
            break;

        //ADV_IND
        case ADV_IND:
            m = new BTMessage("ADV_IND",4); //4=yellow color
            nBytePdu += 6 + sizeof(pdu)*strlen(pdu);
            break;

        //CONN_REQ
        case CONN_REQ:
            m = new BTMessage("CONN_REQ",2); //2=blue color
            nBytePdu += 6 + 6 + 22;
            break;

        //DATA
        case DATA:
            m = new BTMessage("DATA",6); //6=pink color
            nBytePdu += 33;
            nPck = ceil(strlen(pdu)/(double)33);
            EV << "Numero pacchetti data: " <<nPck <<endl;
            break;

        //START_TX
        case START_TX:
            m = new BTMessage("START_TX",5); //0=red color
            break;

        //TERMINATE_TX
        case TERMINATE_TX:
            m = new BTMessage("TERMINATE_TX",5); //0=red color
            break;

        default: throw cRuntimeError("Unknown Operational Code");
    }


    totByte = nPck * (nByteHandF + nBytePdu);

    m->setOpcode(oc);
    m->setTag(createTag(m));
    m->setPdu(pdu);
    m->setByteLength(totByte);
    return m;
}

//===============INDIVIDUAL CREATE METHODS===============================
BTMessage * BTMessageGenerator::createAckMessage(const char *pdu){

    return createMessage(ACK, pdu);
}

BTMessage * BTMessageGenerator::createAdvIndMessage(const char *pdu){

    return createMessage(ADV_IND, pdu);
}

BTMessage * BTMessageGenerator::createConnReqMessage(const char *pdu){

    return createMessage(CONN_REQ, pdu);
}

BTMessage * BTMessageGenerator::createDataMessage(const char *pdu){

    return createMessage(DATA, pdu);
}

BTMessage * BTMessageGenerator::createStartTxMessage(const char *pdu){

    return createMessage(START_TX, pdu);
}

BTMessage * BTMessageGenerator::createTerminateTxMessage(const char *pdu){

    return createMessage(TERMINATE_TX, pdu);
}

