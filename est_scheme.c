#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_scheme(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un scheme*/
    char S[] = "scheme";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 1 ;
    char car ;
    if (l == 0) {
        return 0;
    }
    if (!(est_alpha(c[0]))) {
        return 0;
    }
    while (indice<l) {
        car = c[indice];
        if (!(est_alpha(car) || est_digit(car) || car == '+' || car == '-' || car == '.')) {
            return 0;
        }
        indice ++;
    }
    return 1;
}
