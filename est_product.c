#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_product(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "product";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb =0, fin = 0;
    int virgule ;
    while (fin < l && c[fin] != '/' ) {
        fin ++;
    }
    if (!(est_token(c, fin, s, ls, callback))) {
        return 0;
    }
    if (fin == l){
    return 1;
    }
    if (c[fin] != '/'){
    return 0;
    }
    if(!est_product_version(c + sizeof(char) * (fin+1), l - (fin+1), s, ls, callback)){
    return 0;
    }
    return 1;
}
