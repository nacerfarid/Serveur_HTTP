#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_rfc850_date(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "rfc850_date";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = 0;
    while (i<l && c[i] != ',') {
        i ++ ;
    }

    if(!est_day_name_l(c, i, s, ls, callback)){
        return 0;
    }

    if(c[i+1]!=' '){
        return 0;
    }
    i++;
    if(!est_date2(c + sizeof(char)*(i+1), 9, s, ls, callback)){
        return 0;
    }
    if(c[i+10]!=' '){
        return 0;
    }
    if(!est_time_of_day(c + sizeof(char)*(i+11), 8, s, ls, callback)){
        return 0;
    }
    if(c[i+19]!=' '){
        return 0;
    }
    if(!est_gmt(c + sizeof(char)*(i+20), 3, s, ls, callback)){
        return 0;
    }
    return 1;
}
