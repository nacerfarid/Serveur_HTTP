#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_last_byte_pos(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "last_byte_pos";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int i = est_complete_length(c, l, s, ls, callback);
    return i;
}
