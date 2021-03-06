#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_message_body(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un corps de message*/
    char S[] = "message_body";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    return (1);
}
