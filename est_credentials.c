#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_credentials(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "credentials";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    return( est_challenge(c,l, s, ls, callback));
}
