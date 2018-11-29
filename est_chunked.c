#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_chunked(char c) {
/*Retourne 1 si c est un */
	char S[] = "chunked";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = strcmp(c,"chunked");
    return indice;
}

