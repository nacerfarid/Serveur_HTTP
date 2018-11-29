#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"
/*a faire*/

int est_opaque_tag(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
    		char S[] = "opaque_tag";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int i;
	for(i=1;i<l-1;i++){
		if(!est_etagc(i)){
			return 0;
		}
	}
    int indice = (l>1 && c[0]=='"' && c[l-1]=='"');
    return indice;
}
