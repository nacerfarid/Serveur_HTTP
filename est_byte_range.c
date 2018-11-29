#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_byte_range(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "byte_range";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int deb = 0;
    int fin = 0;

    while (fin<l && c[fin] != '-') {
        fin ++ ;
    }
    if(!est_first_byte_pos(c + sizeof(char)*deb, fin - deb, s, ls, callback)){
        return 0;
    }

    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != '\0') {
        fin ++ ;
    }
    if(!est_last_byte_pos(c + sizeof(char)*deb,l-deb, s, ls, callback)){
        return 0;
    }
return 1;
}
