#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ls32(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un ls32 */
    char S[] = "ls32";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int b1 = (est_ipv4address(c, l,s,ls,callback));
    int b2 = 0;
    int deb, fin = 0;
    while(fin<l && c[fin] != ':') {
        fin ++;
    }
    if (fin<l && est_h16(c, fin, s, ls, callback) && est_h16(c + sizeof(char) * (fin + 1), l - (fin + 1),s, ls, callback) ) {
        b2 = 1;
    }
    return (b1 || b2);
}
