#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_referer(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un Referent */
char S[] = "referer";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_absolute_uri(c, l, s, ls, callback) || est_partial_uri(c, l, s, ls, callback));
    return indice;
}
