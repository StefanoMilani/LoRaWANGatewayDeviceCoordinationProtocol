//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/TransportSegments/TCPSegment.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "TCPSegment_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(TCPSegment)

TCPSegment::TCPSegment(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

TCPSegment::TCPSegment(const TCPSegment& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

TCPSegment::~TCPSegment()
{
}

TCPSegment& TCPSegment::operator=(const TCPSegment& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TCPSegment::copy(const TCPSegment& other)
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->sequenceNumber = other.sequenceNumber;
    this->ACKnumber = other.ACKnumber;
    this->dataOffset = other.dataOffset;
    this->reserved = other.reserved;
    this->NS = other.NS;
    this->CWR = other.CWR;
    this->ECE = other.ECE;
    this->URG = other.URG;
    this->ACK = other.ACK;
    this->PSH = other.PSH;
    this->RST = other.RST;
    this->SYN = other.SYN;
    this->FIN = other.FIN;
    this->windowSize = other.windowSize;
    this->checksum = other.checksum;
    this->urgentPointer = other.urgentPointer;
    for (size_t i = 0; i < 40; i++) {
        this->options[i] = other.options[i];
    }
}

void TCPSegment::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->ACKnumber);
    doParsimPacking(b,this->dataOffset);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->NS);
    doParsimPacking(b,this->CWR);
    doParsimPacking(b,this->ECE);
    doParsimPacking(b,this->URG);
    doParsimPacking(b,this->ACK);
    doParsimPacking(b,this->PSH);
    doParsimPacking(b,this->RST);
    doParsimPacking(b,this->SYN);
    doParsimPacking(b,this->FIN);
    doParsimPacking(b,this->windowSize);
    doParsimPacking(b,this->checksum);
    doParsimPacking(b,this->urgentPointer);
    doParsimArrayPacking(b,this->options,40);
}

void TCPSegment::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->ACKnumber);
    doParsimUnpacking(b,this->dataOffset);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->NS);
    doParsimUnpacking(b,this->CWR);
    doParsimUnpacking(b,this->ECE);
    doParsimUnpacking(b,this->URG);
    doParsimUnpacking(b,this->ACK);
    doParsimUnpacking(b,this->PSH);
    doParsimUnpacking(b,this->RST);
    doParsimUnpacking(b,this->SYN);
    doParsimUnpacking(b,this->FIN);
    doParsimUnpacking(b,this->windowSize);
    doParsimUnpacking(b,this->checksum);
    doParsimUnpacking(b,this->urgentPointer);
    doParsimArrayUnpacking(b,this->options,40);
}

uint16_t TCPSegment::getSrcPort() const
{
    return this->srcPort;
}

void TCPSegment::setSrcPort(uint16_t srcPort)
{
    this->srcPort = srcPort;
}

uint16_t TCPSegment::getDestPort() const
{
    return this->destPort;
}

void TCPSegment::setDestPort(uint16_t destPort)
{
    this->destPort = destPort;
}

uint32_t TCPSegment::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void TCPSegment::setSequenceNumber(uint32_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

uint32_t TCPSegment::getACKnumber() const
{
    return this->ACKnumber;
}

void TCPSegment::setACKnumber(uint32_t ACKnumber)
{
    this->ACKnumber = ACKnumber;
}

uint8_t TCPSegment::getDataOffset() const
{
    return this->dataOffset;
}

void TCPSegment::setDataOffset(uint8_t dataOffset)
{
    this->dataOffset = dataOffset;
}

uint8_t TCPSegment::getReserved() const
{
    return this->reserved;
}

void TCPSegment::setReserved(uint8_t reserved)
{
    this->reserved = reserved;
}

bool TCPSegment::getNS() const
{
    return this->NS;
}

void TCPSegment::setNS(bool NS)
{
    this->NS = NS;
}

bool TCPSegment::getCWR() const
{
    return this->CWR;
}

void TCPSegment::setCWR(bool CWR)
{
    this->CWR = CWR;
}

bool TCPSegment::getECE() const
{
    return this->ECE;
}

void TCPSegment::setECE(bool ECE)
{
    this->ECE = ECE;
}

bool TCPSegment::getURG() const
{
    return this->URG;
}

void TCPSegment::setURG(bool URG)
{
    this->URG = URG;
}

bool TCPSegment::getACK() const
{
    return this->ACK;
}

void TCPSegment::setACK(bool ACK)
{
    this->ACK = ACK;
}

bool TCPSegment::getPSH() const
{
    return this->PSH;
}

void TCPSegment::setPSH(bool PSH)
{
    this->PSH = PSH;
}

bool TCPSegment::getRST() const
{
    return this->RST;
}

void TCPSegment::setRST(bool RST)
{
    this->RST = RST;
}

bool TCPSegment::getSYN() const
{
    return this->SYN;
}

void TCPSegment::setSYN(bool SYN)
{
    this->SYN = SYN;
}

bool TCPSegment::getFIN() const
{
    return this->FIN;
}

void TCPSegment::setFIN(bool FIN)
{
    this->FIN = FIN;
}

uint16_t TCPSegment::getWindowSize() const
{
    return this->windowSize;
}

void TCPSegment::setWindowSize(uint16_t windowSize)
{
    this->windowSize = windowSize;
}

uint16_t TCPSegment::getChecksum() const
{
    return this->checksum;
}

void TCPSegment::setChecksum(uint16_t checksum)
{
    this->checksum = checksum;
}

uint16_t TCPSegment::getUrgentPointer() const
{
    return this->urgentPointer;
}

void TCPSegment::setUrgentPointer(uint16_t urgentPointer)
{
    this->urgentPointer = urgentPointer;
}

size_t TCPSegment::getOptionsArraySize() const
{
    return 40;
}

uint8_t TCPSegment::getOptions(size_t k) const
{
    if (k >= 40) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)40, (unsigned long)k);
    return this->options[k];
}

void TCPSegment::setOptions(size_t k, uint8_t options)
{
    if (k >= 40) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)40, (unsigned long)k);
    this->options[k] = options;
}

class TCPSegmentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcPort,
        FIELD_destPort,
        FIELD_sequenceNumber,
        FIELD_ACKnumber,
        FIELD_dataOffset,
        FIELD_reserved,
        FIELD_NS,
        FIELD_CWR,
        FIELD_ECE,
        FIELD_URG,
        FIELD_ACK,
        FIELD_PSH,
        FIELD_RST,
        FIELD_SYN,
        FIELD_FIN,
        FIELD_windowSize,
        FIELD_checksum,
        FIELD_urgentPointer,
        FIELD_options,
    };
  public:
    TCPSegmentDescriptor();
    virtual ~TCPSegmentDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TCPSegmentDescriptor)

TCPSegmentDescriptor::TCPSegmentDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(TCPSegment)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

TCPSegmentDescriptor::~TCPSegmentDescriptor()
{
    delete[] propertyNames;
}

bool TCPSegmentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPSegment *>(obj)!=nullptr;
}

const char **TCPSegmentDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TCPSegmentDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TCPSegmentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 19+base->getFieldCount() : 19;
}

unsigned int TCPSegmentDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_destPort
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_ACKnumber
        FD_ISEDITABLE,    // FIELD_dataOffset
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_NS
        FD_ISEDITABLE,    // FIELD_CWR
        FD_ISEDITABLE,    // FIELD_ECE
        FD_ISEDITABLE,    // FIELD_URG
        FD_ISEDITABLE,    // FIELD_ACK
        FD_ISEDITABLE,    // FIELD_PSH
        FD_ISEDITABLE,    // FIELD_RST
        FD_ISEDITABLE,    // FIELD_SYN
        FD_ISEDITABLE,    // FIELD_FIN
        FD_ISEDITABLE,    // FIELD_windowSize
        FD_ISEDITABLE,    // FIELD_checksum
        FD_ISEDITABLE,    // FIELD_urgentPointer
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_options
    };
    return (field >= 0 && field < 19) ? fieldTypeFlags[field] : 0;
}

const char *TCPSegmentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "sequenceNumber",
        "ACKnumber",
        "dataOffset",
        "reserved",
        "NS",
        "CWR",
        "ECE",
        "URG",
        "ACK",
        "PSH",
        "RST",
        "SYN",
        "FIN",
        "windowSize",
        "checksum",
        "urgentPointer",
        "options",
    };
    return (field >= 0 && field < 19) ? fieldNames[field] : nullptr;
}

int TCPSegmentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcPort") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destPort") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "ACKnumber") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "dataOffset") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "reserved") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "NS") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "CWR") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "ECE") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "URG") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "ACK") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "PSH") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "RST") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "SYN") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "FIN") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "windowSize") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "checksum") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "urgentPointer") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "options") == 0) return baseIndex + 18;
    return base ? base->findField(fieldName) : -1;
}

const char *TCPSegmentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_srcPort
        "uint16_t",    // FIELD_destPort
        "uint32_t",    // FIELD_sequenceNumber
        "uint32_t",    // FIELD_ACKnumber
        "uint8_t",    // FIELD_dataOffset
        "uint8_t",    // FIELD_reserved
        "bool",    // FIELD_NS
        "bool",    // FIELD_CWR
        "bool",    // FIELD_ECE
        "bool",    // FIELD_URG
        "bool",    // FIELD_ACK
        "bool",    // FIELD_PSH
        "bool",    // FIELD_RST
        "bool",    // FIELD_SYN
        "bool",    // FIELD_FIN
        "uint16_t",    // FIELD_windowSize
        "uint16_t",    // FIELD_checksum
        "uint16_t",    // FIELD_urgentPointer
        "uint8_t",    // FIELD_options
    };
    return (field >= 0 && field < 19) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPSegmentDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TCPSegmentDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TCPSegmentDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        case FIELD_options: return 40;
        default: return 0;
    }
}

void TCPSegmentDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TCPSegment'", field);
    }
}

const char *TCPSegmentDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPSegmentDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        case FIELD_srcPort: return ulong2string(pp->getSrcPort());
        case FIELD_destPort: return ulong2string(pp->getDestPort());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_ACKnumber: return ulong2string(pp->getACKnumber());
        case FIELD_dataOffset: return ulong2string(pp->getDataOffset());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_NS: return bool2string(pp->getNS());
        case FIELD_CWR: return bool2string(pp->getCWR());
        case FIELD_ECE: return bool2string(pp->getECE());
        case FIELD_URG: return bool2string(pp->getURG());
        case FIELD_ACK: return bool2string(pp->getACK());
        case FIELD_PSH: return bool2string(pp->getPSH());
        case FIELD_RST: return bool2string(pp->getRST());
        case FIELD_SYN: return bool2string(pp->getSYN());
        case FIELD_FIN: return bool2string(pp->getFIN());
        case FIELD_windowSize: return ulong2string(pp->getWindowSize());
        case FIELD_checksum: return ulong2string(pp->getChecksum());
        case FIELD_urgentPointer: return ulong2string(pp->getUrgentPointer());
        case FIELD_options: return ulong2string(pp->getOptions(i));
        default: return "";
    }
}

void TCPSegmentDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        case FIELD_srcPort: pp->setSrcPort(string2ulong(value)); break;
        case FIELD_destPort: pp->setDestPort(string2ulong(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); break;
        case FIELD_ACKnumber: pp->setACKnumber(string2ulong(value)); break;
        case FIELD_dataOffset: pp->setDataOffset(string2ulong(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_NS: pp->setNS(string2bool(value)); break;
        case FIELD_CWR: pp->setCWR(string2bool(value)); break;
        case FIELD_ECE: pp->setECE(string2bool(value)); break;
        case FIELD_URG: pp->setURG(string2bool(value)); break;
        case FIELD_ACK: pp->setACK(string2bool(value)); break;
        case FIELD_PSH: pp->setPSH(string2bool(value)); break;
        case FIELD_RST: pp->setRST(string2bool(value)); break;
        case FIELD_SYN: pp->setSYN(string2bool(value)); break;
        case FIELD_FIN: pp->setFIN(string2bool(value)); break;
        case FIELD_windowSize: pp->setWindowSize(string2ulong(value)); break;
        case FIELD_checksum: pp->setChecksum(string2ulong(value)); break;
        case FIELD_urgentPointer: pp->setUrgentPointer(string2ulong(value)); break;
        case FIELD_options: pp->setOptions(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TCPSegment'", field);
    }
}

omnetpp::cValue TCPSegmentDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        case FIELD_srcPort: return (omnetpp::intval_t)(pp->getSrcPort());
        case FIELD_destPort: return (omnetpp::intval_t)(pp->getDestPort());
        case FIELD_sequenceNumber: return (omnetpp::intval_t)(pp->getSequenceNumber());
        case FIELD_ACKnumber: return (omnetpp::intval_t)(pp->getACKnumber());
        case FIELD_dataOffset: return (omnetpp::intval_t)(pp->getDataOffset());
        case FIELD_reserved: return (omnetpp::intval_t)(pp->getReserved());
        case FIELD_NS: return pp->getNS();
        case FIELD_CWR: return pp->getCWR();
        case FIELD_ECE: return pp->getECE();
        case FIELD_URG: return pp->getURG();
        case FIELD_ACK: return pp->getACK();
        case FIELD_PSH: return pp->getPSH();
        case FIELD_RST: return pp->getRST();
        case FIELD_SYN: return pp->getSYN();
        case FIELD_FIN: return pp->getFIN();
        case FIELD_windowSize: return (omnetpp::intval_t)(pp->getWindowSize());
        case FIELD_checksum: return (omnetpp::intval_t)(pp->getChecksum());
        case FIELD_urgentPointer: return (omnetpp::intval_t)(pp->getUrgentPointer());
        case FIELD_options: return (omnetpp::intval_t)(pp->getOptions(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TCPSegment' as cValue -- field index out of range?", field);
    }
}

void TCPSegmentDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        case FIELD_srcPort: pp->setSrcPort(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_destPort: pp->setDestPort(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_ACKnumber: pp->setACKnumber(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_dataOffset: pp->setDataOffset(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_reserved: pp->setReserved(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_NS: pp->setNS(value.boolValue()); break;
        case FIELD_CWR: pp->setCWR(value.boolValue()); break;
        case FIELD_ECE: pp->setECE(value.boolValue()); break;
        case FIELD_URG: pp->setURG(value.boolValue()); break;
        case FIELD_ACK: pp->setACK(value.boolValue()); break;
        case FIELD_PSH: pp->setPSH(value.boolValue()); break;
        case FIELD_RST: pp->setRST(value.boolValue()); break;
        case FIELD_SYN: pp->setSYN(value.boolValue()); break;
        case FIELD_FIN: pp->setFIN(value.boolValue()); break;
        case FIELD_windowSize: pp->setWindowSize(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_checksum: pp->setChecksum(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_urgentPointer: pp->setUrgentPointer(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_options: pp->setOptions(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TCPSegment'", field);
    }
}

const char *TCPSegmentDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TCPSegmentDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TCPSegmentDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TCPSegment *pp = omnetpp::fromAnyPtr<TCPSegment>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TCPSegment'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

