#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_pct_encoded(char *c, int l, char *s,int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un pourcentage d'encodage*/
    char S[] = "pct_encoded";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if (l != 3) {
        return 0;
    }
    if (c[0] != '%' || !est_hexdig(c[1]) || est_hexdig(c[2])) {
        return 0;
    }
    return 1;
}
