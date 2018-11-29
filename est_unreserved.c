#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_unreserved(char c) {
/*Retourne 1 si c est un unreserved*/
/*char S[] = "unreserved";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (est_alpha(c) || est_digit(c) || c == '-' || c == '.' || c == '_' || c == '~');
    return indice;
}


