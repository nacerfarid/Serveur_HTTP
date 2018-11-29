#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_server(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "server";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    while (fin < l && (c[fin] != 9) && (c[fin] != 20)) {
        fin ++;
    }
    if (!est_product(c, fin, s, ls, callback)) {
        return 0;
    }
    deb = fin;
    while (fin<l && (c[fin] == 20 || c[fin] == 9)){
        fin ++;
    }
    while (fin < l) {
        fin++;
    }
    if (!(est_subtype(c + sizeof(char) * deb, fin - deb, s, ls, callback)||est_comment(c + sizeof(char)*deb,fin-deb,s,ls,callback))) {
        return 0;
    }

    return 1;
}
