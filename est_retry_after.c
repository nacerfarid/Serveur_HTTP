#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_retry_after(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un ressai après */
char S[] = "retry_after";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_http_date(c, l, s, ls, callback) || est_delay_seconds(c, l, s, ls, callback));
    return indice;
}
