#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_t_ranking(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "t_ranking";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb,fin =0;
    while(fin<l && (c[fin] == 20 || c[fin] == 9)){
        fin++;
    }
    deb = fin;
    if (fin == l){
        return 0;
    }
    if(c[fin] == ';'){
        fin++;
    }
    deb = fin;
    while(fin<l && (c[fin] == 20 || c[fin] == 9)){
        fin++;
    }
    deb = fin;
    if (strcmp(c,"q=") == 0){
        fin++;
    }
    deb = fin;
    while(fin<l && c[fin] != '\0'){
        fin++;
    }
    if(!est_rank(c + sizeof(char)*deb,l-deb, s, ls, callback)){
        return 0;
    }
	return 1;
}
