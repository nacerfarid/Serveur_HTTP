#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_complete_length(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une longueur totale */
    char S[] = "complete_length";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int i = 0;
    if (l == 0) {
        return 0;
    }
    while (i<l) {
        if (!est_digit(c[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
