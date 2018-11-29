#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_http_date(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "http_date";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_imf_fixdate(c, l, s, ls, callback) || est_obs_date(c,l, s, ls, callback));
    return indice;
}
