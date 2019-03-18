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
    0x21,0x01,     //bcdDevice     //  �汾��2101
    0x00,       //Manufacturer
    0x00,       //Product
    0x00,       //serial
    0x01        //numconfigration
};

UINT8 code  ReportDescriptor[]=
{
    0x06, 0x00, 0xFF,   // usage page(�۩w�q)
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
//������������
    0x09,   //����
    0x02,   //bDescriptorType 02��ʾ����
    27,0x00,  // total length   9+9+9 = 27
    0x01,   //������֧�ֵĽӿ����� 4 �� 
    0x01,   //���õ�ֵ��һ�㶼ֻ��һ�����ã���ֵΪ1 
    0x00,   //���������õ��ַ�������0 ����ʾû�� 
    0x80,   //bit7 ����1�� bit6 ���緽ʽ 1��ʾ�Թ��磬bit5ָʾ�Ƿ�֧��Զ�̻��ѣ�bit0-4����
    0xFA,   //��ʾ�����߻�ȡ���������� ÿ����λ2mA 0XFA = 250 500mA


//HID �ӿ�������    
    /*******************�ӿ�������*********************/    
    0x09,    //bLength�ֶΡ��ӿ��������ĳ���Ϊ9�ֽڡ�   
    0x04,    //bDescriptorType�ֶΡ��ӿ��������ı��Ϊ0x04��  
    0x00,    //bInterfaceNumber�ֶΡ��ýӿڵı�ţ���һ���ӿڣ����Ϊ0��   ��5���ӿڣ�UVC&UAC�Ѿ�ռ��4���ӿ�     
    0x00,     //bAlternateSetting�ֶΡ��ýӿڵı��ñ�ţ�Ϊ0��    
//    0x01,   //bNumEndpoints�ֶΡ���0�˵����Ŀ��//1�� ��Ϊ����HID CV ���Ա������1 ������Ҫ�ж϶˵㣬ֻʹ�ÿ��ƴ��䡣    
    0x00,   //bNumEndpoints�ֶΡ���0�˵����Ŀ��//1�� 
    0x03,   //bInterfaceClass�ֶΡ��ýӿ���ʹ�õ��ࡣ��ʵ����HID�࣬ //HID��ı���Ϊ0x03��  
    0x00,  //bInterfaceSubClass�ֶΡ��ýӿ���ʹ�õ����ࡣ��HID1.1Э���У�  
    0x00,    //�Զ����HID�豸��Ҳ��ʹ��Э�顣   
    0x00,   //iConfiguration�ֶΡ��ýӿڵ��ַ�������ֵ������û�У�Ϊ0�� 

    /******************HID������************************/
    //bLength�ֶΡ���HID��������ֻ��һ���¼������������Գ���Ϊ9�ֽڡ�
    0x09,  
    //bDescriptorType�ֶΡ�HID�������ı��Ϊ0x21��
    0x21,   
    //bcdHID�ֶΡ���Э��ʹ�õ�HID1.1Э�顣ע����ֽ����ȡ�
    0x10,
    0x01,    
    //bCountyCode�ֶΡ��豸���õĹ��Ҵ��룬����ѡ��Ϊ����������0x21��
    0x21,    
    //bNumDescriptors�ֶΡ��¼�����������Ŀ������ֻ��һ��������������
    0x01,  
    //bDescriptorType�ֶΡ��¼������������ͣ�Ϊ���������������Ϊ0x22��
    0x22,  
    //bDescriptorLength�ֶΡ��¼��������ĳ��ȡ��¼�������Ϊ������������
    sizeof(ReportDescriptor)&0xFF,
    (sizeof(ReportDescriptor)>>8)&0xFF, 
//    ///*******************�˵�������*********************/
//    0x07,           /*bLength: Endpoint Descriptor size*/
//    0x05,           /*bDescriptorType: endpoint*/  
//    0x81,           /*bEndpointAddress: Endpoint Address (IN)*/
//    0x03,           /*bmAttributes: Interrupt endpoint*/
//    0x04,           /*wMaxPacketSize: 4 Byte max */
//    0x00,
//    0x10,           /*bInterval: Polling Interval (2^16-1)*/	       		
};