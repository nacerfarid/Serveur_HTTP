#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_date1(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */

	char S[] = "date1";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    if(l!= 11){
        return 0;
    }
    if(!est_day(c, 2, s, ls, callback)){
        return 0;
    }
	if(c[2] != ' '){
        return 0;
	}
    if(!est_month(c + sizeof(char)*3, 3, s, ls, callback)){
        return 0;
    }
    if(c[6] != ' '){
        return 0;
	}
    if(!est_year(c+sizeof(char)*7,4,s,ls,callback)){
        return 0;
    }

    return 1;

}
