//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/IPPackets/IPv4Packet.msg.
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
#include "IPv4Packet_m.h"

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

Register_Class(IPv4Packet)

IPv4Packet::IPv4Packet(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

IPv4Packet::IPv4Packet(const IPv4Packet& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IPv4Packet::~IPv4Packet()
{
}

IPv4Packet& IPv4Packet::operator=(const IPv4Packet& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPv4Packet::copy(const IPv4Packet& other)
{
    this->version = other.version;
    this->IHL = other.IHL;
    this->TOS = other.TOS;
    this->totalLength = other.totalLength;
    this->identification = other.identification;
    this->fragmentOffset = other.fragmentOffset;
    this->TTL = other.TTL;
    this->protocol = other.protocol;
    this->headerChecksum = other.headerChecksum;
    for (size_t i = 0; i < 4; i++) {
        this->srcAddress[i] = other.srcAddress[i];
    }
    for (size_t i = 0; i < 4; i++) {
        this->destAddress[i] = other.destAddress[i];
    }
    for (size_t i = 0; i < 40; i++) {
        this->options[i] = other.options[i];
    }
    for (size_t i = 0; i < 65536; i++) {
        this->payload[i] = other.payload[i];
    }
}

void IPv4Packet::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->IHL);
    doParsimPacking(b,this->TOS);
    doParsimPacking(b,this->totalLength);
    doParsimPacking(b,this->identification);
    doParsimPacking(b,this->fragmentOffset);
    doParsimPacking(b,this->TTL);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->headerChecksum);
    doParsimArrayPacking(b,this->srcAddress,4);
    doParsimArrayPacking(b,this->destAddress,4);
    doParsimArrayPacking(b,this->options,40);
    doParsimArrayPacking(b,this->payload,65536);
}

void IPv4Packet::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->IHL);
    doParsimUnpacking(b,this->TOS);
    doParsimUnpacking(b,this->totalLength);
    doParsimUnpacking(b,this->identification);
    doParsimUnpacking(b,this->fragmentOffset);
    doParsimUnpacking(b,this->TTL);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->headerChecksum);
    doParsimArrayUnpacking(b,this->srcAddress,4);
    doParsimArrayUnpacking(b,this->destAddress,4);
    doParsimArrayUnpacking(b,this->options,40);
    doParsimArrayUnpacking(b,this->payload,65536);
}

uint8_t IPv4Packet::getVersion() const
{
    return this->version;
}

void IPv4Packet::setVersion(uint8_t version)
{
    this->version = version;
}

uint8_t IPv4Packet::getIHL() const
{
    return this->IHL;
}

void IPv4Packet::setIHL(uint8_t IHL)
{
    this->IHL = IHL;
}

uint8_t IPv4Packet::getTOS() const
{
    return this->TOS;
}

void IPv4Packet::setTOS(uint8_t TOS)
{
    this->TOS = TOS;
}

uint16_t IPv4Packet::getTotalLength() const
{
    return this->totalLength;
}

void IPv4Packet::setTotalLength(uint16_t totalLength)
{
    this->totalLength = totalLength;
}

uint16_t IPv4Packet::getIdentification() const
{
    return this->identification;
}

void IPv4Packet::setIdentification(uint16_t identification)
{
    this->identification = identification;
}

uint16_t IPv4Packet::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void IPv4Packet::setFragmentOffset(uint16_t fragmentOffset)
{
    this->fragmentOffset = fragmentOffset;
}

uint8_t IPv4Packet::getTTL() const
{
    return this->TTL;
}

void IPv4Packet::setTTL(uint8_t TTL)
{
    this->TTL = TTL;
}

uint8_t IPv4Packet::getProtocol() const
{
    return this->protocol;
}

void IPv4Packet::setProtocol(uint8_t protocol)
{
    this->protocol = protocol;
}

uint16_t IPv4Packet::getHeaderChecksum() const
{
    return this->headerChecksum;
}

void IPv4Packet::setHeaderChecksum(uint16_t headerChecksum)
{
    this->headerChecksum = headerChecksum;
}

size_t IPv4Packet::getSrcAddressArraySize() const
{
    return 4;
}

uint8_t IPv4Packet::getSrcAddress(size_t k) const
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    return this->srcAddress[k];
}

void IPv4Packet::setSrcAddress(size_t k, uint8_t srcAddress)
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    this->srcAddress[k] = srcAddress;
}

size_t IPv4Packet::getDestAddressArraySize() const
{
    return 4;
}

uint8_t IPv4Packet::getDestAddress(size_t k) const
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    return this->destAddress[k];
}

void IPv4Packet::setDestAddress(size_t k, uint8_t destAddress)
{
    if (k >= 4) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)4, (unsigned long)k);
    this->destAddress[k] = destAddress;
}

size_t IPv4Packet::getOptionsArraySize() const
{
    return 40;
}

uint8_t IPv4Packet::getOptions(size_t k) const
{
    if (k >= 40) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)40, (unsigned long)k);
    return this->options[k];
}

void IPv4Packet::setOptions(size_t k, uint8_t options)
{
    if (k >= 40) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)40, (unsigned long)k);
    this->options[k] = options;
}

size_t IPv4Packet::getPayloadArraySize() const
{
    return 65536;
}

uint8_t IPv4Packet::getPayload(size_t k) const
{
    if (k >= 65536) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)65536, (unsigned long)k);
    return this->payload[k];
}

void IPv4Packet::setPayload(size_t k, uint8_t payload)
{
    if (k >= 65536) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)65536, (unsigned long)k);
    this->payload[k] = payload;
}

class IPv4PacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_version,
        FIELD_IHL,
        FIELD_TOS,
        FIELD_totalLength,
        FIELD_identification,
        FIELD_fragmentOffset,
        FIELD_TTL,
        FIELD_protocol,
        FIELD_headerChecksum,
        FIELD_srcAddress,
        FIELD_destAddress,
        FIELD_options,
        FIELD_payload,
    };
  public:
    IPv4PacketDescriptor();
    virtual ~IPv4PacketDescriptor();

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

Register_ClassDescriptor(IPv4PacketDescriptor)

IPv4PacketDescriptor::IPv4PacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IPv4Packet)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

IPv4PacketDescriptor::~IPv4PacketDescriptor()
{
    delete[] propertyNames;
}

bool IPv4PacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4Packet *>(obj)!=nullptr;
}

const char **IPv4PacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IPv4PacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IPv4PacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 13+base->getFieldCount() : 13;
}

unsigned int IPv4PacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_IHL
        FD_ISEDITABLE,    // FIELD_TOS
        FD_ISEDITABLE,    // FIELD_totalLength
        FD_ISEDITABLE,    // FIELD_identification
        FD_ISEDITABLE,    // FIELD_fragmentOffset
        FD_ISEDITABLE,    // FIELD_TTL
        FD_ISEDITABLE,    // FIELD_protocol
        FD_ISEDITABLE,    // FIELD_headerChecksum
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_srcAddress
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_destAddress
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_options
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_payload
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *IPv4PacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "IHL",
        "TOS",
        "totalLength",
        "identification",
        "fragmentOffset",
        "TTL",
        "protocol",
        "headerChecksum",
        "srcAddress",
        "destAddress",
        "options",
        "payload",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int IPv4PacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "version") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "IHL") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "TOS") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "totalLength") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "identification") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "fragmentOffset") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "TTL") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "protocol") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "headerChecksum") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "destAddress") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "options") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 12;
    return base ? base->findField(fieldName) : -1;
}

const char *IPv4PacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_version
        "uint8_t",    // FIELD_IHL
        "uint8_t",    // FIELD_TOS
        "uint16_t",    // FIELD_totalLength
        "uint16_t",    // FIELD_identification
        "uint16_t",    // FIELD_fragmentOffset
        "uint8_t",    // FIELD_TTL
        "uint8_t",    // FIELD_protocol
        "uint16_t",    // FIELD_headerChecksum
        "uint8_t",    // FIELD_srcAddress
        "uint8_t",    // FIELD_destAddress
        "uint8_t",    // FIELD_options
        "uint8_t",    // FIELD_payload
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4PacketDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4PacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int IPv4PacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return 4;
        case FIELD_destAddress: return 4;
        case FIELD_options: return 40;
        case FIELD_payload: return 65536;
        default: return 0;
    }
}

void IPv4PacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IPv4Packet'", field);
    }
}

const char *IPv4PacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4PacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        case FIELD_version: return ulong2string(pp->getVersion());
        case FIELD_IHL: return ulong2string(pp->getIHL());
        case FIELD_TOS: return ulong2string(pp->getTOS());
        case FIELD_totalLength: return ulong2string(pp->getTotalLength());
        case FIELD_identification: return ulong2string(pp->getIdentification());
        case FIELD_fragmentOffset: return ulong2string(pp->getFragmentOffset());
        case FIELD_TTL: return ulong2string(pp->getTTL());
        case FIELD_protocol: return ulong2string(pp->getProtocol());
        case FIELD_headerChecksum: return ulong2string(pp->getHeaderChecksum());
        case FIELD_srcAddress: return ulong2string(pp->getSrcAddress(i));
        case FIELD_destAddress: return ulong2string(pp->getDestAddress(i));
        case FIELD_options: return ulong2string(pp->getOptions(i));
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        default: return "";
    }
}

void IPv4PacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2ulong(value)); break;
        case FIELD_IHL: pp->setIHL(string2ulong(value)); break;
        case FIELD_TOS: pp->setTOS(string2ulong(value)); break;
        case FIELD_totalLength: pp->setTotalLength(string2ulong(value)); break;
        case FIELD_identification: pp->setIdentification(string2ulong(value)); break;
        case FIELD_fragmentOffset: pp->setFragmentOffset(string2ulong(value)); break;
        case FIELD_TTL: pp->setTTL(string2ulong(value)); break;
        case FIELD_protocol: pp->setProtocol(string2ulong(value)); break;
        case FIELD_headerChecksum: pp->setHeaderChecksum(string2ulong(value)); break;
        case FIELD_srcAddress: pp->setSrcAddress(i,string2ulong(value)); break;
        case FIELD_destAddress: pp->setDestAddress(i,string2ulong(value)); break;
        case FIELD_options: pp->setOptions(i,string2ulong(value)); break;
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IPv4Packet'", field);
    }
}

omnetpp::cValue IPv4PacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        case FIELD_version: return (omnetpp::intval_t)(pp->getVersion());
        case FIELD_IHL: return (omnetpp::intval_t)(pp->getIHL());
        case FIELD_TOS: return (omnetpp::intval_t)(pp->getTOS());
        case FIELD_totalLength: return (omnetpp::intval_t)(pp->getTotalLength());
        case FIELD_identification: return (omnetpp::intval_t)(pp->getIdentification());
        case FIELD_fragmentOffset: return (omnetpp::intval_t)(pp->getFragmentOffset());
        case FIELD_TTL: return (omnetpp::intval_t)(pp->getTTL());
        case FIELD_protocol: return (omnetpp::intval_t)(pp->getProtocol());
        case FIELD_headerChecksum: return (omnetpp::intval_t)(pp->getHeaderChecksum());
        case FIELD_srcAddress: return (omnetpp::intval_t)(pp->getSrcAddress(i));
        case FIELD_destAddress: return (omnetpp::intval_t)(pp->getDestAddress(i));
        case FIELD_options: return (omnetpp::intval_t)(pp->getOptions(i));
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IPv4Packet' as cValue -- field index out of range?", field);
    }
}

void IPv4PacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_IHL: pp->setIHL(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_TOS: pp->setTOS(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_totalLength: pp->setTotalLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_identification: pp->setIdentification(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_fragmentOffset: pp->setFragmentOffset(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_TTL: pp->setTTL(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_protocol: pp->setProtocol(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_headerChecksum: pp->setHeaderChecksum(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_srcAddress: pp->setSrcAddress(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_destAddress: pp->setDestAddress(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_options: pp->setOptions(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IPv4Packet'", field);
    }
}

const char *IPv4PacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr IPv4PacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IPv4PacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IPv4Packet *pp = omnetpp::fromAnyPtr<IPv4Packet>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IPv4Packet'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

