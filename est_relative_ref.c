#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_relative_ref(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une référence relative*/
    char S[] = "relative_ref";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int r = 0;
    int q_p = 0 ;
    int f_p = 0 ; /*présence des champs query et fragment*/
    int q = 0 ;
    int f = 0 ; /* q et f sont corrects*/

    int debut = 0;
    int fin = 0;

    while(fin<l && c[fin] != '?' && c[fin] != '#') {
        fin ++ ;
    }
    r = (est_relative_part(c + sizeof(char)*debut , fin - debut, s, ls, callback));

    /*3 Cas : Il y a un ?, un #, ou alors on a fini*/

    if (fin < l && c[fin] == '?') {
        q_p = 1;
        fin ++ ;
        debut = fin ;
        while ( fin<l && c[fin] != '#') {
            fin ++ ;
        }
        q = est_query(c + sizeof(char)*debut, fin - debut, s, ls, callback) ;
    }

    if (fin < l && c[fin] == '#') {
        f_p = 1;
        fin ++ ;
        debut = fin ;
        f = est_fragment(c + sizeof(char)*debut, l - debut, s, ls, callback); /*Pas besoin de calculer fin*/
    }

    return (r && ( (!q_p && !q) || (q_p && q)) && ( (!f_p && !f) || (f_p && f))) ;
}
