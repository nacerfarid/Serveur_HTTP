#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_time_of_day(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "time_of_day";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;


    while (fin<l && c[fin] != ':') {
        fin ++ ;
    }
    if(!est_hour(c, fin - deb, s, ls, callback)){
        return 0;
    }

    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != ':') {
        fin ++ ;
    }
    if(!est_minute(c + sizeof(char)*deb, fin-deb, s, ls, callback)){
        return 0;
    }
    fin ++ ;
    deb = fin ;
    while (fin<l) {
        fin ++ ;
    }
    if(!est_second(c + sizeof(char)*deb, l-deb, s, ls, callback)){
        return 0;
    }
    return 1;
}
