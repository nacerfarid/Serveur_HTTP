#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_content_coding(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un content coding*/
	char S[] = "content_coding";
    int i_search = 0;
    if (ls == 14) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_token(c, l, s, ls, callback)) ;
    return indice;
}
