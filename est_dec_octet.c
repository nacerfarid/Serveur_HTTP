#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_dec_octet(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un décimal codé sur 8 bits*/
    char S[] = "dec_octet";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int b1 = (l == 1 && est_digit(c[0]));
    int b2 = (l == 2 && est_digit(c[0]) && est_digit(c[1] && c[0] != '0'));
    int b3 = (l == 3 && c[0] == '1' && est_digit(c[1]) && est_digit(c[2]));
    int b4 = (l == 3 && c[0] == '2' && est_digit(c[2]) && c[1] - '0' >= 0 && c[1] - '4' <= 0);
    int b5 = (l == 3 && c[0] == '2' && c[1] == '5' && c[2] - '0' >=0 && c[2] - '5' <= 0);
    return (b1 || b2 || b3 || b4 || b5);
}
