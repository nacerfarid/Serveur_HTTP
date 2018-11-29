#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_chunk_ext_val(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "chunk_ext_val";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int indice= (est_token(c,l, s, ls, callback) || est_quoted_string(c,l, s, ls, callback));
    return (indice);
}
