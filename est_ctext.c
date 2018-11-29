#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ctext(char c) {
/*Retourne 1 si c, de longueur l, est un  */
	/*char S[] = "ctext";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (est_obs_text(c) || c == 9 || c == ' ' || (c - 0x21 >= 0 && c - 0x27 <= 0) || (c - 0x2A >= 0 && c - 0x5B <= 0) || (c - 0x5D >= 0 && c - 0x7E <= 0));
    return indice;
}
