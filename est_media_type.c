#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_media_type(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "media_type";
    int i_search = 0;
    if (ls == 10) {
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
    while (fin < l && (c[fin] != '/') ) {
        fin ++;
    }
    if (!est_type(c, fin, s, ls, callback)) {
        return 0;
    }
    deb = fin;
    while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ';') {
        fin++;
    }
    if (!est_subtype(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
        return 0;
    }
    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ';')) {
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
            while (fin <l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ';') {
                fin ++;
            }
            if (!est_parameter(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
                return 0;
            }
        }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
}
