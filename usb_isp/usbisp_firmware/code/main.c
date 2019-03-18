#include "common.h" 
#include "hardware.h"
#include "main.h"  
#include "descript.h"

//?PR?init_fromee?MAIN(0xC400),?PR?addtask_from_eeprom?MAIN(0xC420),?PR?addusbtask_from_eeprom?MAIN(0xC4A0)
//?PR?MAIN?MAIN(0xC400)
//?PR?isp_patch?MAIN(0x7C00)

UINT8 NewAddress;
UINT8 data Usb_request[8];
UINT8 IDLE_TIME;

//void Delay_us(unsigned int i)
//{
//    unsigned int xdata j;
//    for(j=0;j<i;j++);
//}
void isp_patch();
void jmp_usercode();

void CMDRead()
{
    BYTE i;
    for(i=0;i<8;i++)
    {
      Usb_request[i] =  reg_usb_End0;
    }
}

void int_endpoint0_service(void)
{   
    if(reg_usb_CSR0 & 0x04)     //SentStall
    {
        reg_usb_CSR0 &= 0xFB;   //(~0x04);  
    }
    if(reg_usb_CSR0 & 0x10)     //SetupEnd
    {
        reg_usb_CSR0 |= 0x80;
    }
    if(NewAddress != 0xff)
    {
        reg_usb_Faddr = NewAddress;//  SET_ADDRESS : NewAddress = (BYTE)(wValue)
        NewAddress = 0xff;
    }
    if(reg_EP0_OutPktRdy == 1)
    {
        CMDRead();//寄存器值拷贝，跳转到 main 函数的while(Ep0IntFlag)
        Cmd_Process();
    }
}

void jmp_usercode()
{
    UINT8 code *ptcode; 
    ptcode = 0x7C00-3;   // 7BFD = 7C00-3
    if(*ptcode==0x02)
    {
        reg_usb_Power = 0;
        SP = 7;  //恢复栈指针为默认值
        #pragma asm 
            LJMP  7BFDH ;
        #pragma endasm 
    }
    else
    {
        isp_patch();
    }
}


void isp_patch()
{    
    EA = 0;    
    reg_mcu_access_usb_mode = 1;  
    reg_usb_Index   = 0x00; 
    // isoupdate  softcon  hsenab hsmode  rst resume suspendmode  enablesuspendM
    NewAddress = 0xFF;
    //IDLE_TIME = 0;    
    NoData = 0;
    Error = 0;
    ispendflag = 0;
    reg_usb_Power = 0x70;  
    while(1)
    {
        intr_usb = reg_usb_IntrUSB;
        intr_in = reg_usb_IntrIn;
        //intr_out = reg_usb_IntrOut;
        if(intr_usb & 0x04)                 //reset    bit2
        {
            while(reg_usb_BusRest);         //USB RESET 
            reg_EP0_SevOutPktRdy = 1;       //Set 1 use to clear  OutPktRdy //3.flush all ep fifo
        }       
        if (intr_in & 0x01)                 //ep0   bit0
        {
            int_endpoint0_service();        //
        }
        if(ispendflag)
        {
            ispendflag = 0;
            jmp_usercode();
            //reg_usb_Power = 0;  
            //return;  
        }
        //Delay_us(100);
    }
}

void main()
{
    UINT8 code *ptcode; 
    ptcode = 0x7C00-3;                      // 7BFD = 7C00-3
    if(*ptcode!=0x02)
    {
       isp_patch();
    }
    reg_mcu_access_usb_mode = 1;  
    reg_usb_Index   = 0x00; 
    reg_usb_Power = 0x70;
    while(1)
    {
        intr_usb = reg_usb_IntrUSB; 
        if(intr_usb & 0x04)                 //reset bit2
        {
            while(reg_usb_BusRest);         //USB RESET 
            reg_EP0_SevOutPktRdy = 1;
            if(reg_usb_Power & SET_BIT4)    //high speed mode
            {
                jmp_usercode();
                //return;
            }
            else                            //low speed mode
            {
                isp_patch();
                //return
            }
        }  
    }
}

      


  
