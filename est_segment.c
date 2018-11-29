#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_segment(char *c, int l, char *s,int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un segment*/
    char S[] = "segment";
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
	while(indice < l) {
	    if (indice + 2 < l && est_pchar(c + sizeof(char) * indice, 3, s,ls, callback)) {
            indice += 3;
	    }
	    else if (indice < l && est_pchar(c + sizeof(char) * indice, 1, s,ls, callback)) {
            indice ++;
	    }
	    else {
            return 0;
	    }
	}
	return 1;
}
