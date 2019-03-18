#include "common.h" 
#include "descript.h" 

//UINT8 code LANGIDString[] = 
//{
//    0x04,0x03,0x09,0x04
//};

UINT8 code dev_desc[18] =	  
{
    0x12,
    0x01,
    0x00,0x02,     //USB2.0
    0x03,       //Class
    0x00,       //SubClass
    0x00,       //Protocol
    0x40,       //MaxPacket
//    0x4d,0x53,     //VID
//    0x21,0x00,     //PID
    0x15,0x15,     //VID
    0x15,0x15,     //PID    
    0x21,0x01,     //bcdDevice     //  版本号2101
    0x00,       //Manufacturer
    0x00,       //Product
    0x00,       //serial
    0x01        //numconfigration
};

UINT8 code  ReportDescriptor[]=
{
    0x06, 0x00, 0xFF,   // usage page(﹚竡)
    0x09, 0x01,                        // usage(0) undefined
    0xA1, 0x01,                        // Collection(Application)
    //0x85, 0x01,                         // REPORT_ID (1)
    0x15, 0x00,                        // Logical Minimum (0)
    0x26, 0xFF, 0x00,                // Logical Maximum (255)
    0x19, 0x01,                        // Usage Minimum(0x01)
    0x29, 0x02,                       // Usage Maximum(0x05)
    0x75, 0x08,                        // REPORT SIZE (8)
    0x95, 0x08,                       // REPORT COUNT(8)
    0xB1, 0x02,                      // FEATURE(DATA,VARIABLE,ABSOLUTE)
    0xC0                                // END COLLECTION
};



//Descriptors for high-speed
UINT8 code  ConfigDescript[] = 
{
//配置描述符号
    0x09,   //长度
    0x02,   //bDescriptorType 02表示配置
    27,0x00,  // total length   9+9+9 = 27
    0x01,   //该配置支持的接口总数 4 个 
    0x01,   //配置的值，一般都只有一种配置，此值为1 
    0x00,   //描述该配置的字符串索引0 ，表示没有 
    0x80,   //bit7 必须1， bit6 供电方式 1表示自供电，bit5指示是否支持远程唤醒，bit0-4保留
    0xFA,   //表示从总线获取的最大电流量 每个单位2mA 0XFA = 250 500mA


//HID 接口描述符    
    /*******************接口描述符*********************/    
    0x09,    //bLength字段。接口描述符的长度为9字节。   
    0x04,    //bDescriptorType字段。接口描述符的编号为0x04。  
    0x00,    //bInterfaceNumber字段。该接口的编号，第一个接口，编号为0。   第5个接口，UVC&UAC已经占用4个接口     
    0x00,     //bAlternateSetting字段。该接口的备用编号，为0。    
//    0x01,   //bNumEndpoints字段。非0端点的数目。//1个 ，为兼容HID CV 测试必须大于1 ，不需要中断端点，只使用控制传输。    
    0x00,   //bNumEndpoints字段。非0端点的数目。//1个 
    0x03,   //bInterfaceClass字段。该接口所使用的类。本实例是HID类， //HID类的编码为0x03。  
    0x00,  //bInterfaceSubClass字段。该接口所使用的子类。在HID1.1协议中，  
    0x00,    //自定义的HID设备，也不使用协议。   
    0x00,   //iConfiguration字段。该接口的字符串索引值。这里没有，为0。 

    /******************HID描述符************************/
    //bLength字段。本HID描述符下只有一个下级描述符。所以长度为9字节。
    0x09,  
    //bDescriptorType字段。HID描述符的编号为0x21。
    0x21,   
    //bcdHID字段。本协议使用的HID1.1协议。注意低字节在先。
    0x10,
    0x01,    
    //bCountyCode字段。设备适用的国家代码，这里选择为美国，代码0x21。
    0x21,    
    //bNumDescriptors字段。下级描述符的数目。我们只有一个报告描述符。
    0x01,  
    //bDescriptorType字段。下级描述符的类型，为报告描述符，编号为0x22。
    0x22,  
    //bDescriptorLength字段。下级描述符的长度。下级描述符为报告描述符。
    sizeof(ReportDescriptor)&0xFF,
    (sizeof(ReportDescriptor)>>8)&0xFF, 
//    ///*******************端点描述符*********************/
//    0x07,           /*bLength: Endpoint Descriptor size*/
//    0x05,           /*bDescriptorType: endpoint*/  
//    0x81,           /*bEndpointAddress: Endpoint Address (IN)*/
//    0x03,           /*bmAttributes: Interrupt endpoint*/
//    0x04,           /*wMaxPacketSize: 4 Byte max */
//    0x00,
//    0x10,           /*bInterval: Polling Interval (2^16-1)*/	       		
};