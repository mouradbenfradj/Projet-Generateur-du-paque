#include <pcap.h>
#include"ethernet.h"
#include"ip.h"
#include"arp.h"
#include"icmp.h"
int menu()
{
    int choix=0;
    while((choix<1)||(choix>4))
    {
        printf("choisir la type de tram a envoyer \n");
        printf("1- Simple tram Ethernet \n");
        printf("2- tram IP4\n");
        printf("3- tram ARP \n");
        printf("4- tram ICMP \n");
        scanf("%d",&choix);
    }
}

void tram(int choix,u_char *p)
{
    switch(choix)
    {
    case 1:remplir_ether(p);break;
    case 2:menu_ip(p);break;
    case 3:remplir_arp(p);break;
    case 4:remplir_ICMP(p);break;
    }
}


int main(int argc, _TCHAR* argv[])
{
    pcap_if_t * allAdapters;
    pcap_if_t * adapter;
    pcap_t * adapterHandle;
    u_char packet[ 180 ];
    char errorBuffer[ PCAP_ERRBUF_SIZE ];

    // retrieve the adapters from the computer
    if( pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL,&allAdapters, errorBuffer ) == -1 )
    {
        fprintf( stderr, "Error in pcap_findalldevs_ex function: %s\n",
                 errorBuffer );
        return -1;
    }

    // if there are no adapters, print an error
    if( allAdapters == NULL )
    {
    printf( "\nNo adapters found! Make sure WinPcap is installed.\n" );
        return 0;
    }

    // print the list of adapters along with basic information about an adapter
    int crtAdapter = 0;
    for( adapter = allAdapters; adapter != NULL; adapter = adapter->next)
    {
    printf( "\n%d.%s ", ++crtAdapter, adapter->name );
    printf( "-- %s\n", adapter->description );
    printf( "-- %s\n", (adapter->flags &PCAP_IF_LOOPBACK)?"yes":"no" );
    }

    printf( "\n" );

    int adapterNumber;

    printf( "Enter the adapter number between 1 and %d:", crtAdapter );
    scanf( "%d", &adapterNumber );

    if( adapterNumber < 1 || adapterNumber > crtAdapter )
    {
        printf( "\nAdapter number out of range.\n" );

        // Free the adapter list
        pcap_freealldevs( allAdapters );

        return -1;
    }

    // parse the list until we reach the desired adapter
    adapter = allAdapters;
    for( crtAdapter = 0; crtAdapter < adapterNumber - 1; crtAdapter++ )
        adapter = adapter->next;

    // open the adapter
    adapterHandle = pcap_open( adapter->name, // name of the adapter
                               65536,         // portion of the packet to capture
                                              // 65536 guarantees that the whole
                                              // packet will be captured
                               PCAP_OPENFLAG_PROMISCUOUS, // promiscuous mode
                               1000,             // read timeout - 1 millisecond
                               NULL,          // authentication on the remote machine
                               errorBuffer    // error buffer
                              );

    if( adapterHandle == NULL )
    {
        fprintf( stderr, "\nUnable to open the adapter\n", adapter->name );

        // Free the adapter list
        pcap_freealldevs( allAdapters );

        return -1;
    }

    // free the adapter list
    pcap_freealldevs( allAdapters );


    // this is the most important part of the application
    // here we send the packet

    // first we create the packet

//ip4
    packet[12] = 0x08;
    packet[13] = 0x00;




int nbe,kk;


tram(menu(),packet);


    printf("donnez le nombre de tram a envoyer");
    scanf("%d",&nbe);
    // send the packet
    for(kk=0;kk<nbe;kk++){
    if( pcap_sendpacket( adapterHandle, // the adapter handle
             packet, // the packet
             180 // the length of the packet
               ) != 0 )
    {
        fprintf( stderr,"\nError sending the packet: \n", pcap_geterr( adapterHandle ) );
        return -1;
    }}

printf("%",packet);
    system( "PAUSE" );
    return 0;
}
