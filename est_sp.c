#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_sp(char c) {
/*Retourne 1 si c est un */
char S[] = "sp";
    int i_search = 0;
    if (ls == 2) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if(l!=1 && c[0]!=' '){
	return 0;
	}
return 1;
}

