#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_user_agent_header(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "user_agent_header";
    int i_search = 0;
    if (ls == 17) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    char test[] = "User-Agent:";
    int deb=0;
    int indice = 0;
    int esp= l - 1;

    if (l<=11){
        return(0);
    }
    while (deb<11){
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
    indice= est_user_agent(c + deb * sizeof(char),1+esp-deb, s, ls, callback);
    return(indice);
}
