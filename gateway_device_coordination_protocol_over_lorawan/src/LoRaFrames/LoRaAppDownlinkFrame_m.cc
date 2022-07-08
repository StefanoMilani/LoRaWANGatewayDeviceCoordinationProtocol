//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/LoRaFrames/LoRaAppDownlinkFrame.msg.
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
#include "LoRaAppDownlinkFrame_m.h"

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

LoRaControlDownlink::LoRaControlDownlink()
{
    for (size_t i = 0; i < 4; i++)
        this->FOptsLen[i] = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const LoRaControlDownlink& a)
{
    doParsimArrayPacking(b,a.FOptsLen,4);
    doParsimPacking(b,a.FPending);
    doParsimPacking(b,a.ACK);
    doParsimPacking(b,a.RFU);
    doParsimPacking(b,a.ADR);
}

void __doUnpacking(omnetpp::cCommBuffer *b, LoRaControlDownlink& a)
{
    doParsimArrayUnpacking(b,a.FOptsLen,4);
    doParsimUnpacking(b,a.FPending);
    doParsimUnpacking(b,a.ACK);
    doParsimUnpacking(b,a.RFU);
    doParsimUnpacking(b,a.ADR);
}

class LoRaControlDownlinkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_FOptsLen,
        FIELD_FPending,
        FIELD_ACK,
        FIELD_RFU,
        FIELD_ADR,
    };
  public:
    LoRaControlDownlinkDescriptor();
    virtual ~LoRaControlDownlinkDescriptor();

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

Register_ClassDescriptor(LoRaControlDownlinkDescriptor)

LoRaControlDownlinkDescriptor::LoRaControlDownlinkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoRaControlDownlink)), "")
{
    propertyNames = nullptr;
}

LoRaControlDownlinkDescriptor::~LoRaControlDownlinkDescriptor()
{
    delete[] propertyNames;
}

bool LoRaControlDownlinkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaControlDownlink *>(obj)!=nullptr;
}

const char **LoRaControlDownlinkDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoRaControlDownlinkDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoRaControlDownlinkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int LoRaControlDownlinkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_FOptsLen
        FD_ISEDITABLE,    // FIELD_FPending
        FD_ISEDITABLE,    // FIELD_ACK
        FD_ISEDITABLE,    // FIELD_RFU
        FD_ISEDITABLE,    // FIELD_ADR
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LoRaControlDownlinkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "FOptsLen",
        "FPending",
        "ACK",
        "RFU",
        "ADR",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LoRaControlDownlinkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "FOptsLen") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "FPending") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ACK") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "RFU") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "ADR") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *LoRaControlDownlinkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_FOptsLen
        "bool",    // FIELD_FPending
        "bool",    // FIELD_ACK
        "bool",    // FIELD_RFU
        "bool",    // FIELD_ADR
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaControlDownlinkDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaControlDownlinkDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LoRaControlDownlinkDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        case FIELD_FOptsLen: return 4;
        default: return 0;
    }
}

void LoRaControlDownlinkDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoRaControlDownlink'", field);
    }
}

const char *LoRaControlDownlinkDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaControlDownlinkDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        case FIELD_FOptsLen: if (i >= 4) return "";
                return bool2string(pp->FOptsLen[i]);
        case FIELD_FPending: return bool2string(pp->FPending);
        case FIELD_ACK: return bool2string(pp->ACK);
        case FIELD_RFU: return bool2string(pp->RFU);
        case FIELD_ADR: return bool2string(pp->ADR);
        default: return "";
    }
}

void LoRaControlDownlinkDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        case FIELD_FOptsLen: if (i < 0 || i >= 4) throw omnetpp::cRuntimeError("Array index %d out of bounds for field %d of class 'LoRaControlDownlink'", i, field);
                pp->FOptsLen[i] = string2bool(value); break;
        case FIELD_FPending: pp->FPending = string2bool(value); break;
        case FIELD_ACK: pp->ACK = string2bool(value); break;
        case FIELD_RFU: pp->RFU = string2bool(value); break;
        case FIELD_ADR: pp->ADR = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaControlDownlink'", field);
    }
}

omnetpp::cValue LoRaControlDownlinkDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        case FIELD_FOptsLen: if (i >= 4) return omnetpp::cValue();
                return pp->FOptsLen[i];
        case FIELD_FPending: return pp->FPending;
        case FIELD_ACK: return pp->ACK;
        case FIELD_RFU: return pp->RFU;
        case FIELD_ADR: return pp->ADR;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoRaControlDownlink' as cValue -- field index out of range?", field);
    }
}

void LoRaControlDownlinkDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        case FIELD_FOptsLen: if (i < 0 || i >= 4) throw omnetpp::cRuntimeError("Array index %d out of bounds for field %d of class 'LoRaControlDownlink'", i, field);
                pp->FOptsLen[i] = value.boolValue(); break;
        case FIELD_FPending: pp->FPending = value.boolValue(); break;
        case FIELD_ACK: pp->ACK = value.boolValue(); break;
        case FIELD_RFU: pp->RFU = value.boolValue(); break;
        case FIELD_ADR: pp->ADR = value.boolValue(); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaControlDownlink'", field);
    }
}

const char *LoRaControlDownlinkDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LoRaControlDownlinkDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoRaControlDownlinkDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaControlDownlink *pp = omnetpp::fromAnyPtr<LoRaControlDownlink>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaControlDownlink'", field);
    }
}

Register_Class(LoRaAppDownlinkFrame)

LoRaAppDownlinkFrame::LoRaAppDownlinkFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

LoRaAppDownlinkFrame::LoRaAppDownlinkFrame(const LoRaAppDownlinkFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LoRaAppDownlinkFrame::~LoRaAppDownlinkFrame()
{
}

LoRaAppDownlinkFrame& LoRaAppDownlinkFrame::operator=(const LoRaAppDownlinkFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LoRaAppDownlinkFrame::copy(const LoRaAppDownlinkFrame& other)
{
    for (size_t i = 0; i < 4; i++) {
        this->deviceAddress[i] = other.deviceAddress[i];
    }
    this->control = other.control;
    this->counter = other.counter;
    this->port = other.port;
    for (size_t i = 0; i < 11; i++) {
        this->payload[i] = other.payload[i];
    }
}

void LoRaAppDownlinkFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimArrayPacking(b,this->deviceAddress,4);
    doParsimPacking(b,this->control);
    doParsimPacking(b,this->counter);
    doParsimPacking(b,this->port);
    doParsimArrayPacking(b,this->payload,11);
}

void LoRaAppDownlinkFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->deviceAddress,4);
    doParsimUnpacking(b,this->control);
    doParsimUnpacking(b,this->counter);
    doParsimUnpacking(b,this->port);
    doParsimArrayUnpacking(b,this->payload,11);
}

size_t LoRaAppDownlinkFrame::getDeviceAddressArraySize() const
{
    return 4;
}

uint8_t LoRaAppDownlinkFrame::getDeviceAddress(size_t k) const
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    return this->deviceAddress[k];
}

void LoRaAppDownlinkFrame::setDeviceAddress(size_t k, uint8_t deviceAddress)
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    this->deviceAddress[k] = deviceAddress;
}

const LoRaControlDownlink& LoRaAppDownlinkFrame::getControl() const
{
    return this->control;
}

void LoRaAppDownlinkFrame::setControl(const LoRaControlDownlink& control)
{
    this->control = control;
}

uint16_t LoRaAppDownlinkFrame::getCounter() const
{
    return this->counter;
}

void LoRaAppDownlinkFrame::setCounter(uint16_t counter)
{
    this->counter = counter;
}

uint8_t LoRaAppDownlinkFrame::getPort() const
{
    return this->port;
}

void LoRaAppDownlinkFrame::setPort(uint8_t port)
{
    this->port = port;
}

size_t LoRaAppDownlinkFrame::getPayloadArraySize() const
{
    return 11;
}

uint8_t LoRaAppDownlinkFrame::getPayload(size_t k) const
{
    if (k >= 11) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)11, (unsigned long)k);
    return this->payload[k];
}

void LoRaAppDownlinkFrame::setPayload(size_t k, uint8_t payload)
{
    if (k >= 11) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)11, (unsigned long)k);
    this->payload[k] = payload;
}

class LoRaAppDownlinkFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddress,
        FIELD_control,
        FIELD_counter,
        FIELD_port,
        FIELD_payload,
    };
  public:
    LoRaAppDownlinkFrameDescriptor();
    virtual ~LoRaAppDownlinkFrameDescriptor();

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

Register_ClassDescriptor(LoRaAppDownlinkFrameDescriptor)

LoRaAppDownlinkFrameDescriptor::LoRaAppDownlinkFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoRaAppDownlinkFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

LoRaAppDownlinkFrameDescriptor::~LoRaAppDownlinkFrameDescriptor()
{
    delete[] propertyNames;
}

bool LoRaAppDownlinkFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaAppDownlinkFrame *>(obj)!=nullptr;
}

const char **LoRaAppDownlinkFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoRaAppDownlinkFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoRaAppDownlinkFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int LoRaAppDownlinkFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISCOMPOUND,    // FIELD_control
        FD_ISEDITABLE,    // FIELD_counter
        FD_ISEDITABLE,    // FIELD_port
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_payload
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LoRaAppDownlinkFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddress",
        "control",
        "counter",
        "port",
        "payload",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LoRaAppDownlinkFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "control") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "counter") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "port") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *LoRaAppDownlinkFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_deviceAddress
        "LoRaControlDownlink",    // FIELD_control
        "uint16_t",    // FIELD_counter
        "uint8_t",    // FIELD_port
        "uint8_t",    // FIELD_payload
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaAppDownlinkFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaAppDownlinkFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LoRaAppDownlinkFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return 4;
        case FIELD_payload: return 11;
        default: return 0;
    }
}

void LoRaAppDownlinkFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoRaAppDownlinkFrame'", field);
    }
}

const char *LoRaAppDownlinkFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaAppDownlinkFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return ulong2string(pp->getDeviceAddress(i));
        case FIELD_control: return "";
        case FIELD_counter: return ulong2string(pp->getCounter());
        case FIELD_port: return ulong2string(pp->getPort());
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        default: return "";
    }
}

void LoRaAppDownlinkFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(i,string2ulong(value)); break;
        case FIELD_counter: pp->setCounter(string2ulong(value)); break;
        case FIELD_port: pp->setPort(string2ulong(value)); break;
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaAppDownlinkFrame'", field);
    }
}

omnetpp::cValue LoRaAppDownlinkFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress(i));
        case FIELD_control: return omnetpp::toAnyPtr(&pp->getControl()); break;
        case FIELD_counter: return (omnetpp::intval_t)(pp->getCounter());
        case FIELD_port: return (omnetpp::intval_t)(pp->getPort());
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoRaAppDownlinkFrame' as cValue -- field index out of range?", field);
    }
}

void LoRaAppDownlinkFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_counter: pp->setCounter(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_port: pp->setPort(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaAppDownlinkFrame'", field);
    }
}

const char *LoRaAppDownlinkFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_control: return omnetpp::opp_typename(typeid(LoRaControlDownlink));
        default: return nullptr;
    };
}

omnetpp::any_ptr LoRaAppDownlinkFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        case FIELD_control: return omnetpp::toAnyPtr(&pp->getControl()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoRaAppDownlinkFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaAppDownlinkFrame *pp = omnetpp::fromAnyPtr<LoRaAppDownlinkFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaAppDownlinkFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

