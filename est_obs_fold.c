#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_obs_fold(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "obs_fold";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int sc, q = 2;

    if (l < 2 || c[0] != 0xD || c[1] != 0xA) {
        return 0;
    }
    while (q<l && (c[q] == ' ' || c[q] == 9)) {
        q++;
    }

    return q==l ;
}
