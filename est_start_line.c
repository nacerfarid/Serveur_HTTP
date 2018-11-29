#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_start_line(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un début de ligne */
	char S[] = "start_line";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int indice = (est_request_line(c, l, s, ls, callback) || est_status_line(c, l, s, ls, callback));
    return indice;
}
