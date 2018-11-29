#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_received_by(char *c, int l, char *s, int ls, void (*callback)()) {
	char S[] = "received_by";
    int i_search = 0;
    if (ls == 11) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
/*Retourne 1 si c, de longueur l, est un URI*/
    int h = 0; /* booleen de 'uri_host' est correct */
    int p_p = 0 ; /*présence du champs port*/
    int p = 0 ; /* p est correct*/
    int debut = 0;
    int fin = 0;

    while(fin<l && c[fin] == ':') {
        fin ++ ;
    }
    h = (est_uri_host(c + sizeof(char) , fin - debut, s, ls, callback)); /*on incrémente l'adresse considérée pour est_uri_host*/

    if (fin < l && c[fin] == '?') {
        p_p = 1;
        p = est_port(c + sizeof(char)*(fin+1), fin - debut - 1 , s, ls, callback) ;
    }

    return (h && ( (!p_p && !p) || (p_p && p)) || est_pseudonym(c, l, s, ls, callback)) ;
}
