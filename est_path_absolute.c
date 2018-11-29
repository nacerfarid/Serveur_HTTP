#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_path_absolute(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l,  est un chemin absolu */
    char S[] = "path_absolute";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin ;
    int rep = 1 ;
    if (l == 0 || c[0] != '/') {
        return 0;
    }
    fin = 1;
    deb = 1;

    while (fin < l && c[fin] != '/') { /*On vérifie qu'on a 1 segment nz*/
        fin ++;
    }
    rep = rep && est_segment_nz(c + deb * sizeof(char), fin - deb, s,ls, callback);
    fin ++ ;
    deb = fin ;
    while (fin < l) { /*Puis on vérifie qu'on a un certain nombre de '/segment' */
        while (fin < l && c[fin] != '/') {
            fin ++;
        }
        rep = rep && est_segment(c + deb * sizeof(char), fin - deb, s,ls, callback);
        fin ++ ;
        deb = fin ;
    }
    return rep ;
}
