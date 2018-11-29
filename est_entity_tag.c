#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_entity_tag(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est  */
	char S[] = "entity_tag";
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
    int b1,b2,b3,b4;
    char car;
    if (c[0]==0x5B){
        while (fin<l && c[fin]!=0x5D){
          fin++;
        }
        b1=est_weak(c,l,s,ls,callback);
        while (fin<l && c[fin]!=0x20){
          fin++;
        }
        b2=est_opaque_tag(c,l, s, ls, callback);

        b3=b1 && b2;

    }
    else{
        while (fin<l){
            fin++;
        }
        b4=est_opaque_tag(c,l, s, ls, callback);
    }
    return b3 || b4;

}
