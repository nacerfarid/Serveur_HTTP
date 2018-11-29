#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_content_length(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un content length*/
char S[] = "content_length";
    int i_search = 0;
    if (ls == 14) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
    if (l == 0) {
        return 0;
    }
    while (indice<l) {
        if (!est_digit(c[indice])) {
            return 0;
        }
        indice ++;
    }
    return 1;
}
