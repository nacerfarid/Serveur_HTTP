#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_script(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un script*/
    char S[] = "script";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    int i ;
    if (l != 4) {
        return 0;
    }
    for(i = 0; i<4; i++) {
        if (!(est_alpha(c[i])) ) {
            return 0;
        }
    }
    return 1;
}

}

