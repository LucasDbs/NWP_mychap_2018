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

        printf("args.password = %s\n", args.password);
        return (0);
}