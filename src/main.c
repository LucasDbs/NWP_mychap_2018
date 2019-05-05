/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

#include <stdio.h>
#include "mychap.h"

int main(int ac, char **av)
{
    arguments args = parsing(ac, av);

    printf("args.port = %d\n", args.port);
    return (0);
}