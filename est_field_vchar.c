#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_field_vchar(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un pourcentage d'encodage*/
    char S[] = "field_vchar";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int k=0;
    while (k<l) {
        if (!(est_vchar(k) || est_obs_text(k))) {
            return 0;
        }
        k++;
    }
    return 1;
}
