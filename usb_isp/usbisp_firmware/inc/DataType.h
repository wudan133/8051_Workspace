#ifndef	__DATATYPE_H__
#define __DATATYPE_H__

#define TRUE 	1
#define FALSE	0
#define IN 0
#define OUT 1
#define true  1
#define false 0
#ifndef NULL
#define NULL 0
#endif

#define MS185X_DRV_API
#define MS185X_MW_API
#define MS1850_DRV_API
#define MS1850_MW_API

#define CG7100_DRV_API
#define CG7100_MW_API
#define CG7100_EXT_APIS  0
#define CG7100_DEBUG_LOG  0
#define CG7100_FPGA_VERIFY 0   //if real chip please modify to 0
//#define CG7100_CLK_RESRT_CONFIG_USE_DRIVER_API

typedef unsigned char 	BOOL;
typedef unsigned char 	bool;
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	DWORD;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned long  UINT32;

typedef signed char  INT8;
typedef signed short INT16;
typedef signed long  INT32;
typedef void  VOID;

#define XBYTE      BYTE   xdata
#define XWORD    WORD xdata
#define XDWORD  DWORD xdata

#ifndef _countof
#define _countof(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))
#endif

#define SWAP(x)   ((((x)&0xFF)<<8)|(((x)>>8)&0xFF))
#define MSB(x)	  (BYTE)(((x)>>8)&0xff)

#define CLEAR_ALL_BIT 0x00;
#define SET_BIT0 0x01
#define SET_BIT1 0x02
#define SET_BIT2 0x04
#define SET_BIT3 0x08
#define SET_BIT4 0x10
#define SET_BIT5 0x20
#define SET_BIT6 0x40
#define SET_BIT7 0x80

/*
* generic mask macro definitions
*/
#define MSRT_BIT0                   (0x01)
#define MSRT_BIT1                   (0x02)
#define MSRT_BIT2                   (0x04)
#define MSRT_BIT3                   (0x08)
#define MSRT_BIT4                   (0x10)
#define MSRT_BIT5                   (0x20)
#define MSRT_BIT6                   (0x40)
#define MSRT_BIT7                   (0x80)
    
#define MSRT_MSB8BITS               MSRT_BIT7
#define MSRT_LSB                    MSRT_BIT0
    // Bit7 ~ Bit0
#define MSRT_BITS7_6                (0xC0)
#define MSRT_BITS7_5                (0xE0)
#define MSRT_BITS7_4                (0xF0)
#define MSRT_BITS6_5                (0x60)
#define MSRT_BITS6_4                (0x70)
#define MSRT_BITS5_4                (0x30)
#define MSRT_BITS4_3                (0x18)
#define MSRT_BITS3_2                (0x0C)
#define MSRT_BITS3_1                (0x0E)
#define MSRT_BITS3_0                (0x0F)
#define MSRT_BITS2_1                (0x06)
#define MSRT_BITS2_0                (0x07)
#define MSRT_BITS1_0                (0x03)
#define MSRT_BITS6_0                (0x7f)
#define MSRT_BITS5_0                (0x3f)
#define MSRT_BITS4_2                (0x1c)
#define MSRT_BITS6_2                (0x7c)
#define MSRT_BITS4_0                (0x1f)
#define MSRT_BITS5_3                (0x38)
#define MSRT_BITS7_0                (0xff)
#define MSRT_BITS5_2                (0x3c)


#define WAIT_TWHR 0xC0
#define WAIT_TR   0x80


#define USE1BIT 0x01
#define USE2BIT 0x03
#define USE3BIT 0x07
#define USE4BIT 0x0f
#define USE5BIT 0x1f
#define USE6BIT 0x3f
#define USE7BIT 0x7f
#define USE8BIT 0xff


#define MAX_CE_CNT     0x04
#define FOUR_PLANE_CNT 0x04
#define TWO_PLANE_CNT  0x02

#define FIRST_CYCLE 0
#define SECOND_CYCLE 1
#define THIRD_CYCLE 2
/***************************************************************
	USB协议，描述符定义
****************************************************************/
//#define DESCRIPT_LENGTH					    0x1A8
#define DESCRIPT_LENGTH					    0x19C	  		
#define USB_DEVICE_DESC_TYPE                0x01
#define USB_CONFIG_DESC_TYPE   		        0x02
#define USB_STRING_DESC_TYPE                0x03
#define USB_INTERFACE_DESC_TYPE             0x04
#define USB_ENDPOINT_DESC_TYPE              0x05
#define USB_QUALIFIER_DESC_TYPE				0x06
#define	USB_OTHERSPEED_DESC_TYPE			0x07

#define USB_REQUEST_GET_STATUS              0x00
#define USB_REQUEST_CLEAR_FEATURE           0x01
#define USB_REQUEST_SET_FEATURE             0x03
#define USB_REQUEST_SET_ADDRESS             0x05
#define USB_REQUEST_GET_DESCRIPTOR          0x06
#define USB_REQUEST_SET_DESCRIPTOR          0x07
#define USB_REQUEST_GET_CONFIGURATION       0x08
#define USB_REQUEST_SET_CONFIGURATION       0x09
#define USB_REQUEST_GET_INTERFACE           0x0A
#define USB_REQUEST_SET_INTERFACE           0x0B
#define USB_REQUEST_SYNC_FRAME              0x0C
#define USB_REQUEST_GET_MAXLUN				0xFE
#define USB_REQUEST_BOUL_RESET				0xFF

//-----------------------------
#define	EP0_CMD		0
#define	EP0_RX		1
#define	EP0_TX		2
#define	EP0_IDEL	3


#define TEST_MODE		2
#define ENDP_HALT		0
#define REMOTE_WAK		1

#define	TEST_J			1
#define	TEST_K			2
#define	TEST_PKT		4
#define TEST_SE0_NAK	3

#define	DEV_DEFAULT	0
#define DEV_ADDRESS	1
#define	DEV_CONFIG	2

typedef struct _T_MS_VIDEO_SIZE_
{
    UINT16 u16_h;
    UINT16 u16_v;
} VIDEOSIZE_T;

//typedef struct _T_MS185X_VIDEO_TIMING_
//{
//    UINT8           u8_polarity;
//    UINT16          u16_htotal;
//    UINT16          u16_vtotal;
//    UINT16          u16_hactive;
//    UINT16          u16_vactive;
//    UINT16          u16_pixclk;     /*10000hz*/
//    UINT16          u16_vfreq;      /*0.01hz*/
//    UINT16          u16_hoffset;    /* h sync start to h active*/
//    UINT16          u16_voffset;    /* v sync start to v active*/
//    UINT16          u16_hsyncwidth;
//    UINT16          u16_vsyncwidth;
//} VIDEOTIMING_T;




void Delay_us(unsigned int i);
void XDATA_WriteByte(UINT16 u16_index, UINT8 u8_value) ;
void XDATA_ClrBits(UINT16 u16_index, UINT8 u8_mask) ;
void XDATA_ModBits(UINT16 u16_index, UINT8 u8_mask, UINT8 u8_value);
void XDATA_SetBits(UINT16 u16_index, UINT8 u8_mask);
UINT8 XDATA_ReadByte(UINT16 u16_index);
//UINT32 XDATA_ReadRange(UINT16 u16_index, UINT8 u8_bitpos, UINT8 u8_length);
VOID XDATA_WriteRange(UINT16 u16_index, UINT8 u8_bitpos, UINT8 u8_length, UINT32 u32_value);

VOID XDATA_ToggleBits(UINT16 u16_index, UINT8 u8_mask, BOOL b_set);
VOID XDATA_WriteWord(UINT16 u16_index, UINT16 u16_value);

#if 0 //Old version residue, recommended deleted dwu 20161228
#define MS1850_DEINTERLACE_DISABLE  (0)
#define MS1850_USE_MTOOLS           (0)
#define MS1850_INC_MULTI_WINDOWS    (0)
#define MS1850_SDRAM_SIZE           (2)
#define MS1850_3D_DECODER_ENABLE    (1)
#define MS1850_FPGA_VERIFY          (0)
#endif

void Delay_ms(unsigned int count_ms);



// tvd reg_rw
void HAL_WriteByte(UINT8 u8_index, UINT8 u8_value);
UINT8 HAL_ReadByte(UINT8 u8_index);
void HAL_ClrBits(UINT8 u8_index, UINT8 u8_mask);
void HAL_ModBits(UINT8 u8_index, UINT8 u8_mask, UINT8 u8_value);
void HAL_SetBits(UINT8 u8_index, UINT8 u8_mask);
UINT32 HAL_ReadRange(UINT16 u16_index, UINT8 u8_bitpos, UINT8 u8_length);
VOID HAL_WriteRange(UINT16 u16_index, UINT8 u8_bitpos, UINT8 u8_length, UINT32 u32_value);

#endif
