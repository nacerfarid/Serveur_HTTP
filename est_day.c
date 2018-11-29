#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_day(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un jour*/
 	char S[] = "day";
    int i_search = 0;
    if (ls == 3) {
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
	return (est_digit(c[0]) && est_digit(c[1]));
}
