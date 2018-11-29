#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_https_uri(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "https_uri";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int i = (l >= 8 && c[0] == 'h' && c[1] == 't' && c[2] == 't' && c[3] == 'p' && c[4] == 's' && c[5] == ':' && c[6] == '/'  && c[7] == '/');
    if (i==0) {
        return 0;
    }
    int deb,fin = 0;
    int k, o, q_p, x  = 0;
    int q=1;
    while (fin<l && c[fin] != '?' && c[fin]!= '/' && c[fin]!='#') {
        fin ++ ;
    }
    if (fin==l) {
        return ( est_authority(c,l, s, ls, callback));
    }
    k = est_authority(c, fin, s, ls, callback) ;


    deb=fin;
    if (c[fin]=='/') {
        while (fin<l && c[fin] != '?' && c[fin]!='#') {
            fin++;
        }
        q=est_path_abempty(c+deb*sizeof(char),fin-deb, s, ls, callback);
    }

    if (fin==l) {
        return k && q ;
    }


    if (c[fin]=='?') {
        deb=fin;
        q_p = 1;
        while (fin<l && c[fin] !='#') {
            fin ++ ; /*Positionnement au 1er carac de query*/
            o = est_query(c + deb * sizeof(char), fin-deb, s, ls, callback) ;
        }
    }


    if (fin==l) {
        return (k && q && ( (!q_p && !o) || (q_p && o) ) );
    }
    fin++;
    x=est_fragment (c+ fin*sizeof(char), l-fin-1, s, ls, callback);


    return (k && q && x && ( (!q_p && !o) || (q_p && o) ) ) ;
}
