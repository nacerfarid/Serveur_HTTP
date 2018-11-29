#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_auth_param(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "auth_param";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }



    int i;
    i= est_transfer_parameter(c,l, s, ls, callback);
    return (i) ;
}
