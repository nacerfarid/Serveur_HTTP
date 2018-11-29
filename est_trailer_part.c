#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_trailer_part(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "trailer_part";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
	while(indice < l && c[indice-1] !='\t' && c[indice] != '\n') {
        if ( ! (est_header_field(c, l, s, ls, callback) ) ) {
            return 0 ;
        }
        indice ++ ;
	}
	return 1;
}

