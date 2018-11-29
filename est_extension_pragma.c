#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_extension_pragma(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "extension_pragma";
    int i_search = 0;
    if (ls == 16) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int i;
    i=est_cache_directive(c,l, s, ls, callback);
    return (i);
}
