/*
 * Coordinate2D.h
 *
 *  Created on: 08/mag/2015
 *      Author: Lorenzo
 */

#ifndef COORDINATE2D_H_
#define COORDINATE2D_H_

//#include <csimplemodule.h>

class Coordinate2D /*: public cSimpleModule*/{

private:
    double xCoord,yCoord;

public:
    Coordinate2D();
    Coordinate2D(double, double);
    virtual ~Coordinate2D();

    //Getter
    double getXcoord();
    double getYcoord();

    //Setter
    void setXcoord(double);
    void setYcoord(double);

protected:
    virtual void initialize();
};

#endif /* COORDINATE2D_H_ */
