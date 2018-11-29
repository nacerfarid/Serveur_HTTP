#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_bytes_unit(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est "bytes" */
    char S[] = "bytes_unit";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int i = (l == 5 && c[0] == 'b' && c[1] == 'y' && c[2] == 't' && c[3] == 'e' && c[4] == 's');
    return i;
}
