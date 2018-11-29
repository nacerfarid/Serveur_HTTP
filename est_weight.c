#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_weight(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "weight";
    int i_search;
	i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb,fin;
	deb =0;fin = 0;
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    if (fin == l){
        return 0;
    }
    if(c[fin] != ';'){
        return 0;
    }
    fin++;
    while(fin<l && (c[fin] == ' ' || c[fin] == 9)){
        fin++;
    }
    if (fin==l) {
        return 0;
    }

    if (fin+2 >= l || c[fin] != 'q' || c[fin+1] != '='){
        return 0;
    }
    fin+=2;



    if(!est_qvalue(c + sizeof(char)*fin,l-fin, s, ls, callback)){
        return 0;
    }
	return 1;
}
