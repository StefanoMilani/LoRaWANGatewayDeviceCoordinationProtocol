//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/LoRaFrames/LoRaJoinAcceptFrame.msg.
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
#include "LoRaJoinAcceptFrame_m.h"

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

Register_Class(LoRaJoinAcceptFrame)

LoRaJoinAcceptFrame::LoRaJoinAcceptFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

LoRaJoinAcceptFrame::LoRaJoinAcceptFrame(const LoRaJoinAcceptFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LoRaJoinAcceptFrame::~LoRaJoinAcceptFrame()
{
}

LoRaJoinAcceptFrame& LoRaJoinAcceptFrame::operator=(const LoRaJoinAcceptFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LoRaJoinAcceptFrame::copy(const LoRaJoinAcceptFrame& other)
{
    this->joinNonce = other.joinNonce;
    for (size_t i = 0; i < 3; i++) {
        this->netID[i] = other.netID[i];
    }
    for (size_t i = 0; i < 4; i++) {
        this->devAddr[i] = other.devAddr[i];
    }
    this->DLSettings = other.DLSettings;
    this->RXDelay = other.RXDelay;
    for (size_t i = 0; i < 16; i++) {
        this->CFList[i] = other.CFList[i];
    }
}

void LoRaJoinAcceptFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->joinNonce);
    doParsimArrayPacking(b,this->netID,3);
    doParsimArrayPacking(b,this->devAddr,4);
    doParsimPacking(b,this->DLSettings);
    doParsimPacking(b,this->RXDelay);
    doParsimArrayPacking(b,this->CFList,16);
}

void LoRaJoinAcceptFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->joinNonce);
    doParsimArrayUnpacking(b,this->netID,3);
    doParsimArrayUnpacking(b,this->devAddr,4);
    doParsimUnpacking(b,this->DLSettings);
    doParsimUnpacking(b,this->RXDelay);
    doParsimArrayUnpacking(b,this->CFList,16);
}

uint32_t LoRaJoinAcceptFrame::getJoinNonce() const
{
    return this->joinNonce;
}

void LoRaJoinAcceptFrame::setJoinNonce(uint32_t joinNonce)
{
    this->joinNonce = joinNonce;
}

size_t LoRaJoinAcceptFrame::getNetIDArraySize() const
{
    return 3;
}

uint8_t LoRaJoinAcceptFrame::getNetID(size_t k) const
{
    if (k >= 3) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)3, (unsigned long)k);
    return this->netID[k];
}

void LoRaJoinAcceptFrame::setNetID(size_t k, uint8_t netID)
{
    if (k >= 3) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)3, (unsigned long)k);
    this->netID[k] = netID;
}

size_t LoRaJoinAcceptFrame::getDevAddrArraySize() const
{
    return 4;
}

uint8_t LoRaJoinAcceptFrame::getDevAddr(size_t k) const
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    return this->devAddr[k];
}

void LoRaJoinAcceptFrame::setDevAddr(size_t k, uint8_t devAddr)
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    this->devAddr[k] = devAddr;
}

uint8_t LoRaJoinAcceptFrame::getDLSettings() const
{
    return this->DLSettings;
}

void LoRaJoinAcceptFrame::setDLSettings(uint8_t DLSettings)
{
    this->DLSettings = DLSettings;
}

uint8_t LoRaJoinAcceptFrame::getRXDelay() const
{
    return this->RXDelay;
}

void LoRaJoinAcceptFrame::setRXDelay(uint8_t RXDelay)
{
    this->RXDelay = RXDelay;
}

size_t LoRaJoinAcceptFrame::getCFListArraySize() const
{
    return 16;
}

uint8_t LoRaJoinAcceptFrame::getCFList(size_t k) const
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)16, (unsigned long)k);
    return this->CFList[k];
}

void LoRaJoinAcceptFrame::setCFList(size_t k, uint8_t CFList)
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)16, (unsigned long)k);
    this->CFList[k] = CFList;
}

class LoRaJoinAcceptFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_joinNonce,
        FIELD_netID,
        FIELD_devAddr,
        FIELD_DLSettings,
        FIELD_RXDelay,
        FIELD_CFList,
    };
  public:
    LoRaJoinAcceptFrameDescriptor();
    virtual ~LoRaJoinAcceptFrameDescriptor();

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

Register_ClassDescriptor(LoRaJoinAcceptFrameDescriptor)

LoRaJoinAcceptFrameDescriptor::LoRaJoinAcceptFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoRaJoinAcceptFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

LoRaJoinAcceptFrameDescriptor::~LoRaJoinAcceptFrameDescriptor()
{
    delete[] propertyNames;
}

bool LoRaJoinAcceptFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaJoinAcceptFrame *>(obj)!=nullptr;
}

const char **LoRaJoinAcceptFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoRaJoinAcceptFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoRaJoinAcceptFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int LoRaJoinAcceptFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_joinNonce
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_netID
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_devAddr
        FD_ISEDITABLE,    // FIELD_DLSettings
        FD_ISEDITABLE,    // FIELD_RXDelay
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_CFList
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *LoRaJoinAcceptFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinNonce",
        "netID",
        "devAddr",
        "DLSettings",
        "RXDelay",
        "CFList",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int LoRaJoinAcceptFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "joinNonce") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "netID") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "devAddr") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "DLSettings") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "RXDelay") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "CFList") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *LoRaJoinAcceptFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_joinNonce
        "uint8_t",    // FIELD_netID
        "uint8_t",    // FIELD_devAddr
        "uint8_t",    // FIELD_DLSettings
        "uint8_t",    // FIELD_RXDelay
        "uint8_t",    // FIELD_CFList
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaJoinAcceptFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaJoinAcceptFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LoRaJoinAcceptFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        case FIELD_netID: return 3;
        case FIELD_devAddr: return 4;
        case FIELD_CFList: return 16;
        default: return 0;
    }
}

void LoRaJoinAcceptFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoRaJoinAcceptFrame'", field);
    }
}

const char *LoRaJoinAcceptFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaJoinAcceptFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinNonce: return ulong2string(pp->getJoinNonce());
        case FIELD_netID: return ulong2string(pp->getNetID(i));
        case FIELD_devAddr: return ulong2string(pp->getDevAddr(i));
        case FIELD_DLSettings: return ulong2string(pp->getDLSettings());
        case FIELD_RXDelay: return ulong2string(pp->getRXDelay());
        case FIELD_CFList: return ulong2string(pp->getCFList(i));
        default: return "";
    }
}

void LoRaJoinAcceptFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinNonce: pp->setJoinNonce(string2ulong(value)); break;
        case FIELD_netID: pp->setNetID(i,string2ulong(value)); break;
        case FIELD_devAddr: pp->setDevAddr(i,string2ulong(value)); break;
        case FIELD_DLSettings: pp->setDLSettings(string2ulong(value)); break;
        case FIELD_RXDelay: pp->setRXDelay(string2ulong(value)); break;
        case FIELD_CFList: pp->setCFList(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinAcceptFrame'", field);
    }
}

omnetpp::cValue LoRaJoinAcceptFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinNonce: return (omnetpp::intval_t)(pp->getJoinNonce());
        case FIELD_netID: return (omnetpp::intval_t)(pp->getNetID(i));
        case FIELD_devAddr: return (omnetpp::intval_t)(pp->getDevAddr(i));
        case FIELD_DLSettings: return (omnetpp::intval_t)(pp->getDLSettings());
        case FIELD_RXDelay: return (omnetpp::intval_t)(pp->getRXDelay());
        case FIELD_CFList: return (omnetpp::intval_t)(pp->getCFList(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoRaJoinAcceptFrame' as cValue -- field index out of range?", field);
    }
}

void LoRaJoinAcceptFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinNonce: pp->setJoinNonce(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_netID: pp->setNetID(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_devAddr: pp->setDevAddr(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_DLSettings: pp->setDLSettings(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_RXDelay: pp->setRXDelay(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_CFList: pp->setCFList(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinAcceptFrame'", field);
    }
}

const char *LoRaJoinAcceptFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LoRaJoinAcceptFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoRaJoinAcceptFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinAcceptFrame *pp = omnetpp::fromAnyPtr<LoRaJoinAcceptFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinAcceptFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

