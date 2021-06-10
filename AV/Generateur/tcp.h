#include <pcap.h>

typedef struct tcp {
   u_char port_source [2]  ;
   u_char port_destination [2];
   u_char sequance[4] ;
   u_char ack[4];
   u_char offcet [2];
   u_char fenetre [2];
   u_char checksum [2];
   u_char pointeur [2];
   }TCP ;

    u_char remplir_packet(TCP *e,u_char pac[100])
    {
        pac[0]=e->port_source[0];
        pac[1]=e->port_source[1];
        pac[2]=e->port_destination[0];
        pac[3]=e->port_destination[1];
        pac[4]=e->sequance[0];
        pac[5]=e->sequance[1];
        pac[6]=e->sequance[2];
        pac[7]=e->sequance[3];
        pac[8]=e->ack[0];
        pac[9]=e->ack[1];
        pac[10]=e->ack[2];
        pac[11]=e->ack[3];
        pac[12]=e->offcet[0];
        pac[13]=e->offcet[1];
        pac[14]=e->fenetre[0];
        pac[15]=e->fenetre[1];
        pac[16]=e->checksum[0];
        pac[17]=e->checksum[1];
        pac[18]=e->pointeur[0];
        pac[19]=e->pointeur[1];
        return pac;
    }
     u_char remplir_packet2(TCP *e)
    {
        u_char pac[100];
        pac[0]='a';
        pac[1]='a';
        pac[2]='a';
        pac[3]='a';
        pac[4]='a';
        pac[5]='a';
        pac[6]='a';
        pac[7]='a';
        pac[8]='a';
        pac[9]='a';
        pac[10]='a';
        pac[11]='a';
        pac[12]='a';
        pac[13]='a';
        pac[14]='a';
        pac[15]='a';
        pac[16]='a';
        pac[17]='a';
        pac[18]='a';
        pac[19]='a';
        return pac;
    }

   void set_port_source(TCP *e ,u_char d[2])
   {
       e->port_source[0]=d[0];
       e->port_source[1]=d[1];
   }
     void set_port_destination ( TCP *e ,u_char d[2] )
   {
       e->port_destination[0]=d[0];
       e->port_destination[1]=d[1];
   }

     void set_sequance (TCP *e , u_char a[4] )
   {
       e->sequance[0] = a[0] ;
       e->sequance[1] = a[1] ;
       e->sequance[2] = a[2] ;
       e->sequance[3] = a[3] ;
   }
     void set_ack (TCP *e , u_char a[4] )
   {
       e->ack[0] = a[0] ;
       e->ack[1] = a[1] ;
       e->ack[2] = a[2] ;
       e->ack[3] = a[3] ;
   }



    void set_offcet (TCP *e ,u_char d[2])
   {
       e->offcet[0]=d[0];
       e->offcet[1]=d[1];
   }

    void set_fenetre (TCP *e ,u_char d[2])
   {
       e->fenetre[0]=d[0];
       e->fenetre[1]=d[1];
   }
 void set_checksum (TCP *e ,u_char d[2])
   {
       e->checksum [0]=d[0];
       e->checksum [1]=d[1];
   }
   void set_pointeur(TCP *e ,u_char d[2])
   {
       e->pointeur [0]=d[0];
       e->pointeur [1]=d[1];
   }

