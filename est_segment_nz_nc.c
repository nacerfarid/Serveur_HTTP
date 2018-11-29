#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_segment_nz_nc(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un segment non-nul et non-(quelque chose d'autre)*/
 char S[] = "segment_nz_nc";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    while (indice <l) {
        while (indice < l || est_sub_delims(c[indice]) || est_unreserved(c[indice]) || c[indice] == '@') {
            indice ++;
        }
        if (indice < l) {
            if (c[indice] == '%') {
                indice = indice && est_pct_encoded(c + indice * sizeof(char), 3, s, ls, callback);

            }
            else {
                indice = 0;
            }
        }
    }
    return indice;
}
