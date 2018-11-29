#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_host(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un host */
    char S[] = "host";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_ip_literal(c, l, s, ls, callback) || est_ipv4address(c, l, s, ls, callback) || est_reg_name(c, l, s, ls, callback));
    return indice;
}
