#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_hier_part(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un 'hier-part' */
    char S[] = "hier_part";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int booleen1 = (est_path_absolute(c, l, s, ls, callback) || est_path_rootless(c, l, s, ls, callback) || est_path_empty(c, l, s, ls, callback)) ;
    int booleen2 = 1;
    int deb = 2 ; /*Dans le cas avec // */
    int fin = 2 ; /*Idem*/
    int a = 0 ; /*authority correct, le cas �ch�ant*/
    int p = 1 ; /*path_abempty...*/ /*vaut 1, car il peut �tre vide*/

    /*Cas //authority path-abempty */
    if (l<2 || c[0] != '/' || c[1] != '/') { /*Cas // non pr�sent*/
        booleen2 = 0;
    }
    else {
        while(fin<l && c[fin] != '/') {
            fin ++ ;
        }
        a = est_authority(c + 2*sizeof(char), fin - deb, s, ls, callback) ;
        if (fin<l) { /*Il y a un contenu non nul apr�s authority */
            p =  p && est_path_abempty(c + fin * sizeof(char), l - fin, s, ls, callback) ;
        }
    }
    booleen2 = booleen2 && (a && p) ;
    return (booleen1 || booleen2) ;
}
