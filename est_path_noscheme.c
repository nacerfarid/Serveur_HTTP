#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_path_noscheme(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l,  est un 'path noscheme' */
    char S[] = "path_noscheme";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    int rep = 1 ;
    if (l == 0) {
        return 1;
    }

    while (fin < l && c[fin] != '/') {
            fin ++;
    }
    rep = rep && est_segment_nz_nc(c , fin, s, ls, callback) ;
    fin ++ ;
    deb = fin ;

    while (fin < l) {
        while (fin < l && c[fin] != '/') {
            fin ++;
        }
        rep = rep && est_segment(c + deb * sizeof(char), fin - deb, s, ls, callback);
        fin ++ ;
        deb = fin ;
    }

    return rep ; /*Pas de pb si c fini par '/', puisque segment peut etre égal a 0*/
}
