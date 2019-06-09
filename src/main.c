/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
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

char *sha256(char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };
    struct SHA256state_st sha256;
    char *buff = calloc(((SHA256_DIGEST_LENGTH * 2) + 1), sizeof(char));

    if (!buff)
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(buff + (i * 2), "%02x", hash[i]);
    buff[64] = 0;
    return (buff);
}

char *to_sha(char *msg, char *password)
{
    char *sha = malloc(sizeof(char) * (strlen(msg) + strlen(password) + 1));

    if (!sha)
        return (NULL);
    strcpy(sha, msg);
    strcat(sha, password);
    sha = sha256(sha);
    return (sha);
}

int main(int ac, char **av)
{
    arguments args = parsing(ac, av);
    int sock = 0;
    char *msg = NULL;

    if ((sock = create_socket(args.target)) == -1)
        return (84);
    msg = write_server(sock, &args, "client hello");
    printf("msg av sha = %s\n", msg);
    msg = to_sha(msg, args.password);
    msg = write_server(sock, &args, msg);
    printf("msg ap sha = %s\n", msg);
    return (0);
}