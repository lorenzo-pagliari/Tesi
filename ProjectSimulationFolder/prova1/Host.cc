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
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

// The module class needs to be registered with OMNeT++
Define_Module(Host);

void Host::initialize()
{
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `host1'.

    // Am I Tic or Toc?
    if (strcmp("host1", getName()) == 0)
    {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        EV << "Sono " << getName() << " edd invio il messaggio iniziale\n";
        cMessage *msg = new cMessage("prova1Msg");
        send(msg, "out");
    }
}

void Host::handleMessage(cMessage *msg)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
    EV << "Sono "<< getName() << " e ho riceveuto '" << msg->getName() << "', lo rispedisco\n";
    send(msg, "out");
}

