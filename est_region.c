#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_region(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "region";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
/*Retourne 1 si c, de longueur l, est une region*/
    if (l == 2 && est_alpha(c[0]) && est_alpha(c[1])) {
        return 1;
    }
    if (l == 3 && est_digit(c[0]) && est_digit(c[1]) && est_digit(c[2])) {
        return 1;
    }
    return 0;
}
}
