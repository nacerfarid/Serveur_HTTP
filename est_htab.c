#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_htab(char c) {
/*Retourne 1 si c est un */
	char S[] = "htab";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
if(l!=1 && c[0]!='\t'){
return 0;
}
return 1;
}

