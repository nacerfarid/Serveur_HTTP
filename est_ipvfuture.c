#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ipvfuture(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une version future d'un ip*/
    char S[] = "ipvfuture";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = 1 ;
    if (l == 0 || c[0] != 'v') {
        return 0;
    }
    while (i < l && c[i] != '.') {
        if (!est_hexdig(c[i])) {
            return 0 ;
        }
        i ++;
    }
    if (i == l) { /*On saute le '.' */
        return 0 ;
    }
    i++ ;
    if (i == l) { /*On vérife qu'il y a au moins un unreserved/sub/: */
        return 0;
    }
    while (i<l) {
        if (!(est_unreserved(c[i]) || est_sub_delims(c[i]) || c[i] == ':')) {
            return 0;
        }
        i++;
    }
    return 1;
}
