#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_status_code(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un status code*/
	char S[] = "status_code";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    if (l != 3) {
        return 0;
    }

	while(indice < l) {
        if (!( c[indice] - '0' >= 0 && c[indice] - '9' <= 0) ) { /*Entre 0 et 9*/
            return 0 ;
        }
        indice ++ ;
	}
	return 1;
}
