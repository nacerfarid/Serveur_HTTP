#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ip_literal(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un 'ip literal' */
    char S[] = "ip_literal";
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
    if (l == 0 || c[0] != '[' || c[l - 1] != ']') {
        return 0;
    }
    i = (est_ipv6address(c + sizeof(char), l - 2, s, ls, callback) || est_ipvfuture(c + sizeof(char), l - 2, s, ls, callback));
    return i;
}
