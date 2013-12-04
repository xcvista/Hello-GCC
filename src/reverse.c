#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse.h"
#include "linerev.h"

void reverse(FILE *file)
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
    while (fgets(inbuf, 1024, file))
    {
        inbuf[strlen(inbuf) - 1] = 0;
        strrev(outbuf, inbuf);
        puts(outbuf);
    }
}
