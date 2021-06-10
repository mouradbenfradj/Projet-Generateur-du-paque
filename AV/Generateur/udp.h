typedef struct udp{
    u_char sport[2];          // Source port
    u_char dport[2];          // Destination port
    u_char len[2];            // Datagram length
    u_char crc[2];            // Checksum
}UDP;
