#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_quoted_pair(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un port*/
    char S[] = "quoted_pair";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

	if (l != 2 || c[0] != 92) {
        return 0;
	}
	if ( ! ((c[1]==9) || est_vchar (c[1]) || est_obs_text(c[1]) || (c[1]==' ') )) {
        return 0;
	}
	return 1;
}

