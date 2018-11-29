#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_received_protocol(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "received_protocol";
    int i_search = 0;
    if (ls == 17) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int fin = 0;


    while (fin<l && c[fin]!= '/') {
	fin ++;
	}
if(fin<l){
return (est_protocol_name(c,fin, s, ls, callback) && est_protocol_version(c + sizeof(char)*(fin + 1), l-fin - 1, s, ls, callback));
}
}
