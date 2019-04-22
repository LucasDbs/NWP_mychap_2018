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
                        args->port = arg;
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
        arguments args = { NULL, NULL, NULL };
        static struct argp argp = { options, parse_opt, NULL, NULL, NULL, NULL, NULL };

        if (ac != 7) {
                fprintf(stderr, "Wrong number of arg.\n");
                exit(84);
        }
        argp_parse(&argp, ac, av, 0, 0, &args);
        return (args);
}