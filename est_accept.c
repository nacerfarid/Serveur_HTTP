#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_accept(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "accept";
    int i_search = 0;
    if (ls == 6) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int iii = 0;
    int med_tr = 0;
    int deb = 0, fin = 0;
    int virg1 = 0, virg2 = 0; /*on cherchera dans l'algo des virgules*/
    int pvg = 0, pvg2 = 0; /*des points-virgules*/
    int rec_virg = 1; /*Recherche de virgule activée / elle sera désactivé si on est dans un quote-string*/
    if (l==0) {
        return 1;
    }
    while (virg2<l) {
        /*RECHERCHE ENTRE 2 VIRGULES*/
        while (virg2<l && !(c[virg2] == ',' && rec_virg == 1)) {
            if (c[virg2] == '"' && rec_virg == 1) {
                rec_virg = 0;
            }
            else if (c[virg2] == '"' && rec_virg == 0) {
                rec_virg = 1;
            }
            virg2++;
        }
        pvg = virg1;
        pvg2 = virg1;
        int correctif = 0;
        int correct2 = 0;
        if (virg1 == 0) {
            deb = virg1;
        }
        else { /* le deb de media_range*/
            deb = virg1+1;
        }
        while (pvg2 < virg2 && med_tr == 0) {
            while (pvg2 < virg2 && c[pvg2] != ';') {
                pvg2++;
            }
            if (!est_weight(c+sizeof(char)*pvg,pvg2-pvg,s,ls,callback)) {
                pvg = pvg2;
                if (pvg2 != virg2) {
                    pvg2++;
                }
                correctif = 1;
            }
            else {
                fin = pvg;
                med_tr = 1;
            }
        }
        if (pvg2 == virg2) {
            fin = virg2;
        }
        if (!est_media_range(c+sizeof(char)*deb,fin-deb,s,ls,callback)) {
            return 0;
        }
        if (fin != virg2) {
            if (!est_accept_params(c+sizeof(char)*fin,virg2-fin,s,ls,callback)) {
                return 0;
            }
        }
        virg1 = virg2;
        virg2++;
        med_tr = 0;
        }
    return 1;
}
