#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_via(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "via";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int deb=0,fin=0;
    int k, j, i =0;
    int h=1;
    if (c[deb]==','){
        while (deb < l && (c[deb] == ' ' || c[deb] == 9 || c[deb] == ',') ) {
        deb ++;
        }
    }

    fin = deb ;
    while (fin < l && c[fin] != ' ' && c[fin] != 9) {               /* on compte est received protocol */
        fin++;
    }
    k= est_received_protocol(c + sizeof(char) * deb, fin - deb, s, ls, callback) ;



     while (fin < l && (c[fin] == ' ' || c[fin] == 9 ) ) {              /* on compte des espaces*/
        fin ++;
    }
    deb=fin;

    while (fin < l && c[fin] != ' ' && c[fin] != 9) {               /* on compte est received by */
        fin++;
    }
    j= est_received_by(c + sizeof(char) * deb, fin - deb, s, ls, callback) ;


    /* 1ere partie faite */



     while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == '(' ) ) {              /* on compte des espaces*/
        fin ++;
    }
    deb=fin;

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
            h=est_comment (c+deb*sizeof(char), fin-deb, s, ls, callback);
        }
        else{
            return 0;
        }
    }

    if (fin==l){
        return (h && j && k);
    }

    while (fin < l && (c[fin] == ' ' || c[fin] == 9 ) ) {              /* on compte des espaces*/
        fin ++;
    }
    deb=fin;

    if (fin==l || (fin=l-1 && c[fin]!=',') ){
        return 0;
    }

    if (fin=l-1 && c[fin]==',') {
        return (h && j && k);
    }


    i= est_via (c+fin*sizeof(char), l-fin, s, ls, callback);

    return (i && j && k && h);
}



