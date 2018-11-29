#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_if_range_header(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "if_range_header";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    char test[] = "If-Range:";
    int deb=0;
    int indice = 0;
    int esp= l - 1;

    if (l<=9){
        return(0);
    }
    while (deb<9){
        if ( test[deb] != c[deb]){
            return(0);
        }
        deb++;
    }

    while (deb<l && (c[deb] == ' ' || c[deb] == 9)){
        deb++;
    }
    if (deb==l) {
        return 0;
    }

    while (esp>deb && (c[esp] == ' ' || c[esp] == 9)){
        esp--;
    }
    indice= est_if_range(c + deb * sizeof(char),1 + esp-deb, s, ls, callback);
    return(indice);
}
