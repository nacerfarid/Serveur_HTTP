#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_request_line(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
char S[] = "request_line";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;

    while (fin<l && c[fin] != ' ' && c[fin] != 9) {
        fin ++ ;
    }
    if(!est_method(c, fin - deb, s, ls, callback)){
		return 0;
	}
    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != ' ' && c[fin] != 9) {
        fin ++ ;
    }
    if(!est_request_target(c + sizeof(char)*deb, fin-deb, s, ls, callback)){
	return 0;
	}
    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin-1] != '\r' && c[fin] != '\n') {
        fin ++ ;
    }
    if(!est_http_version(c + sizeof(char)*deb, (l-2)-deb, s, ls, callback)){
		return 0;
	}
	if (c[l-2] != 13 || c[l-1] != 10) {
        return 0;
	}
    return 1;
}
