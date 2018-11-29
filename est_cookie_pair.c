#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_cookie_pair(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "cookie_pair";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int fin = 0;
    int m, k;

    while (fin<l && c[fin] != '=') {
        fin ++ ;
    }
    m = est_cookie_name(c, fin, s, ls, callback) ;

    if (fin+1>=l) {
        return 0;
    }

    fin+=2 ;
    k = est_cookie_value(c+fin*sizeof(char) , l-fin, s, ls, callback) ;

    return m && k;
}
