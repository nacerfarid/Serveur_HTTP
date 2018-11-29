#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_reg_name(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un nom de reg*/
    char S[] = "reg_name";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    int rep = 1 ;
    while (indice <l) {
        while (indice < l && (est_sub_delims(c[indice]) || est_unreserved(c[indice]))) {
            indice ++;
        }
        if (indice < l) {
            if (c[indice] == '%') {
                if (indice+2>=l) {
                    return 0;
                }
                rep = rep && est_pct_encoded(c + indice * sizeof(char), 3, s, ls, callback);

            }
            else {
                rep = 0;
            }
        }
        indice++;
    }
    return rep;
}
