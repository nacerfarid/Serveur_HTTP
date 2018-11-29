#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept_language(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "accept_language";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int deb, fin = 0;
    int virgule =0 ;

    while (fin<l && (c[fin] == ','  || c[fin] == ' ' || c[fin] == 9)) {
        fin++;
    }
    if (fin==l) {
        return 0;
    }
    /* on a passé ("," OWS) */
    deb = fin;
    if (c[fin] == '*') {
        fin++;
    }
    else {
        while (fin < l && c[fin] != ' ' && c[fin] != ',' && c[fin] != 9) {
            fin++;
        }
    }

    if (!est_language_range(c + sizeof(char) * deb,fin-deb,s,ls,callback)) {
        return 0;
    }

    if (fin == l) { /*Pas de weight ni de partie facult.*/
        return 1;
    }
    else { /*weight ou partie facultative*/
        deb = fin;
        while (fin < l && (c[fin] == ' ' || c[fin] == 9)) {
            fin++;
        }

        if (fin == l) {
            return 0;
        }

        /*on arrive soit au 1er carac de weight, soit au 1er carac de la partie facult., autre que OWS*/
        if (c[fin] != ',' && c[fin] != ';') {
            return 0;
        }

        if (c[fin] == ';') { /*on traite le weigth*/
            fin++;
            while (fin<l && c[fin] != 'q') {
                fin++;
            }

            if (fin==l) {
                return 0;
            }
            while (fin < l && c[fin] != ' ' && c[fin] != ',' && c[fin] != 9) {
                fin++;
            }


            if (!est_weight(c + sizeof(char) * deb,fin-deb,s,ls,callback)) {
                return 0;
            }
            if(fin == l) {
                return 1;
            }
            if(c[fin] == ',') {
                virgule = 1;
            }
        }
        if (c[fin] == ',') { /*on entame la partie facultative*/
            fin++;
            virgule = 1;
        }

        /*partie facultative*/
        while(fin<l) {
            while (fin<l && (c[fin] == ' ' || c[fin] == ',' || c[fin] == 9)) {
                if (c[fin] == ',') {
                    virgule = 1;
                }
                fin++;
            }
            if (fin == l) {
                return (c[l-1] != ' ' && c[l-1] != 9);
            }
            deb = fin;

            if (virgule == 0) {
                return 0;
            }
            else {
                virgule = 0;
            }

            while (fin < l && c[fin] != ' ' && c[fin] != ',' && c[fin] != ';' && c[fin] != 9) {
                fin++;
            }

            if (!est_language_range(c + sizeof(char)*deb,fin-deb,s,ls,callback)) {
                return 0;
            }
            if (fin == l) {
                return 1;
            }
            deb = fin;
            while (fin<l && (c[fin] == ' ' || c[fin] == 9)) {
                fin++;
            }
            if (fin == l) {
                return 0;
            }
            if (c[fin] != ',' && c[fin] != ';') {
                return 0;
            }
            if (c[fin] == ';') { /*si c'est une virgule, on reboucle au dessus*/
                deb = fin ; /*tant pis pour les ows qui devaient en toute rigueur etre dans weight*/
                while (fin < l && c[fin] != 'q') {
                    fin++;
                }
                if (fin==l) {
                    return 0;
                }
                while (fin < l && c[fin] != ' ' && c[fin] != ',' && c[fin] != 9) {
                    fin++;
                }

                if (!est_weight(c + sizeof(char) * deb,fin-deb,s,ls,callback)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


