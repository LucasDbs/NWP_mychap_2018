/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** msg_gestion.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "mychap.h"

int send_msg(int sock, char *headers, uint16_t len,
struct sockaddr_in server_add)
{
    if (sendto(sock, headers, len, 0,
    (struct sockaddr *)&server_add, sizeof(server_add)) < 0) {
        perror("sendto failed");
        exit(84);
    }
    return (0);
}

char *send_to_serv(int sock, arguments *args, char *msg)
{
    char headers[4096] = { 0 };
    struct iphdr *ip_hdr = (struct iphdr *)headers;
    struct udphdr *udp_hdr = (struct udphdr *)(headers + sizeof(struct iphdr));
    char *ret_msg = (headers + sizeof(struct iphdr) + sizeof(struct udphdr));
    struct sockaddr_in server_add = init_server_add(args->port);

    strcpy(ret_msg, msg);
    ip_header(ip_hdr, strlen(msg), args->target);
    udp_header(udp_hdr, args->port, strlen(msg));
    ip_hdr->check = csum((unsigned short *)headers, ip_hdr->tot_len);
    send_msg(sock, headers, ip_hdr->tot_len, server_add);
    for (int i = 0; i != 2; i++) {
        memset(headers, 0, sizeof(headers));
        recvfrom(sock, headers, sizeof(headers), 0, NULL, NULL);
    }
    return (strdup(ret_msg));
}