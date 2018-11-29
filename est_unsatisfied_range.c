#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_unsatisfied_range(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une portée non satisfaite */
    char S[] = "unsatisfied_range";
    int i_search = 0;
    if (ls == 17) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int i = (l > 2 && c[0] == '*' && c[1] == '/' && est_complete_length(c + 2*sizeof(char), l-2, s, ls, callback) );
    return i;
}
