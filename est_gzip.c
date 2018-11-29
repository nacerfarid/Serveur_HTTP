#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_gzip(char c) {
/*Retourne 1 si c est un */
	char S[] = "gzip";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = strcmp(c,"gzip");
    return indice;
}

