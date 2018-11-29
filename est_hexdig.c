#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_hexdig(char c) {
/*Retourne 1 si c est un hexadecimal*/
	/*char S[] = "hexdig";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (est_digit(c) || (c - 'A' >= 0 && c - 'F' <= 0)) ;
    return indice;
}

