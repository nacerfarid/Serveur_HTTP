#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_path(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c est un chemin*/
    char S[] = "path";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_path_abempty(c, l, s, ls, callback) || est_path_absolute(c, l, s, ls, callback) || est_path_noscheme(c, l, s, ls, callback) || est_path_rootless(c, l, s, ls, callback) || est_path_empty(c, l, s, ls, callback)) ;
    return indice ;
}
