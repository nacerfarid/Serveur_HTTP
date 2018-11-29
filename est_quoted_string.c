#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_quoted_string(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un scheme*/
    char S[] = "quoted_string";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int indice = 1 ;
    char car ;
    if (l == 0) {
        return 0;
    }
    if (c[0] != '"' || c[l-1] != '"') {
        return 0;
    }

    while (indice<l) {
        if(c[indice] == '\\'){
            if(indice + 1 >= l || !est_quoted_pair(c + sizeof(char)*indice,2,s, ls, callback)){
                return 0;
            }
            indice +=2;
        }
        else {
            if (!(est_qdtext(c[indice]))) {
                return 0;
            }
        indice ++;
        }
    }

    return 1;
}
