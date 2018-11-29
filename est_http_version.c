#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_http_version(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une version d'HTTP */
char S[] = "http_version";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (l == 8 && est_http_name(c, 4,s,ls,callback) && c[4] == '/' && c[6] == '.' && est_digit(c[5]) && est_digit(c[7])) ;
    return indice;
}
