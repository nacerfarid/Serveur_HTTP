#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_chunk_ext(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "chunk_ext";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int deb=0, fin=0 , k=1;


    if (l==0 ){
        return 1;
    }

    if (c[0]!=';' || l<2){
        return 0;
    }

    if (c[l-1]==';' ||c[l-1]=='=') {
        return 0;
    }

    while (fin<l) {
        deb=fin;
        fin++;
        while (fin<l && fin!=';' && fin!='=') {
            fin++;
        }
        k= k && (est_chunk_ext_name(c+(deb+1)*sizeof(char), fin-deb-1, s, ls, callback) || est_chunk_ext_val(c+(deb+1)*sizeof(char), fin-deb-1, s, ls, callback) );
    }

    return k;
}
