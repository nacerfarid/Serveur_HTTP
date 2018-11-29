#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_imf_fixdate(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "imf_fixdate";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if (l != 29) {
        return 0;
    }
    if(!est_day_name(c, 3, s, ls, callback)){
        return 0;
    }
    if(c[3]!=',' || c[4] != ' '){
        return 0;
    }
    if(!est_date1(c + sizeof(char)*5, 11, s, ls, callback)){
        return 0;
    }
    if(c[16]!=' '){
        return 0;
    }
    if(!est_time_of_day(c + sizeof(char)*17, 8, s, ls, callback)){
        return 0;
    }
    if(c[25]!=' '){
        return 0;
    }
    if(!est_gmt(c + sizeof(char)*26, 3, s, ls, callback)){
        return 0;
    }
    return 1;
}
