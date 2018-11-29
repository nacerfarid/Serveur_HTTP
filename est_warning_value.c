#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_warning_value(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "warning_value";
    int i_search;
	i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int deb;
    int fin;
	deb=0;fin=0;
    int m, r, v, z;

    while (fin<l && c[fin] != ' ') {    /* délimitation de warn-code */
        fin ++ ;
    }
    m = est_warn_code(c, fin, s, ls, callback) ;         /* test de warn-code */

    if (fin==l){                        /* vérification pour pouvoir faire fin++ */
        return 0;
    }



    fin++ ;
    deb=fin;
    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    r = est_warn_agent(c + deb*sizeof(char) , fin-deb, s, ls, callback) ;

    if (fin==l){                        /* vérification pour pouvoir faire fin++ */
        return 0;
    }




    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    v = est_warn_text(c + deb*sizeof(char) , fin-deb, s, ls, callback) ;

    if (fin==l){
        return m && r && v;
    }


    if (c[fin]== ' ') {
        fin++;
        z= est_warn_date(c + fin*sizeof(char) , l-fin, s, ls, callback) ;
        return m && r && v && z ;
    }
}
