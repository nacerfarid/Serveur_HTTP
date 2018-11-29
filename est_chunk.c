#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_chunk(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "chunk";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int deb=0,fin=0;
    int k,t;
    int d=1;

    while (c[fin]<l) {
        while( c[fin]<l && c[fin]!=';' && c[fin]!=0xD){
            fin++;
        }
        k= est_chunk_size (c,fin, s, ls, callback);
        deb=fin;
        if (fin==l) {
            return 0;
        }

        if (c[fin]==';') {
            while( c[fin]<l && c[fin]!=0xD) {
                fin++;
            }
            d= est_chunk_ext(c+deb*sizeof(char),fin-deb, s, ls, callback);
        }

        if (fin>= l-3) {
            return 0;
        }

        if (c[fin+1]!=0xA || c[l-1]!=0xA || c[l-2]!=0xD ){
            return 0;
        }
        t=est_chunk_data(c+(fin+2)*sizeof(char),l-fin-4, s, ls, callback);
    }
    return (k && t && d);
}
