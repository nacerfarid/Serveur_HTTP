#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_digit(char c) {
/*Retourne 1 si c est un chiffre entre 0 et 9*/
	/*char S[] = "digit";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int i = ((c - '0' >= 0 ) && (c - '9' <= 0));
	return (i) ;
}

