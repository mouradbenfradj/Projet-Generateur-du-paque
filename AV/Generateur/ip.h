#include <pcap.h>
#include"udp.h"
#include"tcp.h"

void remplir_ip(u_char *p)
{
    remplir_ether(p);
    p[12]=0x08;p[13]=0x00;
    p[14]=0x00;
    p[15]=0x04;
    int i;
    for(  i = 16; i < 180; i++ )
        {
            p[i] = 0x00;
        }

}

void menu_ip(u_char *p)
{
       int choix=0;
    while((choix<1)||(choix>3))
    {
        printf("choisir la type du tram ip a envoyer \n");
        printf("1- Simple tram ip \n");
        printf("2- tram UDP\n");
        printf("3- tram TCP \n");
        scanf("%d",&choix);
    }
}

void tramip(int choix,u_char *p)
{
    switch(choix)
    {
    case 1:remplir_ip(p);break;
    case 2:printf("udp");/* remplir_udp(p) */;break;
    case 3:printf("tcp");/* remplir_tcp(p)*/;break;
    }
}

typedef struct ip {
   u_char vertion;
   u_char service ;
   u_char longueur[2] ;
   u_char identification[2];
   u_char flag [2];
   u_char ttl ;
   u_char protocol ;
   u_char checksum [2];
   u_char ipsource [4];
   u_char ipdestination [4];
   }IP ;

   void set_vertion(IP *e ,u_char d)
   {
       e->vertion=d;
   }
     void set_service( IP *e ,u_char d )
   {
       e->service=d;
   }

 void set_longueur(IP *e , u_char a[2] )
   {
       e->longueur[0] = a[0] ;
       e->longueur[1] = a[1] ;
   }
 void set_identification(IP *e , u_char a[2] )
   {
       e->identification[0] = a[0] ;
       e->identification[1] = a[1] ;
   }
 void set_flag(IP *e , u_char a[2] )
   {
       e->flag[0] = a[0] ;
       e->flag[1] = a[1] ;
   }

 void set_ttl( IP *e ,u_char d )
   {
       e->ttl=d;
   } void set_protocol( IP *e ,u_char d )
   {
       e->protocol=d;
   }
     void set_checksummm (IP *e , u_char a[2] )
   {
       e->checksum[0] = a[0] ;
       e->checksum[1] = a[1] ;
   }
     void set_ipsource (IP *e , u_char a[4] )
   {
       e->ipsource[0] = a[0] ;
       e->ipsource[1] = a[1] ;
        e->ipsource[2] = a[2] ;
        e->ipsource[3] = a[3] ;
   }
    void set_ipdestination(IP *e ,u_char d[4])
   {
       e->ipdestination[0]=d[0];
       e->ipdestination[1]=d[1];
       e->ipdestination[2]=d[2];
       e->ipdestination[3]=d[3];
   }

