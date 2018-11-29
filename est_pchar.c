#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_pchar(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un pchar*/
    char S[] = "pchar";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int bool1 = (l == 1 && (c[0] == ':' || c[0] == '@' || est_unreserved(c[0]) || est_sub_delims(c[0])));
    int bool2 = (l == 3 && est_pct_encoded(c, l, s, ls, callback));
    return (bool1 || bool2);
}
