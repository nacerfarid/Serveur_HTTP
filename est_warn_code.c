#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_warn_code(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un code d'alerte */
    char S[] = "warn_code";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    if (l == 3 && est_digit(c[0]) && est_digit(c[1]) && est_digit(c[2]) ) {
        return 1;
    }
    return 0;
}
