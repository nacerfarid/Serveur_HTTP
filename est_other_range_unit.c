#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_other_range_unit(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est ~~~~ une autre unité de portée ~~~~ */
    char S[] = "other_range_unit";
    int i_search = 0;
    if (ls == 16) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }





    int indice = est_token(c, l, s, ls, callback);
    return indice;
}
