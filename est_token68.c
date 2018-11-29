#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_token68 (char*c, int l, char *s, int ls, void (*callback)()){
    char S[] = "token68";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice=1;
    int i=0;
    int k=0;
    if (l == 0 ) {
        indice = 0;
    }
        else {
            while( i<l && indice ==1 ) {
                indice = (est_alpha(c[i]) || est_digit(c[i]) || c[i] == '-' || c[i] == '.' || c[i] == '_' || c[i] == '~' || c[i] =='+' || c[i] == '/' );
            }
            if(k<i && c[k]=='='){
                k++;
            }
        }



    return indice;

}
