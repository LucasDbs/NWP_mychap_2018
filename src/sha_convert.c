/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** sha_convert.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include "mychap.h"

int sha256(char *str, char *buff)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };
    struct SHA256state_st sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(buff + (i * 2), "%02x", hash[i]);
    buff[64] = 0;
    return (0);
}

char *to_sha(char *msg, char *password)
{
    char *sha = calloc(strlen(msg) + strlen(password) + 1, sizeof(char));
    char *buff = calloc(((SHA256_DIGEST_LENGTH * 2) + 1), sizeof(char));

    if (!sha || !buff)
        return (NULL);
    strcpy(sha, msg);
    strcat(sha, password);
    sha256(sha, buff);
    free(sha);
    return (buff);
}