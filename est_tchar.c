#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_tchar(char c) {
/*Retourne 1 si c est un tchar*/
/*char S[] = "tchar";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
	char L_autre[] = "!#$&'*+-.^_`|~";
	if (est_alpha(c) || est_digit(c)) { /*strstr : caract�re dans string ? */
        	return 1;
	}
	int i = 0;
	for (i=0;i<14;i++) {
        if (c == L_autre[i]) {
            return 1;
        }
	}
	return c == '%';
}
