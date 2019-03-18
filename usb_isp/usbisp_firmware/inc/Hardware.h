#ifndef	__HARDWARE_H__
#define __HARDWARE_H__

/*************************************************************************
  8051 Mcu Register
**************************************************************************/

sfr TEST_REG = 0xFF;

sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr PCON    = 0x87;
sfr TCON    = 0x88;
sfr IEN0    = 0xA8;
sfr IP0     = 0xA9;//0xB8;
sfr PSW     = 0xD0;
sfr ACC     = 0xE0;
sfr B       = 0xF0;

/* Extensions  */
sfr DPL1   	= 0x84;
sfr DPH1   	= 0x85;
sfr DPS    	= 0x92;//0x86;
sfr CKCON  	= 0x8E;
sfr IEN2	= 0x8F;
sfr IRCON  	= 0xC0;//0xD8;
sfr IEN1    = 0xB8;//0xE8;
sfr IP1    	= 0xB9;//0xF8;

/*  BIT Registers  */
/*  PSW */
sbit CY     = PSW^7;
sbit AC     = PSW^6;
sbit F0     = PSW^5;
sbit RS1    = PSW^4;
sbit RS0    = PSW^3;
sbit OV     = PSW^2;
sbit FL     = PSW^1;
sbit P      = PSW^0;

/*  IEN0  */
sbit EA     = IEN0^7;
sbit ES1    = IEN0^6;
sbit ET2    = IEN0^5;
sbit ES0    = IEN0^4;
sbit ET1    = IEN0^3;
sbit EX1    = IEN0^2;
sbit ET0    = IEN0^1;
sbit EX0    = IEN0^0;

/*  TCON  */
sbit TF1    = TCON^7;
sbit TR1    = TCON^6;
sbit TF0    = TCON^5;
sbit TR0    = TCON^4;
sbit IE1    = TCON^3;
sbit IT1    = TCON^2;
sbit IE0    = TCON^1;
sbit IT0    = TCON^0;

/*  IRCON  */
sbit IEX6   = IRCON^5;
sbit IEX5   = IRCON^4;
sbit IEX4   = IRCON^3;
sbit IEX3   = IRCON^2;
sbit IEX2   = IRCON^1;

/*  IEN1  */
sbit EX6  	= IEN1^5;
sbit EX5  	= IEN1^4;
sbit EX4 	= IEN1^3;
sbit EX3  	= IEN1^2;
sbit EX2  	= IEN1^1;

#define	  InterruptDisable()	EA=EX0=EX1 = ET0=ET1= 0;
#define   InterruptEnable()		EA=EX0 = EX1 = ET0 =1 

/*************************************************************************
  SIE Register
**************************************************************************/
sfr reg_usb_Index              = 0x93;   
sfr reg_usb_Faddr              = 0x94;  
sfr reg_usb_Power              = 0x95;
sfr reg_usb_IntrIn             = 0x96;
sfr reg_usb_IntrOut            = 0x97;
sfr reg_usb_IntrInE            = 0x9A;
sfr reg_usb_IntrOutE           = 0x9B;
sfr reg_usb_IntrUSB            = 0x9C;
sfr reg_usb_IntrUSBE           = 0x9D;
sfr reg_usb_FrameL             = 0x9E;
sfr reg_usb_FrameH             = 0x9F;
sfr reg_usb_Testmode           = 0xA1;
sfr reg_usb_InMaxPL            = 0xA2;
sfr reg_usb_InMaxPH            = 0xA3;
sfr reg_usb_OutMaxPL           = 0xA4;    
sfr reg_usb_OutMaxPH           = 0xA5;
sfr reg_usb_CountL             = 0xA6;        
sfr reg_usb_CountH             = 0xA7;    
sfr reg_usb_End0                = 0xAB;    
sfr reg_usb_End1                = 0xAC; 
sfr reg_usb_End2                = 0xAD; 
sfr reg_usb_End3                = 0xAE;   

#define reg_usb_Ep0		reg_usb_End0
#define reg_usb_Ep1		reg_usb_End1
#define reg_usb_Ep2		reg_usb_End2
#define reg_usb_Ep3		reg_usb_End3

/*****************************
the usb_CSR0 regs only can be used
when usb_Index = 0
*****************************/

sfr reg_usb_CSR0			   = 0x80;
	sbit reg_EP0_OutPktRdy	   = 0x80+0;
	sbit reg_EP0_InPktRdy	   = 0x80+1;
	sbit reg_EP0_SentStall	   = 0x80+2;
	sbit reg_EP0_DataEnd	   = 0x80+3;
	sbit reg_EP0_SetupEnd	   = 0x80+4;
	sbit reg_EP0_SendStall	   = 0x80+5;
	sbit reg_EP0_SevOutPktRdy  = 0x80+6;
	sbit reg_EP0_SevSetupEnd   = 0x80+7;
//////////////////////////////	

sfr reg_usb_InCSRL             = 0x80;
    sbit reg_IntPktRdy         = 0x80+0;
    sbit reg_FifoNotEmpty      = 0x80+1;
    sbit reg_UnderRun          = 0x80+2;
    sbit reg_InFlushFifo       = 0x80+3;
    sbit reg_InSendStall       = 0x80+4;
    sbit reg_InSentStall       = 0x80+5;
    sbit reg_InClrDataTog      = 0x80+6;
    sbit reg_IncompTx          = 0x80+7;
    
sfr reg_usb_InCSRH             = 0x90;
    sbit reg_InFrcDataTog      = 0x90+3;
    sbit reg_InDmaEnab         = 0x90+4;
    sbit reg_InMode            = 0x90+5;
    sbit reg_InIso             = 0x90+6;
    sbit reg_AutoSet           = 0x90+7;
    
sfr reg_usb_OutCSRL            = 0x8B;  
    sbit reg_OuttPktRdy        = 0x8B+0;
    sbit reg_OutFifoFull       = 0x8B+1;
    sbit reg_OverRun           = 0x8B+2;
    sbit reg_DataError         = 0x8B+3;
    sbit reg_OutFlushFifo      = 0x8B+4;
    sbit reg_OutSendStall      = 0x8B+5;
    sbit reg_OutSentStall      = 0x8B+6;
    sbit reg_OutClrDataTog     = 0x8B+7;
                                    
sfr reg_usb_OutCSRH            = 0x8C;  
    sbit reg_IncompRx          = 0x8C+0;
    sbit reg_OutDmaMode        = 0x8C+3;
    sbit reg_DisYet            = 0x8C+4;
    sbit reg_OutDmaEnb         = 0x8C+5;
    sbit reg_OutIso            = 0x8C+6;
    sbit reg_AutoClear         = 0x8C+7;

/*************************************************************************
 Global Register
**************************************************************************/

sfr reg_DmaCtrl  =	0xE8;
  sbit reg_DmaStart = 0xE8+0;
  sbit reg_DmaDecelerate = 0xE8+4;


sfr reg_usb_BusRest                = 0xe9; 		 	//default 0x00 1:busreset staus  0:other
 
sfr	reg_mcu_access_usb_mode			   = 0xEA;		   //default 0x00  1:MCU访问USB 0：Video audio 写USB

//gpio   
sfr	reg_gpio_data				   = 0xA0;			//default 0x00
  sbit reg_gpio7_data	   			= 0xA0+7;   
  sbit reg_gpio6_data	   			= 0xA0+6;   
  sbit reg_gpio5_data	   			= 0xA0+5;   
  sbit reg_gpio4_data	   			= 0xA0+4;
  sbit reg_gpio3_data	   			= 0xA0+3;   
  sbit reg_gpio2_data	   			= 0xA0+2;   
  sbit reg_gpio1_data	   			= 0xA0+1;   
  sbit reg_gpio0_data	   			= 0xA0+0;   
  
sfr	reg_gpio_oen				   = 0xB0;			//default 0xff    1:input 0:output
  sbit reg_gpio7_oen	   			= 0xB0+7;   
  sbit reg_gpio6_oen	   			= 0xB0+6;   
  sbit reg_gpio5_oen	   			= 0xB0+5;   
  sbit reg_gpio4_oen	   			= 0xB0+4;
  sbit reg_gpio3_oen	   			= 0xB0+3;   
  sbit reg_gpio2_oen	   			= 0xB0+2;   
  sbit reg_gpio1_oen	   			= 0xB0+1;   
  sbit reg_gpio0_oen	   			= 0xB0+0;   
   




/*************************************************************************
 	Global Register
**************************************************************************/
#define GLOBAL_BASE			        0xF000
#define BYTE_TABLE_BASE             0xF0A0

#define GPIO_PAD_CONFIG						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x03))	//F030  

#define reg_ResetConfig                      (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x00)) //bit2: audio reset  bit1:video reset bit0:UTM reset
#define reg_ClkSuspendConfig                 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x01)) //bit0: 0:	1:clk not stop
//#define reg_TVD_CLK_Config					 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x02))   //bit[7:2] reserve bit1:0从ADC输出的时钟作为TVD时钟	 bit0: 0TVD时钟停止 1TVD时钟有效
#define reg_LedMode                          (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x22))	//F022	 2b10 bit1:LED_DATA 0 亮，1 灭；bit0 LED_MODE 0G根据LED_DATA让LED固定亮灭，1：根据reg_LedThresholdH频率让LED闪烁    
#define reg_LedThresholdH                    (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x23))	//F023   8h05 LED_Cnt 是26bit counter，当MSB = reg_LedThresholdH,且LSB=8H3FFFF时 LED取反
#define reg_TimerEn                          (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x24))	//F024	 1b0  0timer_cnt清为26h0000000；1：timer_cnt累加
#define reg_TimerCntL                        (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x25))	//F025   8hff	软件初始化CNT寄存器，当高16bit = {TIMER_CNTH,TIMER_CNTH}产生int 1
#define reg_TimerCntH                        (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x26))	//F026


#define reg_Timer_int						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x30))	//F030
#define	reg_Vsync_neg_Int_req				 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x31))	//F031	  bit0 : 硬件置1表示有vsyn_neg中断请求，软件清0

#define SDRAM_CTRL                           (*(volatile UINT8 xdata*)(0xf9c2))

#define ADC_BASE_ADDR     0xF800+0X310
#define reg_ADC_Byte0                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x0))			 //bit4-0: reg_AfOffsetCB[4:0] 

#define REG_BG_BASE			        0xF080
#define reg_bg_Byte0							(*(volatile UINT8 xdata*)(REG_BG_BASE+0x00))  //  
#define reg_bg_Byte1				(*(volatile UINT8 xdata*)(REG_BG_BASE+0x01))  // 
#define reg_bg_Byte2				(*(volatile UINT8 xdata*)(REG_BG_BASE+0x02))  // 


#define VP_BASS_ADDRESS				0xF100

#define reg_VSyncStaus							(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF0))  // bit0 : 0:blank 1：active
#define reg_Video_FIFO_RemainDataL				(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF1))  // 
#define reg_Video_FIFO_RemainDataH				(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF2))  // 
#define reg_Video_MaxDmaLenL					(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF3))  // 
#define reg_Video_MaxDmaLenH					(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF4))  // 
#define reg_VideoToUSB_DmaCNTL					(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF5))  // 
#define reg_VideoToUSB_DmaCNTH					(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF6))  // 
#define reg_Video_fifoflush				        (*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xF7))  //
#define reg_VideoTestMode                     	(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xFE))  // 2b00  0:输出CVBS Decode信号 1PIEXL 累加数 2：输出PAL彩条	  3输出NTSC制彩条
#define reg_VideoEnable                      	(*(volatile UINT8 xdata*)(VP_BASS_ADDRESS+0xFF))  // 1b0


#define AUDIO_BASE					0xF300
#define reg_AudioEnable							 	 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x00))  // bit0: 1:open 0:close
#define reg_Audio_ADC_SEL						 	 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x01))  // bit0: 0:IntADC 1:ExitADC
#define reg_IntADC_PGA						 	 	 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x02))  // 音量调节  值越大音量越大
#define reg_IntADC_Filter_Bypass					 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x03))  //	default 0x01  0：close 1：open
#define reg_Audio_mute					             (*(volatile UINT8 xdata*)(AUDIO_BASE+0x04))  // 0 normal 1 mute

#define reg_Audio_regf306					             (*(volatile UINT8 xdata*)(AUDIO_BASE+0x06)) 
#define reg_Audio_regf307					             (*(volatile UINT8 xdata*)(AUDIO_BASE+0x07))
#define reg_Audio_regf308					             (*(volatile UINT8 xdata*)(AUDIO_BASE+0x08)) 
#define reg_Audio_regf309					             (*(volatile UINT8 xdata*)(AUDIO_BASE+0x09))

#define reg_ExtADC_Capture_Config					 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x10))  //	default 0x01  0:LR 第一个CLK上升沿采样数据  1：第二个CLK采样数据
#define reg_ExtADC_Test_Mode						 (*(volatile UINT8 xdata*)(AUDIO_BASE+0x11))  //

#define reg_IntADC_Config					    	(*(volatile UINT8 xdata*)(AUDIO_BASE+0x12))  //	 
#define reg_Audio_FIFO2USB_Start				    (*(volatile UINT8 xdata*)(AUDIO_BASE+0x13))  //
#define reg_Audio_FIFO_Data_Reserved				(*(volatile UINT8 xdata*)(AUDIO_BASE+0x14))  //
#define reg_Audio_FIFO_Trans_Cnt				    (*(volatile UINT8 xdata*)(AUDIO_BASE+0x15))  //
#define reg_Audio_FIFO_Flush				        (*(volatile UINT8 xdata*)(AUDIO_BASE+0x16))  //


//JPEG_REG
#define JPEG_BASE					0xF500
#define  reg_JPEG_0_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x00))
#define  reg_JPEG_0_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x01))
#define  reg_JPEG_0_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x02))
#define  reg_JPEG_0_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x03))
#define  reg_JPEG_1_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x04))
#define  reg_JPEG_1_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x05))
#define  reg_JPEG_1_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x06))
#define  reg_JPEG_1_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x07))
#define  reg_JPEG_2_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x08))
#define  reg_JPEG_2_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x09))
#define  reg_JPEG_2_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x0A))
#define  reg_JPEG_2_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x0B))
#define  reg_JPEG_3_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x0C))
#define  reg_JPEG_3_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x0D))
#define  reg_JPEG_3_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x0E))
#define  reg_JPEG_3_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x0F))
#define  reg_JPEG_4_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x10))
#define  reg_JPEG_4_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x11))
#define  reg_JPEG_4_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x12))
#define  reg_JPEG_4_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x13))
#define  reg_JPEG_5_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x14))
#define  reg_JPEG_5_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x15))
#define  reg_JPEG_5_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x16))
#define  reg_JPEG_5_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x17))
#define  reg_JPEG_6_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x18))
#define  reg_JPEG_6_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x19))
#define  reg_JPEG_6_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x1A))
#define  reg_JPEG_6_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x1B))
#define  reg_JPEG_7_HH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x1C))
#define  reg_JPEG_7_H       (*(volatile UINT8 xdata*)(JPEG_BASE+0x1D))
#define  reg_JPEG_7_L       (*(volatile UINT8 xdata*)(JPEG_BASE+0x1E))
#define  reg_JPEG_7_LL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x1F))


#define  reg_JPEG_ENRST       (*(volatile UINT8 xdata*)(JPEG_BASE+0x20))
#define  reg_JPEG_XSIZEL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x21))
#define  reg_JPEG_XSIZEH       (*(volatile UINT8 xdata*)(JPEG_BASE+0x22))
#define  reg_JPEG_YSIZEL      (*(volatile UINT8 xdata*)(JPEG_BASE+0x23))
#define  reg_JPEG_YSIZEH      (*(volatile UINT8 xdata*)(JPEG_BASE+0x24))
#define  reg_JPEG_QTABLEADDR      (*(volatile UINT8 xdata*)(JPEG_BASE+0x26))
#define  reg_JPEG_QTABLEDATA      (*(volatile UINT8 xdata*)(JPEG_BASE+0x27))





#define reg_UsbPhy_Test_Reg0						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x70))  //8hF8	   
#define reg_UsbPhy_Test_Reg1						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x71))  //8hA4	   
#define reg_UsbPhy_Test_Reg2						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x72))  //8h91	   
#define reg_UsbPhy_Test_Reg3						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x73))  //8h85
#define reg_UsbPhy_Test_Reg4						 (*(volatile UINT8 xdata*)(GLOBAL_BASE+0x74))  //8h34


#define VPROC_TOP_BASE					0xF800
#define reg_tvdadc_clock						    (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x00))  //8hF8	   
#define reg_dram_clock					        	(*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x01))  //8hA4	   
#define reg_vds_clock						        (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x02))  //8h91	   
#define reg_vpmodule_clocken						(*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x03))  //8h85
#define reg_vpmodule_rst						    (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x04))  //8h34
#define reg_vpdfi_pinmux						    (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x05))  //8h34

#define reg_vpfrm1_f806						    (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x06))  //8h34
#define reg_vpfrm2_f807						    (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x07))  //8h34

#define reg_tbus					                (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x08))  //8h34
#define reg_vp_ctrl1					            (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x09))  //8h34
#define reg_vp_ctrl2					            (*(volatile UINT8 xdata*)(VPROC_TOP_BASE+0x0a))  //8h34
 

#define reg_fpga_memory_data_driver             (*(volatile UINT8 xdata*)0xf9be)			 // 
#define reg_fpga_memory_clk_driver              (*(volatile UINT8 xdata*)0xf9bf)			 // 


//De-interlace
#define reg_f81a             (*(volatile UINT8 xdata*)0xf81a)
#define reg_f827             (*(volatile UINT8 xdata*)0xf827)
#define reg_f82e             (*(volatile UINT8 xdata*)0xf82e)
#define reg_f82f             (*(volatile UINT8 xdata*)0xf82f) 
#define reg_f830             (*(volatile UINT8 xdata*)0xf830) 
#define reg_f831             (*(volatile UINT8 xdata*)0xf831) 
#define reg_f833             (*(volatile UINT8 xdata*)0xf833)
#define reg_f83a             (*(volatile UINT8 xdata*)0xf83a)
#define reg_f83b             (*(volatile UINT8 xdata*)0xf83b)

#define reg_adc_fb1a             (*(volatile UINT8 xdata*)0xfb1a)			 // 

#define ADC_BASE_ADDR     0xF800+0X310
#define reg_ADC_Byte0                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x0))			 // 
#define reg_ADC_Byte1						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x1))			 // 
#define reg_ADC_Byte2						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x2))			 // 
#define reg_ADC_Byte3						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x3))			 //                                                                                                                                                                                                    
#define reg_ADC_Byte4                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x4))			 //
#define reg_ADC_Byte5						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x5))			 //
#define reg_ADC_Byte6						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x6))			 //
#define reg_ADC_Byte7						 (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x7))			 //																			      
#define reg_ADC_Byte8                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x8))			 //
#define reg_ADC_Byte9                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0x9))			 //
#define reg_ADC_Bytea                        (*(volatile UINT8 xdata*)(ADC_BASE_ADDR+0xa))			 //

#define MS1850_VFE_TVD_BASE                    (0xf200)

#define reg_TVD_SFR_ADDR						 	 (*(volatile UINT8 xdata*)(MS1850_VFE_TVD_BASE+0x00))  // 	   需要读写TVD寄存器的地址，从00到FF有效，共256个寄存器
#define reg_TVD_SFR_WR_Enable						 (*(volatile UINT8 xdata*)(MS1850_VFE_TVD_BASE+0x01))  //		BIT0   1 ：硬件写TVD寄存器信号有效   0 ：硬件写TVD寄存器信号无效
#define reg_TVD_SFR_RD_Enable						 (*(volatile UINT8 xdata*)(MS1850_VFE_TVD_BASE+0x02))  //		BIT0   1 ：硬件读TVD寄存器信号有效	 0 ：硬件读TVD寄存器信号无效
#define reg_TVD_SFR_WDATA							 (*(volatile UINT8 xdata*)(MS1850_VFE_TVD_BASE+0x03))  //	   需要写到TVD寄存器的值
#define reg_TVD_SFR_RDATA							 (*(volatile UINT8 xdata*)(MS1850_VFE_TVD_BASE+0x04))  //	   从TVD寄存器读回来的值


#endif
