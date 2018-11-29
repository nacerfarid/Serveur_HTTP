#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_irregular(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un irrégulier*/
char S[] = "irregular";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    if (l == 5) {
        if (c[0] =! 'i' || c[0] != '-'){
            return 0;
        }

        if (c[2] == 'a' && c[3] == 'm' && c[4] == 'i') {
            return 1;
        }
        if (c[2] == 'b' && c[3] == 'n' && c[4] == 'n') {
            return 1;
        }
        if (c[2] == 'h' && c[3] == 'a' && c[4] == 'k') {
            return 1;
        }
        if (c[2] == 'l' && c[3] == 'u' && c[4] == 'x') {
            return 1;
        }
        if (c[2] == 'p' && c[3] == 'w' && c[4] == 'n') {
            return 1;
        }
        if (c[2] == 't' && c[3] == 'a' && c[4] == 'o') {
            return 1;
        }
        if (c[2] == 't' && c[3] == 'a' && c[4] == 'y') {
            return 1;
        }
        if (c[2] == 't' && c[3] == 's' && c[4] == 'u') {
            return 1;
        }
        return 0;
    }
    if (l == 7) {
        return (c[0] == 'i' && c[1] == '-' && c[2] == 'm' && c[3] == 'i' && c[4] == 'n' && c[5] == 'g' && c[6] == 'o');
    }
    if (l == 8) {
        return (c[0] == 'i' && c[1] == '-' && c[2] == 'n' && c[3] == 'a' && c[4] == 'v' && c[5] == 'a' && c[6] == 'j' && c[7] == 'o');
    }
    if (l == 9) {
        if (c[0] == 'e' && c[1] == 'n' && c[2] == '-' && c[3] == 'G' && c[4] == 'B' && c[5] == '-' && c[6] == 'o' && c[7] == 'e' && c[8] == 'd') {
            return 1;
        }
        if (c[0] == 'i' && c[1] == '-' && c[2] == 'k' && c[3] == 'l' && c[4] == 'i' && c[5] == 'n' && c[6] == 'g' && c[7] == 'o' && c[8] == 'n') {
            return 1;
        }
        if (c[0] == 'i' && c[1] == '-' && c[2] == 'd' && c[3] == 'e' && c[4] == 'f' && c[5] == 'a' && c[6] == 'u' && c[7] == 'l' && c[8] == 't') {
            return 1;
        }
        if (c[0] == 'e' && c[1] == 'n' && c[2] == '-' && c[3] == 'G' && c[4] == 'B' && c[5] == '-' && c[6] == 'o' && c[7] == 'e' && c[8] == 'd') {
            return 1;
        }
        if (c[0] == 's' && c[1] == 'g' && c[2] == 'n' && c[3] == '-' && c[4] == 'B' && c[5] == 'E' && c[6] == '-' && c[7] == 'F' && c[8] == 'R') {
            return 1;
        }
        if (c[0] == 's' && c[1] == 'g' && c[2] == 'n' && c[3] == '-' && c[4] == 'B' && c[5] == 'E' && c[6] == '-' && c[7] == 'N' && c[8] == 'L') {
            return 1;
        }
        if (c[0] == 's' && c[1] == 'g' && c[2] == 'n' && c[3] == '-' && c[4] == 'C' && c[5] == 'H' && c[6] == '-' && c[7] == 'D' && c[8] == 'E') {
            return 1;
        }
        return 0;
    }
    if (l == 10) {
        return (c[0] == 'i' && c[1] == '-' && c[2] == 'e' && c[3] == 'n' && c[4] == 'o' && c[5] == 'c' && c[6] == 'h' && c[7] == 'i' && c[8] == 'a' && c[9] == 'n') ;
    }
    return 0;
}
