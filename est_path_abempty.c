#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_path_abempty(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l,  est un 'path abempty' */
    char S[] = "path_abempty";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin ;
    int rep = 1 ;
    if (l == 0) {
        return 1;
    }
    if (c[0] != '/') {
        return 0;
    }
    fin = 1;
    deb = 1;

    while (fin < l) {
        while (fin < l && c[fin] != '/') {
            fin ++;
        }
        rep = rep && est_segment(c + deb * sizeof(char), fin - deb, s, ls, callback);
        fin ++ ;
        deb = fin ;
    }
    return (rep) ; /*Pas de pb si c fini par '/', puisque segment peut etre égal a 0*/
}
