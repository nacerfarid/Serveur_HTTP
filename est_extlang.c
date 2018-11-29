#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_extlang(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un extlang */
    char S[] = "extlang";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = 0;
    if (l == 3) {
        i = (est_alpha(c[0]) && est_alpha(c[1]) && est_alpha(c[2]));
    }
    else if (l == 7) {
        i = (est_alpha(c[0]) && est_alpha(c[1]) && est_alpha(c[2]));
        i = i && c[4] == '-';
        i = i && (est_alpha(c[4]) && est_alpha(c[5]) && est_alpha(c[6]));
    }
    else if (l == 11) {
        i = (est_alpha(c[0]) && est_alpha(c[1]) && est_alpha(c[2]));
        i = i && c[4] == '-';
        i = i && (est_alpha(c[4]) && est_alpha(c[5]) && est_alpha(c[6]));
        i = i && c[7] == '-';
        i = i && (est_alpha(c[8]) && est_alpha(c[9]) && est_alpha(c[10]));
    }
    else {
        i = 0;
    }
    return i;
}
