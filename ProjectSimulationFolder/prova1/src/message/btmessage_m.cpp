//
// Generated file, do not edit! Created by nedtool 4.6 from src/message/btmessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "btmessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(BTMessage);

BTMessage::BTMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->source_var = 0;
    this->destination_var = 0;
    this->opcode_var = 0;
    tag_arraysize = 0;
    this->tag_var = 0;
    pdu_arraysize = 0;
    this->pdu_var = 0;
}

BTMessage::BTMessage(const BTMessage& other) : ::cMessage(other)
{
    tag_arraysize = 0;
    this->tag_var = 0;
    pdu_arraysize = 0;
    this->pdu_var = 0;
    copy(other);
}

BTMessage::~BTMessage()
{
    delete [] tag_var;
    delete [] pdu_var;
}

BTMessage& BTMessage::operator=(const BTMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void BTMessage::copy(const BTMessage& other)
{
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->opcode_var = other.opcode_var;
    delete [] this->tag_var;
    this->tag_var = (other.tag_arraysize==0) ? NULL : new char[other.tag_arraysize];
    tag_arraysize = other.tag_arraysize;
    for (unsigned int i=0; i<tag_arraysize; i++)
        this->tag_var[i] = other.tag_var[i];
    delete [] this->pdu_var;
    this->pdu_var = (other.pdu_arraysize==0) ? NULL : new char[other.pdu_arraysize];
    pdu_arraysize = other.pdu_arraysize;
    for (unsigned int i=0; i<pdu_arraysize; i++)
        this->pdu_var[i] = other.pdu_var[i];
}

void BTMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->opcode_var);
    b->pack(tag_arraysize);
    doPacking(b,this->tag_var,tag_arraysize);
    b->pack(pdu_arraysize);
    doPacking(b,this->pdu_var,pdu_arraysize);
}

void BTMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->opcode_var);
    delete [] this->tag_var;
    b->unpack(tag_arraysize);
    if (tag_arraysize==0) {
        this->tag_var = 0;
    } else {
        this->tag_var = new char[tag_arraysize];
        doUnpacking(b,this->tag_var,tag_arraysize);
    }
    delete [] this->pdu_var;
    b->unpack(pdu_arraysize);
    if (pdu_arraysize==0) {
        this->pdu_var = 0;
    } else {
        this->pdu_var = new char[pdu_arraysize];
        doUnpacking(b,this->pdu_var,pdu_arraysize);
    }
}

int BTMessage::getSource() const
{
    return source_var;
}

void BTMessage::setSource(int source)
{
    this->source_var = source;
}

int BTMessage::getDestination() const
{
    return destination_var;
}

void BTMessage::setDestination(int destination)
{
    this->destination_var = destination;
}

int BTMessage::getOpcode() const
{
    return opcode_var;
}

void BTMessage::setOpcode(int opcode)
{
    this->opcode_var = opcode;
}

void BTMessage::setTagArraySize(unsigned int size)
{
    char *tag_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = tag_arraysize < size ? tag_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        tag_var2[i] = this->tag_var[i];
    for (unsigned int i=sz; i<size; i++)
        tag_var2[i] = 0;
    tag_arraysize = size;
    delete [] this->tag_var;
    this->tag_var = tag_var2;
}

unsigned int BTMessage::getTagArraySize() const
{
    return tag_arraysize;
}

char BTMessage::getTag(unsigned int k) const
{
    if (k>=tag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", tag_arraysize, k);
    return tag_var[k];
}

void BTMessage::setTag(unsigned int k, char tag)
{
    if (k>=tag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", tag_arraysize, k);
    this->tag_var[k] = tag;
}

void BTMessage::setPduArraySize(unsigned int size)
{
    char *pdu_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = pdu_arraysize < size ? pdu_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        pdu_var2[i] = this->pdu_var[i];
    for (unsigned int i=sz; i<size; i++)
        pdu_var2[i] = 0;
    pdu_arraysize = size;
    delete [] this->pdu_var;
    this->pdu_var = pdu_var2;
}

unsigned int BTMessage::getPduArraySize() const
{
    return pdu_arraysize;
}

char BTMessage::getPdu(unsigned int k) const
{
    if (k>=pdu_arraysize) throw cRuntimeError("Array of size %d indexed by %d", pdu_arraysize, k);
    return pdu_var[k];
}

void BTMessage::setPdu(unsigned int k, char pdu)
{
    if (k>=pdu_arraysize) throw cRuntimeError("Array of size %d indexed by %d", pdu_arraysize, k);
    this->pdu_var[k] = pdu;
}

class BTMessageDescriptor : public cClassDescriptor
{
  public:
    BTMessageDescriptor();
    virtual ~BTMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BTMessageDescriptor);

BTMessageDescriptor::BTMessageDescriptor() : cClassDescriptor("BTMessage", "cMessage")
{
}

BTMessageDescriptor::~BTMessageDescriptor()
{
}

bool BTMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTMessage *>(obj)!=NULL;
}

const char *BTMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int BTMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BTMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "destination",
        "opcode",
        "tag",
        "pdu",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int BTMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "opcode")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tag")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "pdu")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "char",
        "char",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *BTMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BTMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTMessage *pp = (BTMessage *)object; (void)pp;
    switch (field) {
        case 3: return pp->getTagArraySize();
        case 4: return pp->getPduArraySize();
        default: return 0;
    }
}

std::string BTMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTMessage *pp = (BTMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getDestination());
        case 2: return long2string(pp->getOpcode());
        case 3: return long2string(pp->getTag(i));
        case 4: return long2string(pp->getPdu(i));
        default: return "";
    }
}

bool BTMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTMessage *pp = (BTMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setDestination(string2long(value)); return true;
        case 2: pp->setOpcode(string2long(value)); return true;
        case 3: pp->setTag(i,string2long(value)); return true;
        case 4: pp->setPdu(i,string2long(value)); return true;
        default: return false;
    }
}

const char *BTMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *BTMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTMessage *pp = (BTMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


