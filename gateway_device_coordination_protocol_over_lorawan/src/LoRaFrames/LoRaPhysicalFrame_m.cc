//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/LoRaFrames/LoRaPhysicalFrame.msg.
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
#include "LoRaPhysicalFrame_m.h"

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

Register_Class(LoRaPhysicalFrame)

LoRaPhysicalFrame::LoRaPhysicalFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

LoRaPhysicalFrame::LoRaPhysicalFrame(const LoRaPhysicalFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LoRaPhysicalFrame::~LoRaPhysicalFrame()
{
}

LoRaPhysicalFrame& LoRaPhysicalFrame::operator=(const LoRaPhysicalFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LoRaPhysicalFrame::copy(const LoRaPhysicalFrame& other)
{
    this->preamble = other.preamble;
    this->syncWord = other.syncWord;
    this->payloadLength = other.payloadLength;
    this->FECRate = other.FECRate;
    this->CRCPresence = other.CRCPresence;
    this->headerCRC = other.headerCRC;
    this->transmissionPower = other.transmissionPower;
    this->channelFrequency = other.channelFrequency;
    this->codingRate = other.codingRate;
    this->spreadingFactor = other.spreadingFactor;
    this->bandwidth = other.bandwidth;
    this->IQPolarizationInverted = other.IQPolarizationInverted;
    for (size_t i = 0; i < 59; i++) {
        this->payload[i] = other.payload[i];
    }
    this->payloadCRC = other.payloadCRC;
}

void LoRaPhysicalFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->preamble);
    doParsimPacking(b,this->syncWord);
    doParsimPacking(b,this->payloadLength);
    doParsimPacking(b,this->FECRate);
    doParsimPacking(b,this->CRCPresence);
    doParsimPacking(b,this->headerCRC);
    doParsimPacking(b,this->transmissionPower);
    doParsimPacking(b,this->channelFrequency);
    doParsimPacking(b,this->codingRate);
    doParsimPacking(b,this->spreadingFactor);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->IQPolarizationInverted);
    doParsimArrayPacking(b,this->payload,59);
    doParsimPacking(b,this->payloadCRC);
}

void LoRaPhysicalFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->preamble);
    doParsimUnpacking(b,this->syncWord);
    doParsimUnpacking(b,this->payloadLength);
    doParsimUnpacking(b,this->FECRate);
    doParsimUnpacking(b,this->CRCPresence);
    doParsimUnpacking(b,this->headerCRC);
    doParsimUnpacking(b,this->transmissionPower);
    doParsimUnpacking(b,this->channelFrequency);
    doParsimUnpacking(b,this->codingRate);
    doParsimUnpacking(b,this->spreadingFactor);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->IQPolarizationInverted);
    doParsimArrayUnpacking(b,this->payload,59);
    doParsimUnpacking(b,this->payloadCRC);
}

uint32_t LoRaPhysicalFrame::getPreamble() const
{
    return this->preamble;
}

void LoRaPhysicalFrame::setPreamble(uint32_t preamble)
{
    this->preamble = preamble;
}

uint16_t LoRaPhysicalFrame::getSyncWord() const
{
    return this->syncWord;
}

void LoRaPhysicalFrame::setSyncWord(uint16_t syncWord)
{
    this->syncWord = syncWord;
}

uint8_t LoRaPhysicalFrame::getPayloadLength() const
{
    return this->payloadLength;
}

void LoRaPhysicalFrame::setPayloadLength(uint8_t payloadLength)
{
    this->payloadLength = payloadLength;
}

uint8_t LoRaPhysicalFrame::getFECRate() const
{
    return this->FECRate;
}

void LoRaPhysicalFrame::setFECRate(uint8_t FECRate)
{
    this->FECRate = FECRate;
}

bool LoRaPhysicalFrame::getCRCPresence() const
{
    return this->CRCPresence;
}

void LoRaPhysicalFrame::setCRCPresence(bool CRCPresence)
{
    this->CRCPresence = CRCPresence;
}

uint16_t LoRaPhysicalFrame::getHeaderCRC() const
{
    return this->headerCRC;
}

void LoRaPhysicalFrame::setHeaderCRC(uint16_t headerCRC)
{
    this->headerCRC = headerCRC;
}

uint8_t LoRaPhysicalFrame::getTransmissionPower() const
{
    return this->transmissionPower;
}

void LoRaPhysicalFrame::setTransmissionPower(uint8_t transmissionPower)
{
    this->transmissionPower = transmissionPower;
}

float LoRaPhysicalFrame::getChannelFrequency() const
{
    return this->channelFrequency;
}

void LoRaPhysicalFrame::setChannelFrequency(float channelFrequency)
{
    this->channelFrequency = channelFrequency;
}

uint8_t LoRaPhysicalFrame::getCodingRate() const
{
    return this->codingRate;
}

void LoRaPhysicalFrame::setCodingRate(uint8_t codingRate)
{
    this->codingRate = codingRate;
}

uint8_t LoRaPhysicalFrame::getSpreadingFactor() const
{
    return this->spreadingFactor;
}

void LoRaPhysicalFrame::setSpreadingFactor(uint8_t spreadingFactor)
{
    this->spreadingFactor = spreadingFactor;
}

float LoRaPhysicalFrame::getBandwidth() const
{
    return this->bandwidth;
}

void LoRaPhysicalFrame::setBandwidth(float bandwidth)
{
    this->bandwidth = bandwidth;
}

bool LoRaPhysicalFrame::getIQPolarizationInverted() const
{
    return this->IQPolarizationInverted;
}

void LoRaPhysicalFrame::setIQPolarizationInverted(bool IQPolarizationInverted)
{
    this->IQPolarizationInverted = IQPolarizationInverted;
}

size_t LoRaPhysicalFrame::getPayloadArraySize() const
{
    return 59;
}

uint8_t LoRaPhysicalFrame::getPayload(size_t k) const
{
    if (k >= 59) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)59, (unsigned long)k);
    return this->payload[k];
}

void LoRaPhysicalFrame::setPayload(size_t k, uint8_t payload)
{
    if (k >= 59) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)59, (unsigned long)k);
    this->payload[k] = payload;
}

uint16_t LoRaPhysicalFrame::getPayloadCRC() const
{
    return this->payloadCRC;
}

void LoRaPhysicalFrame::setPayloadCRC(uint16_t payloadCRC)
{
    this->payloadCRC = payloadCRC;
}

class LoRaPhysicalFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_preamble,
        FIELD_syncWord,
        FIELD_payloadLength,
        FIELD_FECRate,
        FIELD_CRCPresence,
        FIELD_headerCRC,
        FIELD_transmissionPower,
        FIELD_channelFrequency,
        FIELD_codingRate,
        FIELD_spreadingFactor,
        FIELD_bandwidth,
        FIELD_IQPolarizationInverted,
        FIELD_payload,
        FIELD_payloadCRC,
    };
  public:
    LoRaPhysicalFrameDescriptor();
    virtual ~LoRaPhysicalFrameDescriptor();

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

Register_ClassDescriptor(LoRaPhysicalFrameDescriptor)

LoRaPhysicalFrameDescriptor::LoRaPhysicalFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoRaPhysicalFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

LoRaPhysicalFrameDescriptor::~LoRaPhysicalFrameDescriptor()
{
    delete[] propertyNames;
}

bool LoRaPhysicalFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaPhysicalFrame *>(obj)!=nullptr;
}

const char **LoRaPhysicalFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoRaPhysicalFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoRaPhysicalFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 14+base->getFieldCount() : 14;
}

unsigned int LoRaPhysicalFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_preamble
        FD_ISEDITABLE,    // FIELD_syncWord
        FD_ISEDITABLE,    // FIELD_payloadLength
        FD_ISEDITABLE,    // FIELD_FECRate
        FD_ISEDITABLE,    // FIELD_CRCPresence
        FD_ISEDITABLE,    // FIELD_headerCRC
        FD_ISEDITABLE,    // FIELD_transmissionPower
        FD_ISEDITABLE,    // FIELD_channelFrequency
        FD_ISEDITABLE,    // FIELD_codingRate
        FD_ISEDITABLE,    // FIELD_spreadingFactor
        FD_ISEDITABLE,    // FIELD_bandwidth
        FD_ISEDITABLE,    // FIELD_IQPolarizationInverted
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_payload
        FD_ISEDITABLE,    // FIELD_payloadCRC
    };
    return (field >= 0 && field < 14) ? fieldTypeFlags[field] : 0;
}

const char *LoRaPhysicalFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "preamble",
        "syncWord",
        "payloadLength",
        "FECRate",
        "CRCPresence",
        "headerCRC",
        "transmissionPower",
        "channelFrequency",
        "codingRate",
        "spreadingFactor",
        "bandwidth",
        "IQPolarizationInverted",
        "payload",
        "payloadCRC",
    };
    return (field >= 0 && field < 14) ? fieldNames[field] : nullptr;
}

int LoRaPhysicalFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "preamble") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "syncWord") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "payloadLength") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "FECRate") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "CRCPresence") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "headerCRC") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "transmissionPower") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "channelFrequency") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "codingRate") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "spreadingFactor") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "bandwidth") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "IQPolarizationInverted") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "payloadCRC") == 0) return baseIndex + 13;
    return base ? base->findField(fieldName) : -1;
}

const char *LoRaPhysicalFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_preamble
        "uint16_t",    // FIELD_syncWord
        "uint8_t",    // FIELD_payloadLength
        "uint8_t",    // FIELD_FECRate
        "bool",    // FIELD_CRCPresence
        "uint16_t",    // FIELD_headerCRC
        "uint8_t",    // FIELD_transmissionPower
        "float",    // FIELD_channelFrequency
        "uint8_t",    // FIELD_codingRate
        "uint8_t",    // FIELD_spreadingFactor
        "float",    // FIELD_bandwidth
        "bool",    // FIELD_IQPolarizationInverted
        "uint8_t",    // FIELD_payload
        "uint16_t",    // FIELD_payloadCRC
    };
    return (field >= 0 && field < 14) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaPhysicalFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaPhysicalFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LoRaPhysicalFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        case FIELD_payload: return 59;
        default: return 0;
    }
}

void LoRaPhysicalFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoRaPhysicalFrame'", field);
    }
}

const char *LoRaPhysicalFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaPhysicalFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        case FIELD_preamble: return ulong2string(pp->getPreamble());
        case FIELD_syncWord: return ulong2string(pp->getSyncWord());
        case FIELD_payloadLength: return ulong2string(pp->getPayloadLength());
        case FIELD_FECRate: return ulong2string(pp->getFECRate());
        case FIELD_CRCPresence: return bool2string(pp->getCRCPresence());
        case FIELD_headerCRC: return ulong2string(pp->getHeaderCRC());
        case FIELD_transmissionPower: return ulong2string(pp->getTransmissionPower());
        case FIELD_channelFrequency: return double2string(pp->getChannelFrequency());
        case FIELD_codingRate: return ulong2string(pp->getCodingRate());
        case FIELD_spreadingFactor: return ulong2string(pp->getSpreadingFactor());
        case FIELD_bandwidth: return double2string(pp->getBandwidth());
        case FIELD_IQPolarizationInverted: return bool2string(pp->getIQPolarizationInverted());
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        case FIELD_payloadCRC: return ulong2string(pp->getPayloadCRC());
        default: return "";
    }
}

void LoRaPhysicalFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        case FIELD_preamble: pp->setPreamble(string2ulong(value)); break;
        case FIELD_syncWord: pp->setSyncWord(string2ulong(value)); break;
        case FIELD_payloadLength: pp->setPayloadLength(string2ulong(value)); break;
        case FIELD_FECRate: pp->setFECRate(string2ulong(value)); break;
        case FIELD_CRCPresence: pp->setCRCPresence(string2bool(value)); break;
        case FIELD_headerCRC: pp->setHeaderCRC(string2ulong(value)); break;
        case FIELD_transmissionPower: pp->setTransmissionPower(string2ulong(value)); break;
        case FIELD_channelFrequency: pp->setChannelFrequency(string2double(value)); break;
        case FIELD_codingRate: pp->setCodingRate(string2ulong(value)); break;
        case FIELD_spreadingFactor: pp->setSpreadingFactor(string2ulong(value)); break;
        case FIELD_bandwidth: pp->setBandwidth(string2double(value)); break;
        case FIELD_IQPolarizationInverted: pp->setIQPolarizationInverted(string2bool(value)); break;
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        case FIELD_payloadCRC: pp->setPayloadCRC(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaPhysicalFrame'", field);
    }
}

omnetpp::cValue LoRaPhysicalFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        case FIELD_preamble: return (omnetpp::intval_t)(pp->getPreamble());
        case FIELD_syncWord: return (omnetpp::intval_t)(pp->getSyncWord());
        case FIELD_payloadLength: return (omnetpp::intval_t)(pp->getPayloadLength());
        case FIELD_FECRate: return (omnetpp::intval_t)(pp->getFECRate());
        case FIELD_CRCPresence: return pp->getCRCPresence();
        case FIELD_headerCRC: return (omnetpp::intval_t)(pp->getHeaderCRC());
        case FIELD_transmissionPower: return (omnetpp::intval_t)(pp->getTransmissionPower());
        case FIELD_channelFrequency: return (double)(pp->getChannelFrequency());
        case FIELD_codingRate: return (omnetpp::intval_t)(pp->getCodingRate());
        case FIELD_spreadingFactor: return (omnetpp::intval_t)(pp->getSpreadingFactor());
        case FIELD_bandwidth: return (double)(pp->getBandwidth());
        case FIELD_IQPolarizationInverted: return pp->getIQPolarizationInverted();
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        case FIELD_payloadCRC: return (omnetpp::intval_t)(pp->getPayloadCRC());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoRaPhysicalFrame' as cValue -- field index out of range?", field);
    }
}

void LoRaPhysicalFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        case FIELD_preamble: pp->setPreamble(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_syncWord: pp->setSyncWord(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_payloadLength: pp->setPayloadLength(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_FECRate: pp->setFECRate(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_CRCPresence: pp->setCRCPresence(value.boolValue()); break;
        case FIELD_headerCRC: pp->setHeaderCRC(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_transmissionPower: pp->setTransmissionPower(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_channelFrequency: pp->setChannelFrequency(static_cast<float>(value.doubleValue())); break;
        case FIELD_codingRate: pp->setCodingRate(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_spreadingFactor: pp->setSpreadingFactor(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_bandwidth: pp->setBandwidth(static_cast<float>(value.doubleValue())); break;
        case FIELD_IQPolarizationInverted: pp->setIQPolarizationInverted(value.boolValue()); break;
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_payloadCRC: pp->setPayloadCRC(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaPhysicalFrame'", field);
    }
}

const char *LoRaPhysicalFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LoRaPhysicalFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoRaPhysicalFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaPhysicalFrame *pp = omnetpp::fromAnyPtr<LoRaPhysicalFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaPhysicalFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

