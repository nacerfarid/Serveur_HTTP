#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_other_range_set(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "other_range_set";
    int i_search = 0;
    if (ls == 15) {
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
        if (!(est_vchar(c[indice]), s, ls, callback) ) {
            return 0;
        }
        indice ++;
    }
    return 1;
}
