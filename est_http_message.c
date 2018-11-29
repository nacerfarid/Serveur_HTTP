#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_http_message(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un message http */
    char S[] = "http_message";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int deb, fin = 0;
    int k, m, m_p, h = 0;
    int sortie_header = 0;
    int extend = 0; /*Utilisé dans le cas d'un header-field sur plusieurs lignes*/
    h = 1; /*A priori, pas nécéssairement de header*/

    while (fin < l && c[fin] != 10) {
        fin++;
    }
    if (fin == l) {
        return 0;
    }
    if (c[fin-1] != 13) {
        return 0;
    }
    fin++;
    if (!est_start_line(c, fin, s,ls,callback)) {
        return 0;
    }
    if (fin+2>=l) {
        return 0;
    }
    if (c[fin+1] == 13 && c[fin+2] == 10) {
        if (fin+3 == l) {/*Pas de messaage body*/
            return 1;
        }
        else {
            return est_message_body(c + sizeof(char) * (fin+3),l,s,ls,callback);
        }
    }



    while (fin <l) {
        if (!extend) { /*On considère plusieurs lignes si jamais ...*/
            deb = fin;
        }
        while (fin <l && c[fin] != 10) {
            fin++;
        }
        if (fin == l) {
            return 0;
        }
        if (c[fin-1] != 13) {
            return 0;
        }

        if (fin+2 >= l) {
            return 0;
        }

        else if (c[fin+1] == ' ' || c[fin+1] == 9) {
            extend = 1;
        }
        else if (c[fin+1] == 13 && c[fin+2] == 10) {
            if (!est_header_field(c+sizeof(char)*deb,(fin-1)-deb,s,ls,callback)) {
                return 0;
            }
            return est_message_body(c+sizeof(char)*(fin+3),l-(fin+3),s,ls,callback);
        }
        else {
            extend = 0;
            if (!est_header_field(c+sizeof(char)*deb,(fin-1)-deb,s,ls,callback)) {
                return 0;
            }

        }
        fin++;

    }
    return 2; /*A priori on ne devrai jamais être ici*/
}
