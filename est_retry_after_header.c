#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_retry_after_header(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "retry_after_header";
    int i_search = 0;
    if (ls == 18) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    char test[] = "Retry-after:";
    int deb=0;
    int indice = 0;
    int esp= l - 1;

    if (l<=12){
        return(0);
    }
    while (deb<12){
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
    indice= est_retry_after(c + deb * sizeof(char),1 + esp-deb, s, ls, callback);
    return(indice);
}
