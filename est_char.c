#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_char(char c) {
/*Retourne 1 si c est un char*/
	/*char S[] = "char";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    if(c==0x00){
        return 0;
    }
    return 1;
}

