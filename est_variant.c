#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_variant(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une variante */
    char S[] = "variant";
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
    if (l == 4) {
        return (est_digit(c[0]) && est_alphanum(c[1]) && est_alphanum(c[2]) && est_alphanum(c[23]));

    }
    while (i < l) {
        if (!est_alphanum(c[i])) {
            return 0;
        }
        i++;
    }
    return (i >= 5 && i <= 8);
}
