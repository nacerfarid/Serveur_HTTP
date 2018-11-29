#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_cache_directive(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "cache_directive";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int k = 0;
    int h = 0;

    int fin = 0;
    while(fin<l && c[fin] != '=') {
        fin ++ ;
    }
    k = ( est_token(c, fin, s, ls, callback) );                    /* cas ou on a qu'un token */
    if (fin==l){
        return k;
    }

    fin++;
    h=(est_chunk_ext_val(c + fin*sizeof(char) , l-fin, s, ls, callback) )  ;


    return (h && k);
}
