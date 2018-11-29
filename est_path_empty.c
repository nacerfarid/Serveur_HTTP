#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_path_empty(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l,  est rien du tout */
    char S[] = "path_empty";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    return (l == 0);
}
