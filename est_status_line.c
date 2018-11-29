#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_status_line(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "status_line";
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

    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    if(!est_http_version(c, fin - deb, s, ls, callback)){
	return 0;
	}
    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    if(!est_status_code(c + sizeof(char)*deb, fin-deb, s, ls, callback)){
		return 0;
	}
    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin-1] != '\r' && c[fin] != '\n') {
        fin ++ ;
    }
    if(!est_reason_phrase(c , l-deb, s, ls, callback)){
		return 0;
	}
    return 1;
}
