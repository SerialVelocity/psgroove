#include "usbdrv.h"

void interruptWrite_Byte(uchar byte);
void interruptWrite_Word(uint16_t word);
void sendInterruptBuffer();
void resetDataToggle();
void pUsbSetInterrupt(uchar *pData, uchar len);
void outBuffer_Write_Byte(uchar byte);
void outBuffer_Write_Word(uint16_t word);
usbMsgLen_t sendOutBuffer();
