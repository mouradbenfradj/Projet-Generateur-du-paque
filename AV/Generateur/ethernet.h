#include <pcap.h>




void remplir_ether(u_char *p)
{
    printf("donnez les champs MAC destination un par un \n");
        printf("1-"); scanf("%d",p);printf("2-"); scanf("%d",p+1);printf("3-"); scanf("%d",p+2);printf("4-"); scanf("%d",p+3);printf("5-"); scanf("%d",p+4);printf("6-"); scanf("%d",p+5);

        printf("donnez les champs MAC source un par un \n");
        printf("1-"); scanf("%d",p+6);printf("2-"); scanf("%d",p+7);printf("3-"); scanf("%d",p+8);printf("4-"); scanf("%d",p+9);printf("5-"); scanf("%d",p+10);printf("6-"); scanf("%d",p+11);

        int i;
    // set the rest of the packet
        for(  i = 12; i < 180; i++ )
        {
            p[i] = 0xC4;
        }
}



typedef struct ether {
   u_char add_dest [6]  ;
   u_char add_sour  [6];
   u_char type ;
   u_char crc [4]  ;
   }ether ;




   void set_add_dest (ether *e ,u_char d[6])
   {
       e->add_dest[0]=d[0];
       e->add_dest[1]=d[1];
       e->add_dest[2]=d[2];
       e->add_dest[3]=d[3];
       e->add_dest[4]=d[4];
       e->add_dest[5]=d[5];


   }
     void set_add_sour ( ether *e ,u_char d[6] )
   {
       e->add_sour[0]=d[0];
       e->add_sour[1]=d[1];
       e->add_sour[2]=d[2];
       e->add_sour[3]=d[3];
       e->add_sour[4]=d[4];
       e->add_sour[5]=d[5];


   }
     void type_e (ether *e , u_char a )
   {
       e->type = a ;

   }
    void crc (ether *e ,u_char d[6])
   {
       e->crc[0]=d[0];
       e->crc[1]=d[1];
       e->crc[2]=d[2];
       e->crc[3]=d[3];


   }
