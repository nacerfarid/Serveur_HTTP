#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_parameter(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un */
	char S[] = "parameter";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;
    int t;

    while (fin<l && c[fin] != '=') {
        fin ++ ;
    }
    if(!est_token(c, fin, s, ls, callback)){
        return 0;
    }

fin++;
    if(!(est_token(c  + sizeof(char)*fin, l-fin, s, ls, callback) || est_quoted_string(c + sizeof(char)*fin,l-fin, s, ls, callback))){
        return 0;
    }
    return 1;
}
