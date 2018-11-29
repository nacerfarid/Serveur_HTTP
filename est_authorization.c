#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_authorization(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
    char S[] = "authorization";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }




    int indice = (est_credentials(c, l, s, ls, callback) );
    return indice;
}
