/*
 * RandomGeometricNode.cpp
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#include <RandomGeometricNode.h>
#include <omnetpp.h>
#include <stdio.h>


Register_Class(RandomGeometricNode);

/*--------------- CONSTRUCTOR ---------------*/
RandomGeometricNode::RandomGeometricNode() {
    this->xPos = 0;
    this->yPos = 0;
}

/*--------------- DESTROYER ---------------*/
RandomGeometricNode::~RandomGeometricNode() {

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

    EV << "x: " << this->xPos << endl;
    EV << "y: " << this->yPos << endl;

    std::stringstream ss;
    ss << this->xPos;
    std::string s = ss.str();

    /*
     * il posizionamento non è molto efficace in quanto
     * posiziona secondo pixel e non secondo presunte unità
     * di misura
     *
    char b[20];
    sprintf(b, "%lf", this->xPos);
    getDisplayString().setTagArg("p",0,b);

    sprintf(b, "%lf", this->yPos);
    getDisplayString().setTagArg("p",1,b);
    */
}



/*---------OTHER METHODS ---------------*/

