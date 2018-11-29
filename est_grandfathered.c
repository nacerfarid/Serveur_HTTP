#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_grandfathered(char *c, int l, char *s, int ls, void(*callback)()) {
/*Retourne 1 si c, de longueur l, est un 'grand-père-ifié'*/
    char S[] = "grandfathered";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = (est_irregular(c, l, s, ls, callback) || est_regular(c, l, s, ls, callback));
    return i;
}
