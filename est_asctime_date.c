#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_asctime_date(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "asctime_date";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if(!est_day_name(c, 3, s, ls, callback)){
        return 0;
    }
if(c[3]!=' '){
return 0;
}


    if(!est_date3(c + sizeof(char)*4, 6, s, ls, callback)){
        return 0;
    }
if(c[10]!=' '){
return 0;
}
    if(!est_time_of_day(c + sizeof(char)*11, 8, s, ls, callback)){
        return 0;
    }
if(c[19]!=' '){
return 0;
}
    if(!est_year(c + sizeof(char)*20, 4, s, ls, callback)){
        return 0;
    }
if(c[24]!=' '){
return 0;
}
    if(!est_gmt(c + sizeof(char)*25, 3, s, ls, callback)){
        return 0;
    }

    return 1;
}
