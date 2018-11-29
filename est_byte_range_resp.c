#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_byte_range_resp(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un */
    int deb, fin = 0;
    int space = 1; /*pour s'assurer qu'il n'y ait pas d'espace à la fin du field content*/
	char S[] = "byte_range_resp";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    while (fin < l && c[fin] != '/') {
        fin ++;
    }
    if(!est_byte_range(c, fin, s, ls, callback)){
        return 0;
    }
    while (fin < l) {
        fin ++;
    }
	
    if(!(est_complete_length(c + deb * sizeof(char), fin - deb, s, ls, callback))){
        return 0;
    }
    while (fin < l) {
		if(!est_asterisk_form(fin)){
			return 0;
		}
    }
    return 1;
}
