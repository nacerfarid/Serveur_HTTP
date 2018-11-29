#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_dquote(char c) {
/*Retourne 1 si c est */
	/*char S[] = "dquote";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
if(c !='"'){
return 0;
}

    return 1;
}

