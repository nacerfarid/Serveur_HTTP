#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_token(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un token*/
	char S[] = "token";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int indice = 0 ;
    if (l==0) {
        return 0;
    }
	while(indice < l) {
        if ( ! est_tchar(c[indice]) ) {
            return 0 ;
        }
        indice ++ ;
	}
	return 1;
}
