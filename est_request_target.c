#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_request_target(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
char S[] = "request_target";
    int i_search = 0;
    if (ls == 14) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int indice = (est_origin_form(c, l, s, ls, callback) || est_absolute_form(c, l, s, ls, callback) || est_authority_form(c, l, s, ls, callback) || (l==1 && est_asterisk_form(c[0])));
    return indice;
}
