#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_cookie_octet(char c){
 /*char S[] = "cookie_octet";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (c == 0x21 || (c - 0x23 >=0 && c - 0x2B <= 0) || (c - 0x2D >=0 && c - 0x3A <= 0) || (c - 0x3C >=0 && c - 0x5B <= 0) || (c - 0x5D >=0 && c - 0x7E <= 0));
    return indice;
}

