#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_codings(char *c, int l, char *s, int ls, void (*callback)()){
	char S[] = "codings";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int a = 0;
    if((l == 8 && strcmp(c,"identity")==0)){
        a = 1;
    }
    int indice = (est_content_coding(c, l, s,ls,callback) || a || (l == 1 && c[0] == '*' ));
    	return indice;
}

