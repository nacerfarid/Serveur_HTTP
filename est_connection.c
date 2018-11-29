#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_connection(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une connexion */
char S[] = "connection";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    int virgule ;
    if (l != 0 && c[0] == ' ') {
        return 0;
    }
    while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',') ) {
        fin ++;
    }
    deb = fin;
    while (fin < l && c[fin] != ' ' && c[fin] != 9 && c[fin] != ',') {
        fin++;
    }
    if (!est_connection_option(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
        return 0;
    }
    fin ++;
    deb = fin;
    /*Au moins 1 virgule entre 2 connection-option*/
    virgule = 0;
    while (fin <l) {
        while (fin < l && (c[fin] == ' ' || c[fin] == 9 || c[fin] == ',')) {
            if (c[fin] == ',') {
                virgule = 1;
            }
            fin++;
        }
        if (fin < l) { /*Il y a un connection-option*/
            if (virgule == 0) {
                return 0;
            }
            virgule = 0;


            deb = fin;
            while (fin <l && c[fin] != ' ' && c[fin] == 9 && c[fin] != ',') {
                fin ++;
            }
            if (!est_connection_option(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
                return 0;
            }
        }
    }
    return (c[l - 1] != ' '); /*Pas d'espace autorisé à la fin*/
}
