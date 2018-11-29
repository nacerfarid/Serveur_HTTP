#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_range_unit(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "range_unit";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }



    int indice= (est_bytes_unit(c,l, s, ls, callback) || est_other_range_unit(c,l, s, ls, callback));
    return (indice);
}
