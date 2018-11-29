#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_year(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une année*/
    char S[] = "year";
    int i_search;
	i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice;
	indice = 0 ;
    if (l != 4) {
        return 0;
    }

	for(indice=0;indice<4;indice++) {
        if (!est_digit(c[indice])) {
            return 0;
        }
	}

	return 1;
}
