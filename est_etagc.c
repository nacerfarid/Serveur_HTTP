#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_etagc(char c) {
/*Retourne 1 si c est un obs text*/
	/*char S[] = "etagc";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int a = (c - 0x80 >=0 && c - 0xFF <= 0) ;
    char cs = '!';
    return (a || cs);
}
