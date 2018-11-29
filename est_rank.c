#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_rank(char *c, int l, char *s, int ls, void (*callback)()){
	char S[] = "rank";
    int i_search = 0;
    if (ls == 4) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int i;

    if (l == 0 || (c[0]!= '0' && c[0]!= '1')){
        return 0;
    }

    if (c[0]== '0'){

        if (l == 1) { /*c = '0' */
            return 1;
        }
        if (c[1] != '.') {
            return 0;
        }
        if (l - 2 > 3) /*Plus de 3 digits*/ {
            return 0;
        }
        i = 2 ;
        while (i < l) {
            if (!est_digit(c[i])) {
                return 0;
            }
        i++;
        }
    return 1;
    }


    if (c[0] == '1') {


        if (l == 1) {
            return 1;
        }
        if (c[1] != '.') {
            return 0;
        }
        if (l - 2 > 3) /*Plus de 3 digits*/ {
            return 0;
        }
        i = 2 ;
        while (i < l) {
            if (c[i] != '0') {
                return 0;
            }
            i++;
        }
        return 1;
    }
}
