#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_byte_range_spec(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "byte_range_spec";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int fin = 0;
    int k, h, q, q_p = 0; /*booleen sur la correction de la syntaxe (et la présence de last-byte-pos avec q_p) */

    while (fin<l && c[fin] != '-') {
        fin ++ ;
    }
    k = est_first_byte_pos(c, fin, s, ls, callback) ;

    fin ++ ;

    if (fin<l ) {
        q_p = 1;
        fin ++ ; /*Positionnement au 1er carac de last-byte-pos*/
        q = est_last_byte_pos(c + fin * sizeof(char), l-fin, s, ls, callback) ;
    }

    return (k && ( (!q_p && !q) || (q_p && q) )) ;
}
