/*
 * BTMessageGenerator.h
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#ifndef BTMESSAGEGENERATOR_H_
#define BTMESSAGEGENERATOR_H_

#include <btmessage_m.h>
#include <OPCode.h>

class BTMessageGenerator {

protected:
    static BTMessage *createMessage(OPCode,const char *);
    static const char *createTag(cMessage *);

public:
    static BTMessage *createAckMessage(const char *);
    static BTMessage *createAdvIndMessage(const char *);
    static BTMessage *createConnReqMessage(const char *);
    static BTMessage *createDataMessage(const char * pdu);
    static BTMessage *createStartTxMessage(const char *);
    static BTMessage *createTerminateTxMessage(const char *);
};

#endif /* BTMESSAGEGENERATOR_H_ */
