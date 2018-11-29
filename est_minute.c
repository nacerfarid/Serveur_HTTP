#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_minute(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une minute*/
	char S[] = "minute";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    if (l != 2) {
        return 0;
    }

	while(indice < l) {
        if (!( c[indice] - '0' >= 0 && c[indice] - '9' <= 0) ) { /*Entre 0 et 9*/
            return 0 ;
        }
        indice ++ ;
	}
	if(c[0]>5 && c[1] > 9){
		return 0;
	}
	return 1;
}
