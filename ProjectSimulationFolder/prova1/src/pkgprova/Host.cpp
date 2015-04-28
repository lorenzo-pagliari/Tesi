//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include <string.h>
#include <omnetpp.h>


/**
 * Derive the Host class from cSimpleModule. In the Tictoc1 network,
 * both the `tic' and `toc' modules are Host objects, created by OMNeT++
 * at the beginning of the simulation.
 */
class Host : public cSimpleModule
{
    private:
        simtime_t timeout;  // timeout
        cMessage *timeoutEvent;  // holds pointer to the timeout self-message
        int seq;  // message sequence number
        cMessage *message;  // message that has to be re-sent on timeout

    public:
        Host();
        virtual ~Host();

    protected:
        // The following redefined virtual function holds the algorithm.
        virtual cMessage *generateNewMessage();
        virtual void sendCopyOf(cMessage *msg);
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

// The module class needs to be registered with OMNeT++
Define_Module(Host);

Host::Host()
{
    // Set the pointer to NULL, so that the destructor won't crash
    // even if initialize() doesn't get called because of a runtime
    // error or user cancellation during the startup process.
    timeoutEvent = message = NULL;
}

Host::~Host()
{
    // Dispose of dynamically allocated the objects
    cancelAndDelete(timeoutEvent);
    delete message;
}

void Host::initialize()
{
    // Initialize variables.
    seq = 0;
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    // Generate and send initial message.
    EV << "Sending initial message\n";
    message = generateNewMessage();
    sendCopyOf(message);
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Host::handleMessage(cMessage *msg)
{

    if (msg==timeoutEvent)
    {
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        EV << "Timeout expired, resending message and restarting timer\n";
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
        getDisplayString().setTagArg("t",0,"NO");
    }
    else // message arrived
    {
        // Acknowledgement received!
        EV << "Received: " << msg->getName() << "\n";
        delete msg;

        // Also delete the stored message and cancel the timeout event.
        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete message;

        // Ready to send another one.
        message = generateNewMessage();
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
        getDisplayString().setTagArg("t",0,"YES");
    }
}

cMessage *Host::generateNewMessage()
{
    // Generate a message with a different name every time.
    char msgname[20];
    sprintf(msgname, "tic-%d", ++seq);
    cMessage *msg = new cMessage(msgname);
    return msg;
}

void Host::sendCopyOf(cMessage *msg)
{
    int n = gateSize("gate"); //Degree node
    int k = intuniform(0,n-1);
    // Duplicate message and send the copy.
    cMessage *copy = (cMessage *) msg->dup();
    send(copy, "gate$o", k);
}


/**
 * Sends back an acknowledgement -- or not.
 */
class Hust : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Hust);

void Hust::handleMessage(cMessage *msg)
{
    double p = uniform(0,1);
    EV << "prob: " << p << endl;
    if (p < 0.5)
    {
        EV << "\"Losing\" message " << msg << endl;
        bubble("message lost :'(");
        delete msg;
        getDisplayString().setTagArg("t",0,"CACCA");
    }
    else
    {
        EV << msg << " received, sending back an acknowledgement.\n";
        delete msg;
        int n = gateSize("gate"); //Degree node
        int k = intuniform(0,n-1);
        send(new cMessage("ack"), "gate$o", k);
        getDisplayString().setTagArg("t",0,"FUCK YEAH");
    }
}
