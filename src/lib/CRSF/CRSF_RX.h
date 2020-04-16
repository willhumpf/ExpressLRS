#ifndef CRSF_RX_H_
#define CRSF_RX_H_

#include "CRSF.h"

class CRSF_RX : public CRSF
{
public:
    CRSF_RX(HwSerial *dev) : CRSF(dev) {}
    CRSF_RX(HwSerial &dev) : CRSF(&dev) {}

    void handleUartIn(void);

    void ICACHE_RAM_ATTR sendRCFrameToFC();
    void sendLinkStatisticsToFC();

    volatile crsf_channels_s PackedRCdataOut = {0}; // RC data in packed format for output.

private:
    void ICACHE_RAM_ATTR sendFrameToFC(uint8_t *buff, uint8_t size);
    void processPacket(uint8_t const *data);
};

#endif /* CRSF_RX_H_ */