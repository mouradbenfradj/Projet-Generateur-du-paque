#include <pcap.h>
int reqrep()
{
    int c;
    printf("1:request \n"); printf("2:rely \n");
    scanf("%x",&c);
    return 0xc;

}

void remplir_arp(u_char *p)
{
    remplir_ether(p);
    p[12]=0x08;p[13]=0x06;
    p[14]=0x00;
    p[15]=0x01;
    p[16]=0x08;
    p[17]=0x00;
    p[18]=0x06;
    p[19]=0x04;
    p[20]=0x00;
    p[21]=reqrep();
    int i;
    for(  i = 22; i < 180; i++ )
        {
            p[i] = 0x00;
        }

}
typedef struct arp {
   u_char network [2]  ;
   u_char protocol [2];
   u_char hard_adresse_length ;
   u_char log_adresse_length ;
   u_char operation [2];
   u_char sender_hardware [6];
   }ARP ;

   void set_network(ARP *e ,u_char d[2])
   {
       e->network[0]=d[0];
       e->network[1]=d[1];
   }
     void set_protocoll( ARP *e ,u_char d[2] )
   {
       e->protocol[0]=d[0];
       e->protocol[1]=d[1];
   }

     void set_hard_adresse_length (ARP *e , u_char a )
   {
       e->hard_adresse_length = a ;
   }
     void set_log_adresse_length (ARP *e , u_char a )
   {
       e->log_adresse_length = a ;
   }


    void set_operation (ARP *e ,u_char d[2])
   {
       e->operation[0]=d[0];
       e->operation[1]=d[1];
   }
 void set_sender_hardware (ARP *e ,u_char d[6])
   {
       e->sender_hardware[0]=d[0];
       e->sender_hardware[1]=d[1];
        e->sender_hardware[0]=d[0];
       e->sender_hardware[1]=d[1];
       e->sender_hardware[0]=d[0];
       e->sender_hardware[1]=d[1];
   }

