#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_gmt(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "gmt";
    int i_search = 0;
    if (ls == 3) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
int indice = (l == 3 && c[0] == 'G' && c[1] == 'M' && c[2] == 'T');
    return indice;
}
