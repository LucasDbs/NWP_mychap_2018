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

typedef struct arguments_s
{
    char *target;
    int port;
    char *password;
} arguments;

arguments parsing(int, char **);
int create_socket(char *);
char *send_to_serv(int, arguments *, char *);
struct sockaddr_in init_server_add(int);
void udp_header(struct udphdr *, int, int);
void ip_header(struct iphdr *, size_t, char *);
unsigned short csum(unsigned short *, int);
char *to_sha(char *, char *);
int sha256(char *, char *);

#endif
