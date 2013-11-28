/*
 * linerev.c - Reverse characters in string.
 *
 * Copyright (C) 2013 Maxthon Chan <xcvista@me.com>
 *
 */

#include "linerev.h"
#include <string.h>
#include <stdlib.h>

char *strrev(char *dst, const char *src)
{
    char *dp = dst;
    for (const char *sp = src + strlen(src) - 1; sp >= src; sp--, dp++)
        *dp = *sp;
    *dp = 0;
    return dp;
}
