#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_privateuse(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une privateuse */
    char S[] = "privateuse";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb,fin = 2;
    int i ;
    int test = 0; /* si au moins un -alphanum */
    if (l < 2 || c[0] != 'x' || c[1] != '-') {
        return 0;
    }
    while (fin<l) {
        while (fin<l && c[fin] != '-') {
            fin++;
        }
        if (fin - deb > 8 || fin - deb < 2) { /* trop ou pas assez de caractère entre deux - */
            return 0;
        }
        test = 1;
        for (i = deb; i < fin; i++) {
            if (!(est_alphanum(c[i]))) {
                return 0;
            }
        }
        fin ++;
        deb = fin ;
    }
    return test;
}
