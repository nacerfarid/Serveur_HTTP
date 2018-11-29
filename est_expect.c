#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_expect(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c est un */
	char S[] = "expect";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if(l!=12 && !strcmp(c,"100-continue")){
	return 0;
	}
    return 1;
}

