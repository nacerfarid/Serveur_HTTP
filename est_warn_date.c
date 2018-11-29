#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_warn_date(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une date d'alerte */
    char S[] = "warn_date";
    int i_search;
i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int indice;
	indice = (l>2 && c[0] == '"' && c[l-1] == '"' && est_http_date(c + 1*sizeof(char), l-2, s, ls, callback));
    return indice;
}
