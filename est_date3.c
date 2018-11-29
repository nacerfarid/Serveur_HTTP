#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_date3(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */

	char S[] = "date3";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

if(l!= 6){
return 0;
}

    if(!est_month(c, 3, s, ls, callback)){
        return 0;
    }

	if(c[3] != ' '){
	return 0;
	}
    if(!est_digit(c[4]) && c[4] != ' '){
        return 0;
    }
    if(!est_digit(c[5])){
        return 0;
    }
    return 1 ;
}
