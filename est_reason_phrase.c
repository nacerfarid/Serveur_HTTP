#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_reason_phrase(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "reason_phrase";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
/*Retourne 1 si c, de longueur l, est un port*/
    int indice = 0 ;
	while(indice < l) {
        if ( ! ((c[indice]==9) || est_vchar (c[indice]) || est_obs_text(c[indice]) || (c[indice]==20) )) {
            return 0 ;
        }
        indice ++ ;
	}
	return 1;
}

