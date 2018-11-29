#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_query(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un query*/
    char S[] = "query";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = 0 ;
	while (indice < l) {
	    while(indice < l && c[indice] != '/' && c[indice] != '?' && c[indice] != '%') {
	        indice ++ ;
	    }
	    if (l == indice) {
            return 1;
	    }
	    if (c[indice] == '%') {
	        if (indice +2 >= l || !est_pchar(c + indice * sizeof(char), 3, s, ls, callback) ) {
                printf("evalue : %c%c%c\n",c[indice],c[indice +1],c[indice +2]);
	            return 0;
	        }
	        indice += 3 ;
	    }
	    else {
	        if (!est_pchar(c + indice * sizeof(char), 1, s, ls, callback)) {
                printf("evalue2 : %c d'indice %d alors que l = %d\n",c[indice],indice, l);
	            return 0;
	        }
	        indice ++;
	    }
	}
	return 1;
}
