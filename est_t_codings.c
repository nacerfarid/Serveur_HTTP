#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_t_codings(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "t_codings";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int deb = 0;
    int fin = 0;
    if(l == 8 && strcmp(c,"trailers") == 0){
        return 1;
    }
    while(fin<l && c[fin] != ' '){
        fin++;
    }
    if(!est_transfer_coding(c,fin, s, ls, callback)){
		return 0;
	}
    deb = fin;
    if(fin == l){
        return 0;
    }
    while(fin<l && c[fin] != '\0'){
        fin++;
    }
    if(!est_t_ranking(c + sizeof(char)*deb,fin-deb, s, ls, callback)){
		return 0;
	}
    return 1;
}
