#ifndef	__MAIN_H__
#define __MAIN_H__


unsigned char data intr_in          _at_ 0x32;
unsigned char data intr_usb         _at_ 0x33;
unsigned char data intr_out         _at_ 0x34; 

extern void Cmd_Process();

#endif