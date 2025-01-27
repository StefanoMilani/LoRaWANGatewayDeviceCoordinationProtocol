//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/IPPackets/IPv4Packet.msg.
//

#ifndef __IPV4PACKET_M_H
#define __IPV4PACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class IPv4Packet;
/**
 * Class generated from <tt>src/IPPackets/IPv4Packet.msg:1</tt> by opp_msgtool.
 * <pre>
 * packet IPv4Packet
 * {
 *     uint8_t version; // Actually it is of 4 bits
 *     uint8_t IHL; 	 // Internet Header Length, actually it is of 4 bits
 *     uint8_t TOS;
 *     uint16_t totalLength;
 *     uint16_t identification;
 *     uint16_t fragmentOffset;
 *     uint8_t TTL;
 *     uint8_t protocol;
 *     uint16_t headerChecksum;
 *     uint8_t srcAddress[4];
 *     uint8_t destAddress[4];
 *     uint8_t options[40];
 *     uint8_t payload[65536];
 * }
 * </pre>
 */
class IPv4Packet : public ::omnetpp::cPacket
{
  protected:
    uint8_t version = 0;
    uint8_t IHL = 0;
    uint8_t TOS = 0;
    uint16_t totalLength = 0;
    uint16_t identification = 0;
    uint16_t fragmentOffset = 0;
    uint8_t TTL = 0;
    uint8_t protocol = 0;
    uint16_t headerChecksum = 0;
    uint8_t srcAddress[4] = {0};
    uint8_t destAddress[4] = {0};
    uint8_t options[40] = {0};
    uint8_t payload[65536] = {0};

  private:
    void copy(const IPv4Packet& other);

  protected:
    bool operator==(const IPv4Packet&) = delete;

  public:
    IPv4Packet(const char *name=nullptr, short kind=0);
    IPv4Packet(const IPv4Packet& other);
    virtual ~IPv4Packet();
    IPv4Packet& operator=(const IPv4Packet& other);
    virtual IPv4Packet *dup() const override {return new IPv4Packet(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint8_t getVersion() const;
    virtual void setVersion(uint8_t version);

    virtual uint8_t getIHL() const;
    virtual void setIHL(uint8_t IHL);

    virtual uint8_t getTOS() const;
    virtual void setTOS(uint8_t TOS);

    virtual uint16_t getTotalLength() const;
    virtual void setTotalLength(uint16_t totalLength);

    virtual uint16_t getIdentification() const;
    virtual void setIdentification(uint16_t identification);

    virtual uint16_t getFragmentOffset() const;
    virtual void setFragmentOffset(uint16_t fragmentOffset);

    virtual uint8_t getTTL() const;
    virtual void setTTL(uint8_t TTL);

    virtual uint8_t getProtocol() const;
    virtual void setProtocol(uint8_t protocol);

    virtual uint16_t getHeaderChecksum() const;
    virtual void setHeaderChecksum(uint16_t headerChecksum);

    virtual size_t getSrcAddressArraySize() const;
    virtual uint8_t getSrcAddress(size_t k) const;
    virtual void setSrcAddress(size_t k, uint8_t srcAddress);

    virtual size_t getDestAddressArraySize() const;
    virtual uint8_t getDestAddress(size_t k) const;
    virtual void setDestAddress(size_t k, uint8_t destAddress);

    virtual size_t getOptionsArraySize() const;
    virtual uint8_t getOptions(size_t k) const;
    virtual void setOptions(size_t k, uint8_t options);

    virtual size_t getPayloadArraySize() const;
    virtual uint8_t getPayload(size_t k) const;
    virtual void setPayload(size_t k, uint8_t payload);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IPv4Packet& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IPv4Packet& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline IPv4Packet *fromAnyPtr(any_ptr ptr) { return check_and_cast<IPv4Packet*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __IPV4PACKET_M_H

