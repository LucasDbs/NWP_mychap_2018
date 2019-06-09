/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** mychap.h
*/

#if !defined(MYCHAP_H_)
#define MYCHAP_H_

#include <string.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <openssl/sha.h>

typedef struct arguments_s
{
        char *target;
        int port;
        char *password;
} arguments;

arguments parsing(int ac, char **av);
int create_socket(char *target);
char *write_server(int sock, arguments *, char *msg);
struct sockaddr_in init_server_add(int port);
void udp_header(int port, struct udphdr *udp_hdr, int size);
void ip_header(char *server, char *msg, struct iphdr *ip_hdr);
unsigned short csum(unsigned short *buf, int nwords);

char *sha256(char *str);

#endif // MYCHAP_H_
