#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_byte_content_range(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "byte_content_range";
    int i_search = 0;
    if (ls == 18) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;


    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    if(!est_bytes_unit(c, fin - deb, s, ls, callback)){
		return 0;
	}
    fin ++ ;
    deb = fin ;
    while (fin<l && c[fin] != ' ') {
        fin ++ ;
    }
    if(!(est_byte_range_resp(c + sizeof(char)*deb, fin-deb, s, ls, callback) || est_unsatisfied_range(c + sizeof(char)*deb, fin-deb, s, ls, callback))){
	return 0;
	}
    return 1;
}
