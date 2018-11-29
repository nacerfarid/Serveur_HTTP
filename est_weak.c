#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_weak(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
    char S[] = "weak";
    int i_search;
	i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
int indice;
indice = (l == 2 && c[0] == 'W' && c[1] == '/');
return indice;
}
