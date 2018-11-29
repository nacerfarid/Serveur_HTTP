#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept_params(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "accept_params";
    int i_search = 0;
    int a, virgule;
    int b;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0;
    int fin = 0;

    while (fin<l && c[fin] != ';') {
        fin ++ ;
    }
    if(est_weight(c, fin, s, ls, callback)){
        a = 1;
    }
    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',')) {
            if (c[fin] == ',') {
                virgule = 1;
            }
            fin++;
        }
        if (fin < l) {
            if (virgule == 0) {
                return 0;
            }
            virgule = 0;
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
    if (fin == l || c[fin-1] != 'q' || c[fin] != '='){
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
    b = (est_token(c + sizeof(char)*fin,l-fin, s, ls, callback) || est_quoted_string(c + sizeof(char)*fin,l-fin, s, ls, callback));
    }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
    return a && b;
}
