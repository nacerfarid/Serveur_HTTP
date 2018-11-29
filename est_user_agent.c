#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_user_agent(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est */
	char S[] = "user_agent";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb = 0, fin = 0;
    while (fin < l && (c[fin] != 9) && (c[fin] != ' ')) {
        fin ++;
    }

    if (!est_product(c, fin, s, ls, callback)) {
        return 0;
    }
    if (fin == l) {
        return 0;
    }
    while (fin<l) {
        if (c[fin] != ' ' && c[fin] != 9) {
            return 0;
        }
        if (c[fin] == ' ' || c[fin] == 9) {
            fin++;
        }
        deb = fin;
        if (fin<l && c[fin] == '(' ){
            int nb=1;
            fin++;
            while (nb>0 && fin<l) {
                if (c[fin]!='(' && c[fin]!=')' ){
                    fin++;
                }
                else {
                    if (c[fin]== '(') {
                        nb++;
                    }
                    else if (c[fin]==')') {
                        nb--;
                    }
                    fin++;
                }
            }
            if (nb==0){
                if( !est_comment(c+deb*sizeof(char), fin-deb, s, ls, callback)) {
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else {
            while (fin<l && c[fin] != ' ' && c[fin] != 9) {
                fin++;
            }
            if (!est_product(c + sizeof(char)*deb,fin-deb,s,ls,callback)) {
                return 0;
            }
        }
    }
    return 1;
}
