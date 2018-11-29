#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_language(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un langage */
	char S[] = "language";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0;
    while (indice <l && est_alpha(c[indice])) {
        indice ++ ;
    }
    if (indice == l && indice >= 2 && indice <= 8) { /*Cas sans extlang*/
        return 1;
    }
    if (indice == l) { /*Cas sans extlang*/
        return 0;
    }
    if (indice < l && c[indice] == '-') /*avec*/ {
        indice ++ ;
        return (est_extlang(c + sizeof(char) * indice, l - indice, s, ls, callback));
    }
}
