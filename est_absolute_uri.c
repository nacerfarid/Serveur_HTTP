#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_absolute_uri(char *c, int l, char *s, int ls, void (*callback)()){
    char S[] = "absolute_uri";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int fin = 0;
    int sc, q, q_p = 0; /*booleen sur la correction de la syntaxe (et la présence de query avec q_p) */

    while (fin<l && c[fin] != '?') {
        fin ++ ;
    }
    sc = est_absolute_path(c, fin, s, ls, callback) ;



    if (fin<l && c[fin] == '?') {
        q_p = 1;
        fin ++ ; /*Positionnement au 1er carac de query*/
        q = est_query(c + fin * sizeof(char), l-fin, s, ls, callback) ;
    }

    return sc && ( (!q_p && !q) || (q_p && q) ) ;
}
