//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/LoRaFrames/LoRaJoinRequestFrame.msg.
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
#include "LoRaJoinRequestFrame_m.h"

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

Register_Class(LoRaJoinRequestFrame)

LoRaJoinRequestFrame::LoRaJoinRequestFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

LoRaJoinRequestFrame::LoRaJoinRequestFrame(const LoRaJoinRequestFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LoRaJoinRequestFrame::~LoRaJoinRequestFrame()
{
}

LoRaJoinRequestFrame& LoRaJoinRequestFrame::operator=(const LoRaJoinRequestFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LoRaJoinRequestFrame::copy(const LoRaJoinRequestFrame& other)
{
    for (size_t i = 0; i < 8; i++) {
        this->joinEUI[i] = other.joinEUI[i];
    }
    for (size_t i = 0; i < 8; i++) {
        this->devEUI[i] = other.devEUI[i];
    }
    this->devNonce = other.devNonce;
}

void LoRaJoinRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimArrayPacking(b,this->joinEUI,8);
    doParsimArrayPacking(b,this->devEUI,8);
    doParsimPacking(b,this->devNonce);
}

void LoRaJoinRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->joinEUI,8);
    doParsimArrayUnpacking(b,this->devEUI,8);
    doParsimUnpacking(b,this->devNonce);
}

size_t LoRaJoinRequestFrame::getJoinEUIArraySize() const
{
    return 8;
}

uint8_t LoRaJoinRequestFrame::getJoinEUI(size_t k) const
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)8, (unsigned long)k);
    return this->joinEUI[k];
}

void LoRaJoinRequestFrame::setJoinEUI(size_t k, uint8_t joinEUI)
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)8, (unsigned long)k);
    this->joinEUI[k] = joinEUI;
}

size_t LoRaJoinRequestFrame::getDevEUIArraySize() const
{
    return 8;
}

uint8_t LoRaJoinRequestFrame::getDevEUI(size_t k) const
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)8, (unsigned long)k);
    return this->devEUI[k];
}

void LoRaJoinRequestFrame::setDevEUI(size_t k, uint8_t devEUI)
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)8, (unsigned long)k);
    this->devEUI[k] = devEUI;
}

uint16_t LoRaJoinRequestFrame::getDevNonce() const
{
    return this->devNonce;
}

void LoRaJoinRequestFrame::setDevNonce(uint16_t devNonce)
{
    this->devNonce = devNonce;
}

class LoRaJoinRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_joinEUI,
        FIELD_devEUI,
        FIELD_devNonce,
    };
  public:
    LoRaJoinRequestFrameDescriptor();
    virtual ~LoRaJoinRequestFrameDescriptor();

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

Register_ClassDescriptor(LoRaJoinRequestFrameDescriptor)

LoRaJoinRequestFrameDescriptor::LoRaJoinRequestFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoRaJoinRequestFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

LoRaJoinRequestFrameDescriptor::~LoRaJoinRequestFrameDescriptor()
{
    delete[] propertyNames;
}

bool LoRaJoinRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaJoinRequestFrame *>(obj)!=nullptr;
}

const char **LoRaJoinRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoRaJoinRequestFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoRaJoinRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int LoRaJoinRequestFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_joinEUI
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_devEUI
        FD_ISEDITABLE,    // FIELD_devNonce
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LoRaJoinRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinEUI",
        "devEUI",
        "devNonce",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LoRaJoinRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "joinEUI") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "devEUI") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "devNonce") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *LoRaJoinRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_joinEUI
        "uint8_t",    // FIELD_devEUI
        "uint16_t",    // FIELD_devNonce
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaJoinRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaJoinRequestFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LoRaJoinRequestFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinEUI: return 8;
        case FIELD_devEUI: return 8;
        default: return 0;
    }
}

void LoRaJoinRequestFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoRaJoinRequestFrame'", field);
    }
}

const char *LoRaJoinRequestFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaJoinRequestFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinEUI: return ulong2string(pp->getJoinEUI(i));
        case FIELD_devEUI: return ulong2string(pp->getDevEUI(i));
        case FIELD_devNonce: return ulong2string(pp->getDevNonce());
        default: return "";
    }
}

void LoRaJoinRequestFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinEUI: pp->setJoinEUI(i,string2ulong(value)); break;
        case FIELD_devEUI: pp->setDevEUI(i,string2ulong(value)); break;
        case FIELD_devNonce: pp->setDevNonce(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinRequestFrame'", field);
    }
}

omnetpp::cValue LoRaJoinRequestFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinEUI: return (omnetpp::intval_t)(pp->getJoinEUI(i));
        case FIELD_devEUI: return (omnetpp::intval_t)(pp->getDevEUI(i));
        case FIELD_devNonce: return (omnetpp::intval_t)(pp->getDevNonce());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoRaJoinRequestFrame' as cValue -- field index out of range?", field);
    }
}

void LoRaJoinRequestFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        case FIELD_joinEUI: pp->setJoinEUI(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_devEUI: pp->setDevEUI(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_devNonce: pp->setDevNonce(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinRequestFrame'", field);
    }
}

const char *LoRaJoinRequestFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LoRaJoinRequestFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoRaJoinRequestFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoRaJoinRequestFrame *pp = omnetpp::fromAnyPtr<LoRaJoinRequestFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoRaJoinRequestFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

