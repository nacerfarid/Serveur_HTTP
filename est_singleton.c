#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_singleton(char c) {
/*Retourne 1 si c est singleton*/
/*char S[] = "singleton";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int i = (est_digit(c) || (c - 0x41 >= 0 && c - 0x57 - c <= 0) || (c - 0x59 >= 0 && c - 0x5A - c <= 0) || (c - 0x61 >= 0 && c - 0x77 - c <= 0) || (c - 0x79 >= 0 && c - 0x7A - c <= 0));
	return (i);
}

