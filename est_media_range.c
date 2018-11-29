#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_media_range(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "media_range";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb=0, fin = 0;
    int virgule ;
    while(fin<l && c[fin] != '/') {
        fin++;
    }
    if (fin == l) {
        return 0;
    }
    if (c[0] == '*') {
        fin++;
    }
    else {
        if (!est_type(c,fin,s,ls,callback)) {
            return 0;
        }
        fin++;
    }
    if (fin==l) {
        return 0;
    }

    deb = fin;
    if (c[fin] == '*') {
        fin++;
    }
    else {
        while (fin<l && c[fin] != ';' && c[fin] != ' ' && c[fin] != 9) {
            fin++;
        }
        if (!est_subtype(c+sizeof(char)*deb,fin-deb,s,ls,callback)) {
            return 0;
        }
        if (fin == l) {
            return 1;
        }
    }

    while (fin<l) {
        while (fin<l && c[fin] != ';') {
            fin++;
        }
        if (fin==l) {
            return 0;
        }
        fin++;
        while (fin<l && (c[fin] == ' ' || c[fin] == 9)) {
            fin++;
        }

        deb = fin;
        if (fin == l) {
            return 0;
        }
        while (fin<l && c[fin] != ' ' && c[fin] != ';' && c[fin] != 9) {
            fin++;
        }
        if (!est_parameter(c+sizeof(char)*deb,fin-deb,s,ls,callback)) {
            return 0;
        }
        if (fin==l) {
            return 1;
        }
    }
}
