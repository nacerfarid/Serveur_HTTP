#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_language_range(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une portée de langage */
    char S[] = "language_range";
    int i_search = 0;
    if (ls == 14) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb=0, fin = 0;
    int i ;

    if (l == 1 && c[0] == '*') {
        return 1;
    }

    while( fin < l && c[fin] != '-') {
        fin ++;
    }
    if (fin - deb < 1 || fin - deb >8) {
        return 0;
    }
    for (i = deb; i < fin; i++) {
        if (!est_alpha(c[i])) {
            return 0;
        }
    }
    fin ++;
    deb = fin ;

    while (fin < l) {
        while (fin < l && c[fin] != '-') {
            fin ++;
        }
        if (fin - deb < 1 || fin - deb >8) {
            return 0;
        }

        for (i = deb; i < fin; i++) {
            if (!est_alpha(c[i])) {
                return 0;
            }
        }
        fin++;
        deb = fin;
    }

    return 1;
}

