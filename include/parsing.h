/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** parsing.h
*/

#if !defined(PARSING_H_)
#define PARSING_H_

#include <argp.h>
#include "mychap.h"

int argp_err_exit_status = 84;

static struct argp_option options[] = {
    {"target", 't', "TARGET", 0, "Target", 0 },
    {"port", 'p', "PORT", 0, "Port", 0 },
    {"password", 'P', "PASSW", 0, "Password", 0 },
    { 0 }
};

#endif // PARSING_H_
