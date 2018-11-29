#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_crlf(char *c, int l, char *s, int ls, void (*callback)()){
    char S[] = "crlf";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if(l != 2 || c[0] != 0x0D || c[1] != 0x0A){
        return 0;
    }
    return 1;
}
