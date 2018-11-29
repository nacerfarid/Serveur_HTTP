#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_location(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "location";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_uri_reference(c, l, s, ls, callback));
    return indice;
}
