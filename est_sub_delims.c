#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_sub_delims(char c) {
/*Retourne 1 si c, est un delimiteur 'sub' */
/*char S[] = "sub_delims";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = 0 ;
    char L[] = "!$&'()*+,;=";
	while (indice < 11 && L[indice] != c) {
	    indice ++;
	}
	return (indice != 11);
}
