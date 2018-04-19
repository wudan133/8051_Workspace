#include <ms8005.h>

#define VOID void
typedef unsigned char UINT8;
typedef unsigned short UINT16;

sbit ACC0= ACC^0;
sbit ACC1= ACC^1;
sbit ACC2= ACC^2;
sbit ACC3= ACC^3;
sbit ACC4= ACC^4;
sbit ACC5= ACC^5;
sbit ACC6= ACC^6;
sbit ACC7= ACC^7;



/*******************************************************************/
sbit F_TM = PSW^5;
#define TIMER0_ENABLE  TL0 = 0x7F; TH0 = 0xF9; TR0=1;
#define TIMER0_DISABLE TR0=0; 

#define BT_SND(x)   P0_0 = x
#define BT_REC      P0_1


/*******************************************************************/
VOID PSendChar(UINT8 inch)
{
    ACC = inch;
    
    F_TM = 0;
    BT_SND (0);     //start bit
    TIMER0_ENABLE;
    while(!F_TM);
    
    BT_SND(ACC0); //先低
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC1);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC2);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC3);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC4);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC5);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC6);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(ACC7);
    F_TM=0;
    while(!F_TM);
    
    BT_SND(1);
    F_TM=0;
    while(!F_TM);
    
    TIMER0_DISABLE; //停止timer
}

UINT8 PGetChar(VOID)
{
    TIMER0_ENABLE;
    
    F_TM=0;
    while(!F_TM);//起始位
    ACC0=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC1=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC2=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC3=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC4=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC5=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC6=BT_REC;
    
    F_TM=0;
    while(!F_TM);
    ACC7=BT_REC;
    
    F_TM=0;
    
    while(!F_TM)
    {
        if(BT_REC)
        {
            break;
        }
    }
    TIMER0_DISABLE; //停止timer
    return ACC;
}

UINT8 gch;


void timerint_server_from_eeprom(void) interrupt ET0_VECTOR
{
    F_TM=1;
}

void main(void)
{
    P0OEN = 0xFE;
    
    TL0 = 0x7E;
    TH0 = 0xF9;
    
    ET0=1;
    EA=1;
    
    PSendChar(0x55);
    PSendChar(0xaa);
    PSendChar(0x00);
    PSendChar(0xff);
    
    while(1)
    {
        if(BT_REC==0)
        {
            gch=PGetChar();
            PSendChar(gch);
        }
    }
}

