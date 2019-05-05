/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** parsing.c
*/

#include <stdlib.h>
#include "parsing.h"

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    arguments *args = state->input;

    switch (key)
    {
        case 't':
            args->target = arg;
            break;
        case 'p':
            args->port = atoi(arg);
            break;
        case 'P':
            args->password = arg;
            break;
        case ARGP_KEY_ARG:
            argp_usage(state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return (0);
}

arguments parsing(int ac, char **av)
{
    arguments args = { NULL, 0, NULL };
    static struct argp argp = { options, parse_opt, NULL, NULL, NULL, NULL, NULL };

    int test = argp_parse(&argp, ac, av, 0, 0, &args);
    if (ac != 7) {
        fprintf(stderr, "Error: Wrong number of arg.\n");
        exit(84);
    } else if (args.port <= 0) {
        fprintf(stderr, "Error: Wrong port.\n");
        exit(84);
    }
    return (args);
}