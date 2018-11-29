#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_alphanum(char c) {
/*Retourne 1 si c est un alphanum*/
	/*char S[] = "alphanum";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (est_alpha(c) || est_digit(c)) ;
    return indice;
}
