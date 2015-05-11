/*
 * OPCode.h
 *
 *  Created on: 10/mag/2015
 *      Author: Lorenzo
 */

#ifndef OPCODE_H_
#define OPCODE_H_

class OPCode {

public:
    static const int ACK = 0;
    static const int ADV_IND = 1;
    static const int CONN_REQ = 2;
    static const int DATA = 3;
    static constexpr const char* INIZIO = "INIZIO";
    static constexpr const char* FINE = "FINE";
    static constexpr const char* OK = "OK";
};

#endif /* OPCODE_H_ */
