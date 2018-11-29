#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_proxy_authorization(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une autorisation d'un proxy  */
    char S[] = "proxy_authorization";
    int i_search = 0;
    if (ls == 19) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }



    int i = ( est_credentials(c, l, s, ls, callback) );
    return i;
}
