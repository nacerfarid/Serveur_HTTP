#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept_encoding_header(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "accept_encoding_header";
    int i_search = 0;
    if (ls == 22) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    char test[] = "Accept-Encoding:";
    int deb=0;
    int indice = 0;
    int esp= l - 1;

    if (l<=16){
        return(0);
    }
    while (deb<16){
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
    indice = est_accept_encoding(c + sizeof(char)*deb,1+esp-deb,s,ls,callback);
    return(indice);
}
