#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_asterisk_form(char c) {
/*Retourne 1 si c est un astérisque*/
	/*char S[] = "asterisk_form";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (c == '*');
    return indice;
}

