#pragma pack(1)
struct TCPHEADER
{
    short SrcPort;      //16位源端口
    short DstPort;      //16位目的端口
    int SerialNo;       //32位序列号    
    int AckNo;          //32位确认号
    unsigned char HaderLen : 4;         //4位首部长度         
    unsigned char Reserved1 : 4;        //保留6位中的4位
    unsigned char Reserved2 : 2;        //保留6位中的2位
    unsigned char URG : 1;
    unsigned char AKG : 1;
    unsigned char PSH : 1;
    unsigned char PST : 1;
    unsigned char SYN : 1;
    unsigned char FIN : 1;
    short WindowSize;               //16位窗口大小
    short TcpChkSum;                //16位TCP校验和
    short UrgentPointer;            //16位紧急指针
};

#pragma pack()