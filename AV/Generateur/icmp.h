#include <pcap.h>

void remplir_ICMP(u_char *p)
{
    remplir_ether(p);
    p[12]=0x00;p[13]=0x01;
    p[14]=0x00;
    p[15]=0x04;
    int i;
    for(  i = 16; i < 180; i++ )
        {
            p[i] = 0x00;
        }

}



typedef struct icmp {
   u_char typeP;
   u_char code ;
   u_char checksum[2] ;
   u_char identifiant[2];
   u_char numero_seq [2];
   }ICMP ;

   void set_typeP(ICMP *e ,u_char d)
   {
       e->typeP=d;
   }
     void set_code( ICMP *e ,u_char d )
   {
       e->code=d;
   }

     void set_checksummmm (ICMP *e , u_char a[2] )
   {
       e->checksum[0] = a[0] ;
       e->checksum[1] = a[1] ;
   }
     void set_identifiant (ICMP *e , u_char a[2] )
   {
       e->identifiant[0] = a[0] ;
       e->identifiant[1] = a[1] ;
   }
    void set_numero_seq(ICMP *e ,u_char d[2])
   {
       e->numero_seq[0]=d[0];
       e->numero_seq[1]=d[1];
   }

