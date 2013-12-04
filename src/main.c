/*
 * main.c - Main entry point and help routines
 *
 * Copyright (c) 2013 Maxthon Chan
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#include "version.h"
#include "reverse.h"

int main(int argc, const char **argv)
{
    opterr = 0;
    int c = 0;
    int anything = 0;
    int ok = 0;

    while ((c = getopt(argc, (char **)argv, "HhVv")) != -1)
    {
        switch (c)
        {
            case 'H':
            case 'h':
                usage(0);
            case 'V':
            case 'v':
                version(0);
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "error: unknown option: -%c\n\n", optopt);
                else
                    fprintf(stderr, "error: unrecognized character: '\\x%x'\n\n", optopt);
            default:
                usage(1);
        }
    }

    for (int idx = optind; idx < argc; idx++)
    {
        const char *arg = argv[idx];
        
        anything = 1;

        if (!strcmp(arg, "-"))
            reverse(stdin);
        else
        {
            FILE *file = fopen(arg, "r");
            if (!file)
            {
                fprintf(stderr, "error: cannot open file '%s': %s", arg, strerror(errno));
                ok = -1;
                continue;
            }
            reverse(file);
            if (fclose(file))
            {
                fprintf(stderr, "error: cannot close file '%s': %s", arg, strerror(errno));
                ok = -1;
            }
        }
    }

    if (!anything)
        reverse(stdin);
    return ok;
}
