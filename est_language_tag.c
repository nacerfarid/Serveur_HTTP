#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_language_tag(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un tag de langage */
    char S[] = "language_tag";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_langtag(c, l, s, ls, callback) || est_privateuse(c, l, s, ls, callback) || est_grandfathered(c, l, s, ls, callback));
    return indice;
}
