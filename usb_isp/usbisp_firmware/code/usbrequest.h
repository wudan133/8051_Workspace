#ifndef _USBREQUEST_H
#define _USBREQUEST_H



//hid  related 
#define   GET_REPORT  1      
#define   SET_REPORT  9    
#define   GET_IDLE    0x02      
#define   SET_IDLE    0x0a  

/* Standard Request Codes */
#define GET_STATUS			0x00
#define CLEAR_FEATURE		0x01
#define SET_FEATURE			0x03
#define SET_ADDRESS			0x05
#define GET_DESCRIPTOR		0x06
#define SET_DESCRIPTOR		0x07
#define GET_CONFIGURATION	0x08
#define SET_CONFIGURATION	0x09
#define GET_INTERFACE		0x0A
#define SET_INTERFACE		0x0B
#define SYNCH_FRAME			0x0C


/* Request Type Field */
#define M_CMD_TYPEMASK  0x60
#define M_CMD_STDREQ    0x00
#define M_CMD_CLASSREQ  0x20
#define M_CMD_VENDREQ   0x40
#define M_CMD_STDDEVIN  0x80
#define M_CMD_STDDEVOUT 0x00
#define M_CMD_STDIFIN   0x81
#define M_CMD_STDIFOUT  0x01
#define M_CMD_STDEPIN   0x82
#define M_CMD_STDEPOUT  0x02

#endif

