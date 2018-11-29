#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_suffix_byte_range_spec(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "suffix_byte_range_spec";
    int i_search = 0;
    if (ls == 22) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }



    if (l<2) {
        return 0;
    }

    int indice = (c[0]=='-' && est_suffix_length(c+1*sizeof(char),(l-1), s, ls, callback));
    return (indice);
}
