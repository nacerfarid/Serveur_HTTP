#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_pragma_directive(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "pragma_directive";
    int i_search = 0;
    if (ls == 16) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }




    int i = ( (l = 8 && c[0] == 'n' && c[1] == 'o' && c[2] == '-' && c[3] == 'c' && c[4] == 'a' && c[5] == 'c' && c[6] == 'h' && c[7] == 'e') || (est_extension_pragma(c,l, s, ls, callback)) );
    return i;
}
