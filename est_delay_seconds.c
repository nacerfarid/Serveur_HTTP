#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_delay_seconds(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un delai seconde*/
	char S[] = "delay_seconds";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    if (l == 0) {
        return 0;
    }
    while (indice<l) {
        if (!(est_digit(c[indice]))) {
            return 0;
        }
        indice ++;
    }
    return 1;
}
