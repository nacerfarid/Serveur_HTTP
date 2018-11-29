#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_qdtext(char c){
 /*char S[] = "qdtext";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (est_obs_text(c) || c == 9 || c == 20 || c == 21 || (c - 0x23 >=0 && c - 0x5B <= 0) || (c - 0x5D >=0 && c - 0x7E <= 0));
    return indice;
}

