#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_userinfo(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est une info sur l'utilisateur */
    char S[] = "userinfo";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    int deb = 0;
    while(deb<l) {
        while(deb<l && ( est_unreserved(c[deb]) || est_sub_delims(c[deb])  || c[deb] == ':' || c[deb] == '%')) {
            deb ++ ;
        }
        if (deb + 2 <l && c[deb] == '%') { /*Ce doit donc être un pct encoded*/
            if (!est_pct_encoded(c + deb * sizeof(char), 3, s, ls, callback)) { /*Ce n'est pas un pct encoded*/
                return 0;
            }
            else { /*C'est bien un pct encoded*/
                deb += 3;
            }
        }
        else { /* Ca n'est ni un pct encoded ni quoi que ce soit de juste*/
            return 0;
        }
    }
    return 1;
}
