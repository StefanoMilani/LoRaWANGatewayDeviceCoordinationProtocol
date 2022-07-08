//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/LoRaFrames/LoRaJoinRequestFrame.msg.
//

#ifndef __LORAJOINREQUESTFRAME_M_H
#define __LORAJOINREQUESTFRAME_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class LoRaJoinRequestFrame;
/**
 * Class generated from <tt>src/LoRaFrames/LoRaJoinRequestFrame.msg:1</tt> by opp_msgtool.
 * <pre>
 * packet LoRaJoinRequestFrame
 * {
 *     uint8_t joinEUI[8];
 *     uint8_t devEUI[8];
 *     uint16_t devNonce;
 * }
 * </pre>
 */
class LoRaJoinRequestFrame : public ::omnetpp::cPacket
{
  protected:
    uint8_t joinEUI[8] = {0};
    uint8_t devEUI[8] = {0};
    uint16_t devNonce = 0;

  private:
    void copy(const LoRaJoinRequestFrame& other);

  protected:
    bool operator==(const LoRaJoinRequestFrame&) = delete;

  public:
    LoRaJoinRequestFrame(const char *name=nullptr, short kind=0);
    LoRaJoinRequestFrame(const LoRaJoinRequestFrame& other);
    virtual ~LoRaJoinRequestFrame();
    LoRaJoinRequestFrame& operator=(const LoRaJoinRequestFrame& other);
    virtual LoRaJoinRequestFrame *dup() const override {return new LoRaJoinRequestFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual size_t getJoinEUIArraySize() const;
    virtual uint8_t getJoinEUI(size_t k) const;
    virtual void setJoinEUI(size_t k, uint8_t joinEUI);

    virtual size_t getDevEUIArraySize() const;
    virtual uint8_t getDevEUI(size_t k) const;
    virtual void setDevEUI(size_t k, uint8_t devEUI);

    virtual uint16_t getDevNonce() const;
    virtual void setDevNonce(uint16_t devNonce);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LoRaJoinRequestFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LoRaJoinRequestFrame& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline LoRaJoinRequestFrame *fromAnyPtr(any_ptr ptr) { return check_and_cast<LoRaJoinRequestFrame*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __LORAJOINREQUESTFRAME_M_H

