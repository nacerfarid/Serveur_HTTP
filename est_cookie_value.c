#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"


int est_cookie_value(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une année*/
    char S[] = "cookie_value";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int fin=0;
	if (c[0] == '"' && c[l-1]=='"'){
		fin = 1;
		while (fin<l-1){
			if(!est_cookie_octet(c[fin])){
				return 0;
			}
		fin ++;
		}
	}
	else{
		while(fin<l){
			if(!est_cookie_octet(c[fin])){
				return 0;
			}
		fin ++;
		}
	}
return 1;
}
