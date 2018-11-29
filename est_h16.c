#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_h16(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un nombre hexa écrit sur max 4 chiffres */
    char S[] = "h16";
    int i_search = 0;
    if (ls == 3) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = 0;
    i = 0;
    if (l == 0 || l > 4) {
        return 0;
    }
    while (i<l) {
        if( !est_hexdig(c[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
