#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_field_value(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "field_value";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }



    if (l==0){
        return 1;
    }
    int deb=0, fin=0;

    while (fin<l) {
        while (fin<l && !est_obs_text(c[fin]) && !est_vchar(c[fin]) && c[fin] != 10) {
            fin++;
        }
        if (c[fin] == 10) {
            if (c[fin-1] != 13) {
                return 0;
            }
            fin++;
            if (fin == l || (c[fin] != ' ' && c[fin] != 9)) {
                return 0;
            }
            while (fin<l && (c[fin] == ' ' || c[fin] != 9)) {
                fin++;
            }
        }
        else if (est_obs_text(c[fin]) || est_vchar(c[fin])) {
            fin++;
        }
    }
    return c[l-1] != ' ' && c[l-1] != 9;
}
