/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include "mychap.h"

int create_socket(char *target)
{
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

    if (sock < 0) {
        perror("sokcet(): Failed");
        return (-1);
    }
    else if (gethostbyname(target) == NULL) {
        printf("No such hostname: %s\n", target);
        return (-1);
    }
    else if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL,
    &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt(): Failed");
        return (-1);
    }
    return (sock);
}

int print_res(char *msg)
{
    if (strcmp(msg, "KO") == 0)
        printf("%s\n", msg);
    else
        printf("Secret: '%s'\n", msg);
    return (0);
}

int main(int ac, char **av)
{
    arguments args = parsing(ac, av);
    int sock = create_socket(args.target);
    char *msg = NULL;

    if (sock == -1)
        return (84);
    msg = send_to_serv(sock, &args, "client hello");
    msg = to_sha(msg, args.password);
    msg = send_to_serv(sock, &args, msg);
    print_res(msg);
    free(msg);
    return (0);
}