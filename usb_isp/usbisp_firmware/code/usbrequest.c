#include "common.h" 
#include "hardware.h"
#include "usbrequest.h"  
#include "descript.h"

bit NoData ;
bit Error  ;
bit ispendflag ;
UINT8 data  tempdata[8];
UINT8 data  hidbuff[8];

extern UINT8 data Usb_request[8];


void setupDataIn(UINT8 nBytes, UINT8 *p)
{
    UINT8 i;
    if(nBytes>63)
    {
        nBytes  = 63;
    }
    for(i=0;i<nBytes;i++)
    {
      reg_usb_End0 = *(p+i);
    }
}

void setupDataOut(UINT8 nBytes, UINT8 *p)
{
	UINT8  i = 0;
    for(i=0;i<nBytes;i++)
    {
      *(p+i) =reg_usb_End0;
    }
}



void get_status()
{
    tempdata[0] = 0x00;
    tempdata[1] = 0x00;
    setupDataIn(2, tempdata);
}
  
void set_address(void)
{
    if(Usb_request[2] < 0x80)
    {
        NewAddress =Usb_request[2] ;
    }
    NoData = 1;
}




/************************GET_DESCRIPTOR************************************/
void get_descriptor(void)
{
        if(Usb_request[0] == M_CMD_STDDEVIN)
        {
            switch(Usb_request[3])     
            {
                case 0x01:// Descriptor Types--DEVICE
                    setupDataIn(Usb_request[6], dev_desc);                
                    break;                          
                case 0x02:// Descriptor Types--CONFIGURATION      配置
                    if(Usb_request[6]>27)
                    {
                       Usb_request[6]  = 27;
                    }
                    setupDataIn(Usb_request[6], ConfigDescript);                   
                    break;
//                case 0x03:// Descriptor Types--STRING           字符串
//                    setupDataIn(Usb_request[6], LANGIDString); 
//                    break;
                default:
                    Error = 1;
                    break;
            }           
        }
        else if(Usb_request[0] == M_CMD_STDIFIN)   //接口
        {
            switch(Usb_request[3]) 
            {
            case 0x21:  //HID  DESCRIPTION
                 setupDataIn(9, &ConfigDescript[9]);      // 第9 Bytes 开始 为HID 描述符
                break;
            case 0x22: // hid report DESCRIPTION request
                setupDataIn(23, ReportDescriptor);
                break;
             }
        }
        else
        {
            Error = 1;
        }
}

void get_configuration(void)
{
    tempdata[0] = 0x01;
    setupDataIn(1, tempdata);
}

void set_configuration(void)
{
    NoData = 1;
}

//void get_interface(void)
//{
//    tempdata[0] = 0x00;     // 有效接口 全部应答0
//    setupDataIn(1, tempdata);
//}
//
//void set_interface(void)
//{
//    NoData = 1;
//}

void set_idle()
{
    IDLE_TIME =  Usb_request[3];  
    NoData = 1;  
}

void get_idle()
{
    setupDataIn(1, &IDLE_TIME);  
}

void get_report(void)
{
    setupDataIn(8,hidbuff);   
}

void set_reg_rw_cmd()
{                                             
    UINT8 xdata *xdataptr ;
    UINT8 i,j;
    if((hidbuff[0]&0xf0) == 0x10)   //xdata 连续写指令
    {
        j= hidbuff[0]&0x0f;   // 低4 bit 表示长度                 
        xdataptr =  ((UINT16)hidbuff[1]<<8)|hidbuff[2];
        for(i=0;i<j;i++)
        {
           *xdataptr = hidbuff[3+i];
           xdataptr++;
        }                
    }
    else if(hidbuff[0] == 0xed)   //写结束标志
    {                                              
         ispendflag  =1;
    }

    else
    {
        switch(hidbuff[0])
        {
            case 0xb5:    // xdata reg read             
                xdataptr =  ((UINT16)hidbuff[1]<<8)|hidbuff[2];
                hidbuff[3] =  *xdataptr ;
                hidbuff[4] =  *(xdataptr+1) ;
                hidbuff[5] =  *(xdataptr+2) ;
                hidbuff[6] =  *(xdataptr+3) ;
                hidbuff[7] =  *(xdataptr+4) ;          
                break;
            case 0xb6:  // xdata reg write                              
                 xdataptr =  ((UINT16)hidbuff[1]<<8)|hidbuff[2];
                 *xdataptr = hidbuff[3] ;               
                break;     
            default :
                break;           
        }
    }
}

void set_report(void)
{
    reg_EP0_SevOutPktRdy = 1;
	while (!reg_EP0_OutPktRdy)  ;
    setupDataOut(Usb_request[6], hidbuff); 				
    set_reg_rw_cmd();
	NoData = 1;
}


void Cmd_Process()
{
//    if((Usb_request.bmRequestType & 0x80) == bmBIT7)
    if((Usb_request[0] & 0x80) == bmBIT7)
    {
        reg_EP0_SevOutPktRdy = 1;
    }
    
    if((Usb_request[0] & 0x60) == 0x00)//standard
    {     
      switch(Usb_request[1])
      {
         case GET_STATUS:
                get_status();
                break;
//         case SET_FEATURE:
//                set_feature();
//                break;
//         case CLEAR_FEATURE:
//                clear_feature();
//                break;
         case SET_ADDRESS:
                set_address();
                break;
         case GET_DESCRIPTOR:
                get_descriptor();
                break;
         case GET_CONFIGURATION:
                get_configuration();
                break;
         case SET_CONFIGURATION:                    
                set_configuration();
                break;
//         case GET_INTERFACE:
//                get_interface();
//                break;
//         case SET_INTERFACE:
//                set_interface();
//                break;
        default:
                Error = 1;
                break;
      }
    }
    else if (Usb_request[0] & 0x20)        //类请求
    {
            switch(Usb_request[1])
            {
            case GET_REPORT:            //  0x01
                get_report() ;
                break;
            case SET_REPORT:            // 0x09
                set_report();
                break;
            case GET_IDLE:              //  0x02
                get_idle() ;
                break;
            case SET_IDLE:              // 0x0a
                set_idle();
                break;
            default:
                Error = 1;
                break;
            }       
    }

//    if((Usb_request[0] & 0x80) == bmBIT7)    // IN 
    {
        if(Error)
        {
            reg_EP0_SendStall = 1;
            Error = 0;
        }
        else if(NoData)
        {
            reg_EP0_DataEnd = 1;
            NoData = 0;
        }
        else
        {
            reg_EP0_InPktRdy = 1;
            reg_EP0_DataEnd = 1;           
        }
    }
//    else        //OUT 
//    {
//        if(Error)
//        {
//            reg_EP0_SendStall = 1;
//            Error = 0;
//        }
//        else if(NoData)
//        {
//            reg_EP0_DataEnd = 1;
//            NoData = 0;
//        }
//    }
    if((Usb_request[0] & 0x80) != 0x80)
    {
        reg_EP0_SevOutPktRdy = 1;
    }
}