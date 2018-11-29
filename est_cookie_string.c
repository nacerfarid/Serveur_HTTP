#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_cookie_string(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "cookie_string";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    int virgule ;
    if (l != 0 && c[0] == ' ') {
        return 0;
    }
    while (fin < l && c[fin] != ' ' && c[fin] != ';') {
        fin++;
    }
    if (!est_cookie_pair(c + sizeof(char), fin, s, ls, callback)) {
        return 0;
    }
    deb = fin;

    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == ';')) {
            if (c[fin] == ';') {
                virgule = 1;
            }
            fin++;
        }
        if (fin < l) {
            if (virgule == 0) {
                return 0;
            }
            virgule = 0;
	    deb = fin;
            while (fin <l && c[fin] != ' ' && c[fin] != ';') {
                fin ++;
            }
            if (!est_cookie_pair(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
                return 0;
            }
        }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
}
