#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_transfer_parameter(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "transfer_parameter";
    int i_search = 0;
    if (ls == 18) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    if (l != 0 && c[0] == ' ') {
        return 0;
    }
    while (fin < l && !(c[fin] == ' ' || c[fin] == 9)) {
        fin ++;
    }
    if(!est_token(c , fin, s, ls, callback)){
        return 0;
    }
    deb = fin ;
    while (fin < l && (c[fin] == ' ' || c[fin] == 9) ) {
        fin ++;
    }
    if(c[fin] == '='){
        fin++;
    }
    deb = fin;
    while (fin < l && (c[fin] == ' ' || c[fin] == 9) ) {
        fin ++;
    }
    deb = fin;
    while (fin < l && c[fin] != '\0'){
        fin++;
    }
    if(!(est_token(c + sizeof(char)*deb,fin-deb, s, ls, callback)||est_quoted_string(c + sizeof(char)*deb,fin-deb, s, ls, callback))){
        return 0;
    }
    return 1;
}
