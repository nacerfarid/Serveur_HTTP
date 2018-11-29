#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept_ext(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "accept_ext";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    if (fin == l || c[fin] != ';'){
        return 0;
    }
    fin++;
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    if (fin == l || c[fin] != 'q' || c[fin + 1] != '='){
        return 0;
    }
    fin =+ 2;
    deb = fin;
    while(fin<l && c[fin] == '='){
        fin++;
    }
    if (!est_token(c + sizeof(char)*deb,fin-deb, s, ls, callback)){
        return 0;
    }
    if (fin == l){
        return 1;
    }
    if (c[fin] != '='){
        return 0;
    }
    fin++;
    return (est_token(c + sizeof(char)*fin,l-fin, s, ls, callback) || est_quoted_string(c + sizeof(char)*fin,l-fin, s, ls, callback));
}
