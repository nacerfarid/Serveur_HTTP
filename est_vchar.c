#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_vchar(char c) {
/*Retourne 1 si c est un caractère visible*/
/*char S[] = "vchar";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = (c - 0x21 >=0 && c - 0xF7 <= 0) ;
    return indice;
}
