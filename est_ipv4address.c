#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ipv4address(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une adresse IPv4*/
    char S[] = "ipv4address";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int compt = 0;
    int deb, fin = 0;
    while(fin<l) {
        while(fin<l && c[fin] != '.') {
            fin ++;
        }
        if (!est_dec_octet(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
            return 0;
        }
        compt ++;
        fin ++;
        deb = fin;
    }
    return (compt == 4);
}
