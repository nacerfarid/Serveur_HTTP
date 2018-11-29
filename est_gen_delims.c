#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_gen_delims(char c) {
/*Retourne 1 si c, est un delimiteur 'gen' */
	/*char S[] = "gen_delims";
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
    char L[] =":!?#[]@";
	while (indice < 7 && L[indice] != c) {
	    indice ++;
	}
	return (indice != 7);
}
