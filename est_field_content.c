#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_field_content(char *c, int l, char *s, int ls, void(*callback)()) {
/*Retourne 1 si c, de longueur l, est un contenu de champ */
    char S[] = "field_content";
    int i_search = 0;
    if (ls == 13) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    int space = 1; /*pour s'assurer qu'il n'y ait pas d'espace à la fin du field content*/
    int f = 0; /*f = 1 si tous les field vchar sont corrects et s'il y en a au moins 1*/
    while (fin < l && c[fin] != ' ') {
        fin ++;
    }
    f = est_field_vchar(c, fin,s,ls,callback);
    while (fin < l) {
        while(fin < l && c[fin] == ' ') {
            space = 0;
            fin ++;
        }
        deb = fin ;
        while(fin < l && c[fin] != ' ') {
            space = 1;
            fin ++;
        }
        f = f && est_field_vchar(c + deb * sizeof(char), fin - deb, s, ls, callback);
    }
    return (f && space);
}
