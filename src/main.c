#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linerev.h"

int main(int argc, const char **argv)
{
    char *inbuf = malloc(1024);
    char *outbuf = malloc(1024);
    if (!inbuf || !outbuf)
    {
        fprintf(stderr, "error: no memory.\n");
        exit(1);
    }

    memset(inbuf, 0, 1024);
    memset(outbuf, 0, 1024);
    while (fgets(inbuf, 1024, stdin))
    {
        inbuf[strlen(inbuf) - 1] = 0;
        strrev(outbuf, inbuf);
        puts(outbuf);
        memset(inbuf, 0, 1024);
        memset(outbuf, 0, 1024);
    }
    exit(0);
}
