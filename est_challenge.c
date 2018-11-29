#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_challenge(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un défi*/
    char S[] = "challenge";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin, virgule = 0 ;
    int test = 1 ; /*Au moins une virgule entre 2 t-codings*/


    while (fin < l && c[fin] != ' ') {
        fin ++;
    }
    if (!est_auth_scheme(c, fin, s, ls, callback)) {
        return 0;

    }
    if (fin == l) {
        return 1;
    }
    while (fin < l && c[fin] == ' ') {
        fin++;
    }
    if (fin == l) {
        return 1; /*Si c'est bel et bien possible */ /*SInon, c'est 0*/
    }
    deb = fin;
    if (est_token68(c + sizeof(char) * deb, l - deb, s, ls, callback)) { /*On a token68*/
        return 1;
    }

    /*On a ("," / auth-param )*( OWS ","[ OWS auth-param ]) */


    if (l != c[fin] && c[fin] == ',') {
        fin ++ ;
    }

    else {
        while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ',') {
            if (c[fin] == ',') {
                virgule = 1;
            }
            fin ++;
        }
        if (!est_auth_param(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
            return 0;
        }
    }

    deb = fin ; /*On est sorti de ","/auth_param */

    if (fin == l) {
        return 1;
    }

    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',')) {
            if (c[fin] == ',') {
                virgule = 1;
            }
            fin++;
        }
        if (fin < l) { /*Il y a un auth-param*/
            if (virgule == 0) {
                return 0;
            }
            virgule = 0;


            deb = fin;
            while (fin <l && c[fin] != ' ' && c[fin] == 9 && c[fin] != ',') {
                fin ++;
            }
            if (!est_t_codings(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
                return 0;
            }
        }
    }
    return (c[l - 1] != ' ' && c[l - 1] != 9);
}
