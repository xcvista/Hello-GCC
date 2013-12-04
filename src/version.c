#include <stdio.h>
#include <stdlib.h>

#include "version.h"

void usage(int e)
{
    fprintf(stderr,
            "USAGE: rev [OPTIONS] [file ...]\n"
            "\n"
            "OPTIONS:\n"
            "  -H, -h:\tShow this help messag and exit.\n"
            "  -V, -v:\tShow the version information and exit.\n\n");

    version(e);
}

void version(int e)
{
    fprintf(stderr,
            "tinyREV version %s (git %s)\n"
            "Yet another free implementation of rev(1)\n"
            "Written in 2013 by Maxthon Chan\n"
            "\n"
            "This software is licensed under CC0 license.\n", VERSION, VCS_VERSION);
    exit(e);
}
