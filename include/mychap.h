/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** mychap.h
*/

#if !defined(MYCHAP_H_)
#define MYCHAP_H_

typedef struct arguments_s
{
        char *target;
        int port;
        char *password;
} arguments;

arguments parsing(int ac, char **av);

#endif // MYCHAP_H_
