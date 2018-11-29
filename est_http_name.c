#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_http_name(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est 'HTTP' */
char S[] = "http_name";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (l == 4 && c[0] == 'H' && c[1] == 'T' && c[2] == 'T' && c[3] == 'P');
    return indice;
}
