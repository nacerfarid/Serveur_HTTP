#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_warn_text(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un texte d'alerte */
    char S[] = "warn_text";
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


    if (l==0) {
        return 0;
    }
    int indice;
	indice = (est_quoted_string(c, l, s, ls, callback)) ;
    return indice;
}
