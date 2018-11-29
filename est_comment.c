#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_comment(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "comment";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int nb = 0;
    int deb=0, fin=0, k = 1;
    if (l<2){
        return(0);
    }
    if (c[0]!='(' && c[l-1]!=')') {
        return(0);
    }

    fin = 1;
    while (fin<l-1) {
        if (c[fin]!='(' && c[fin]!=')' ){
            if (!est_ctext(c[fin])) {
                if (fin+1 >= l-1) {
                    return 0;
                }
                if (!est_quoted_pair(c + sizeof(char) * fin,2,s,ls,callback)) {
                    return 0;
                }
                else {
                    fin++; /*On doit incrémenter de 2, mais le fin++ plus bas complète*/
                }
            }
        }
        else {
            if (c[fin]== '(' && nb==0) {
                deb=fin;
                nb++;
            }
            else if (c[fin]=='(' && nb>0){
                nb++;
            }
            else if (c[fin]==')') {
                nb--;
                if (nb<0) {
                    return 0;
                }
                if (nb =0){
                    k=(k && est_comment (c+deb*sizeof(char), fin-deb+1, s, ls, callback) );
                }
            }
        }
        fin++;
    }
    return k;
}
