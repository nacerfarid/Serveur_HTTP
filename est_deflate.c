#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_deflate(char c) {
/*Retourne 1 si c est un */
	char S[] = "deflate";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = strcmp(c,"deflate");
    return indice;
}

