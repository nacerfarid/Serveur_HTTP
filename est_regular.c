#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_regular(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un régulier*/
    char S[] = "regular";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    if (l == 6) {

        if (c[0] == 'n' && c[1] == 'o' && c[2] == '-' && c[3] == 'b' && c[4] == 'o' && c[5] == 'k') {
            return 1;
        }
        if (c[0] == 'n' && c[1] == 'o' && c[2] == '-' && c[3] == 'n' && c[4] == 'y' && c[5] == 'n') {
            return 1;
        }
        if (c[0] == 'z' && c[1] == 'h' && c[2] == '-' && c[3] == 'm' && c[4] == 'i' && c[5] == 'n') {
            return 1;
        }
        return 0;
    }

    if (l == 8) {
        if (c[0] == 'z' && c[1] == 'h' && c[2] == '-' && c[3] == 'g' && c[4] == 'u' && c[5] == 'o' && c[6] == 'y' && c[7] == 'u') {
            return 1;
        }
        if (c[0] == 'z' && c[1] == 'h' && c[2] == '-' && c[3] == 'h' && c[4] == 'a' && c[5] == 'k' && c[6] == 'k' && c[7] == 'a') {
            return 1;
        }
        if (c[0] == 'z' && c[1] == 'h' && c[2] == '-' && c[3] == 'x' && c[4] == 'i' && c[5] == 'a' && c[6] == 'n' && c[7] == 'g') {
            return 1;
        }
        return 0;
    }
    if (l == 10) {
        if (c[0] == 'a' && c[1] == 'r' && c[2] == 't' && c[3] == '-' && c[4] == 'l' && c[5] == 'o' && c[6] == 'j' && c[7] == 'b' && c[8] == 'a' && c[9] == 'n') {
            return 1;
        }
        if (c[0] == 'z' && c[1] == 'h' && c[2] == '-' && c[3] == 'm' && c[4] == 'i' && c[5] == 'n' && c[6] == '-' && c[7] == 'n' && c[8] == 'a' && c[9] == 'n') {
            return 1;
        }
        return 0;
    }
    if (l == 11) {
        return (c[0] == 'c' && c[1] == 'e' && c[2] == 'l' && c[3] == '-' && c[4] == 'g' && c[5] == 'a' && c[6] == 'u' && c[7] == 'l' && c[8] == 'i' && c[9] == 'n') ;
    }
    return 1;
}
