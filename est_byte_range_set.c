#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_byte_range_set(char *c, int l, char *s, int ls, void (*callback)()) {
    int deb = 0;
    int fin = 0;
	char S[] = "byte_range_set";
    int i_search = 0;
    if (ls == 14) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    if (l == 0){
        return 1;
    }
    if(c[0] != ','){
        return 0;
    }
    fin++;
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    return est_byte_range_spec(c + sizeof(char)*deb,fin-deb, s, ls, callback) || est_suffix_byte_range_spec(c + sizeof(char)*deb,fin-deb, s, ls, callback);
    if (fin == l){
        return 0;
    }
    deb = fin;
    while(fin<l && c[fin] == ' '){
        fin++;
    }
    if (c[fin + 1] != ','){
        return 0;
    }
    if (fin == l){
        return 0;
    }

    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    if (fin == l || c[fin] != ','){
        return 0;
    }
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    fin++;
    if (c[fin] != '='){
        return 0;
    }
    fin++;
    return est_byte_range_spec(c + sizeof(char)*deb,fin-deb, s, ls, callback) || est_suffix_byte_range_spec(c + sizeof(char)*deb,fin-deb, s, ls, callback);
}
