#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_if_match(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "if_match";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
int deb, fin = 0;
    int virgule ;
    if(l == 1 && c[0] == '*'){
        return 1;
    }
    if (l != 0 && c[0] == ' ') {
        return 0;
    }
    while (deb < l && (c[deb] == ' ' || c[deb] == 9 || c[deb] == ',') ) {
        deb ++;
    }
    fin = deb ;
    while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ',') {
        fin++;
    }
    if (!est_entity_tag(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
        return 0;
    }
    deb = fin;
    /*Au moins 1 virgule entre 2 entity-tag*/
    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',')) {
            if (c[fin] == ',') {
                virgule = 1;
            }
            fin++;
        }
        if (fin < l) { /*Il y a un entity_tag*/
            if (virgule == 0) {
                return 0;
            }
            virgule = 0;


            deb = fin;
            while (fin <l && c[fin] != ' ' && c[fin] == 9 && c[fin] != ',') {
                fin ++;
            }
            if (!est_entity_tag(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
                return 0;
            }
        }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
}
