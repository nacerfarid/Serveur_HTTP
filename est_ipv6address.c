#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_ipv6address(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une adresse ipv6*/
    char S[] = "ipv6address";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0 ;
    int b1 = 1, b2 = 1, b3 = 1, b4 = 1, b5 = 1, b6 = 1, b7 = 1, b8 = 1, b9 = 1 ;
    int compteur = 0 ;
    int compteur2 = 0;

    /*#####*/
    /*Cas 1*/
    /*#####*/

    while (fin < l && compteur < 6) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s, ls, callback)) {
            b1 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 6) {
        b1 = 0;
    }

    b1 = b1 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 2*/
    /*#####*/

    deb = 2; fin = 2;
    compteur = 0;

    if (l<2 || c[0] != ':' || c[1] != ':') {
        b2 = 0;
    }

    while (fin < l && compteur < 5) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
            b2 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 5) {
        b2 = 0;
    }

    b2 = b2 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 3*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0;
    if (l != 0 && c[0] != ':') { /*Il y a h16 au début*/
        if (l != 1 || c[1] != ':') {
            b3 = 0;
        }
        fin = 2;
        deb = 2;
        while (fin +1 <l && !(c[fin] == ':' && c[fin +1] == ':')) {
            fin++;
        }
        if (!est_h16(c, fin, s ,ls ,callback)) {
            b3 = 0;
        }
        fin += 2;
    }
    else { /*Pas de h16*/
        if (!(c[0] == ':' && c[1] == ':')) {
            b3 = 0;
        }
        fin += 2;
    }

    deb = fin;

    while (fin < l && compteur < 4) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
            b3 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 4) {
        b3 = 0;
    }

    b3 = b3 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 4*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<2) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b4 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b4 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/
    while (fin < l && compteur < 3) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
            b4 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 3) {
        b4 = 0;
    }

    b4 = b4 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 5*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<3) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b5 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b5 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/

    while (fin < l && compteur < 2) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
            b5 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 2) {
        b5 = 0;
    }

    b5 = b5 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 6*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<4) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b6 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b6 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/

    while (fin < l && compteur < 1) {
        while (fin < l && c[fin] != ':') {
            fin++ ;
        }
        if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
            b6 = 0;
        }
        fin ++;
        deb = fin;
        compteur ++;
    }

    if (compteur != 1) {
        b6 = 0;
    }

    b6 = b6 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 7*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<5) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b7 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b7 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/

    b7 = b7 && est_ls32(c + fin * sizeof(char), l - fin, s ,ls ,callback);

    /*#####*/
    /*Cas 8*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<6) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b8 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b8 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/

    b8 = b8 && est_h16(c + fin * sizeof(char), l - fin, s ,ls ,callback);


    /*#####*/
    /*Cas 9*/
    /*#####*/

    deb = 0; fin = 0;
    compteur = 0; compteur2 = 0;

    if(l > 3 && c[fin] != ':') { /*Cas facultatif*/
        while (fin<l && c[fin] != ':' && compteur2<5) { /*Pas besoin de vérifier qu'il y a au moins un h16 dans le crochet...c'est necessairement le cas*/
                                                        /*On compte ici le h16 dans le [] */
            while(fin < l && c[fin] != ':') {
                fin ++;
            }
            if (fin == l || !est_h16(c + deb * sizeof(char), fin - deb, s ,ls ,callback)) {
                b9 = 0;
            }
            fin ++;
            deb = fin ;
        }
    }
    else {
        fin++;
    }
    if (fin >= l || c[fin] != ':') {/*Que l'on ait pas eu de h16, 1 ou 2, il faut que l'on ait ::*/
        b9 = 0;
    }
    fin++;
    deb = fin;

    /*On entame la derniere partie :*/

    b9 = b9 && (fin == l);


    /*#####*/
    /*Conc.*/
    /*#####*/

    return(b1 || b2 || b3 || b4 || b5 || b6 || b7 || b8 || b9);
}
