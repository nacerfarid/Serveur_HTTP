#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_fragment(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un fragment*/
    char S[] = "fragment";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
	while (indice < l) {
	    while(indice < l && c[indice] != '/' && c[indice] != '?' && c[indice] != '%') {
	        indice ++ ;
	    }
	    if (c[indice] == '%') {
	        if (indice +2 >= l || !est_pchar(c + indice * sizeof(char), 3, s, ls, callback) ) {
	            return 0;
	        }
	        indice += 3 ;
	    }
	    else {
	        if (!est_pchar(c + indice * sizeof(char), 1, s, ls, callback)) {
	            return 0;
	        }
	        indice ++;
	    }
	}
	return 1;
}
