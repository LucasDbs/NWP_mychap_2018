/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** headers.c
*/

#include <arpa/inet.h>
#include "mychap.h"

unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for(sum=0; nwords>0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void ip_header(char *server, char *msg, struct iphdr *ip_hdr)
{
    ip_hdr->ihl = 5;
    ip_hdr->version = 4;
    ip_hdr->tos = 0;
    ip_hdr->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr)
    + strlen(msg);
    ip_hdr->id = 0;
    ip_hdr->frag_off = 0x00;
    ip_hdr->ttl = 0xFF;
    ip_hdr->protocol = IPPROTO_UDP;
    ip_hdr->check = 0;
    ip_hdr->saddr = inet_addr("127.0.0.1");
    ip_hdr->daddr = inet_addr(server);
}

void udp_header(int port, struct udphdr *udp_hdr, int size)
{
    udp_hdr->check = 0;
    udp_hdr->source = htons(6554);
    udp_hdr->dest = htons(port);
    udp_hdr->len = htons(sizeof(struct udphdr) + size);
}

struct sockaddr_in init_server_add(int port)
{
    struct sockaddr_in server_add;

    server_add.sin_addr.s_addr = htonl(INADDR_ANY);
    server_add.sin_port = htons(port);
    server_add.sin_family = AF_INET;
    return (server_add);
}