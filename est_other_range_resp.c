#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_other_range_resp(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un autre 'range resp' */
	char S[] = "other_range_resp";
    int i_search = 0;
    if (ls == 16) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = 0;
    while (i<l) {
        if (!est_char(i)) {
            return 0;
        }
        i++;
    }
    return 1;
}
