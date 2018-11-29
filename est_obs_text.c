#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_obs_text(char c) {
/*Retourne 1 si c est un obs text*/
	/*char S[] = "obs_text";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (c - 0x80 >=0 && c - 0xFF <= 0) ;
    return indice;
}
