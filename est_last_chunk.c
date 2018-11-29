#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_last_chunk(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "last_chunk";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int deb=0;
    int sc=1;
    if (l==0 || c[deb]!=0) {
        return 0;
    }
    while (c[deb]=='0' && deb<l) {
        deb++;
    }
    if (deb==l){
        return (0);
    }

    deb++;
    if (c[deb]!= 0xD) {
        sc=est_chunk_ext(c+deb*sizeof(char), l-deb-1, s, ls, callback);
    }
    if (c[l-2]== 0xD && c[l-1]==0xA) {
        return (sc);
    }
    else return 0;
}
