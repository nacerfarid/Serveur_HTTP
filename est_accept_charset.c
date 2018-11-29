#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept_charset(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "accept_charset";
    int i_search = 0;
    if (ls == 14) {
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
    while (deb < l && (c[deb] == ' ' || c[deb] == 9 || c[deb] == ',') ) {
        deb ++;
    }
    fin = deb ;
    while (fin < l && c[fin] != ' ') {
        fin++;
    }
    if (!(est_charset(c + sizeof(char) * deb, fin - deb, s, ls, callback)||(l==1 && c[fin]=='*'))) {
        return 0;
    }
    deb = fin;
    while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ',') {
        fin++;
    }
    if (!est_weight(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
        return 0;
    }
    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',')) {
            if (c[fin] == ',') {
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
            while (fin < l && c[fin] != ' ') {
                fin++;
            }
            if (!(est_charset(c + sizeof(char) * deb, fin - deb, s, ls, callback)||(l==1 && c[fin]=='*'))) {
                return 0;
            }
            deb = fin;
            while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ',') {
                fin++;
            }
            if (!est_weight(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
            return 0;
            }
        }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
}
