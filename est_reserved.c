#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_reserved(char c) {
/*Retourne 1 si c, de longueur l, est un reservé*/
 /*char S[] = "reserved";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int i = (est_gen_delims(c) || est_sub_delims(c));
    return i;
}
