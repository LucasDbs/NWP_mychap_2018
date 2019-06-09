/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

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

int main(int ac, char **av)
{
    arguments args = parsing(ac, av);
    int sock = 0;
    char *msg = NULL;

    if ((sock = create_socket(args.target)) == -1)
        return (84);
    msg = write_server(sock, &args, "client hello");
    return (0);
}