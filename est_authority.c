#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_authority(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un 'authority' */
    char S[] = "authority";
    int i_search = 0;
    if (ls == 9) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int u = 0, h, p = 0 ;
    int u_p = 0, p_p = 0;
    int deb, fin = 0 ;
    int p_ok, u_ok ;
    int test_deux_p = 1; /*Faux s'il n'y a plus de :*/
    int i_test_dp ;
    while(fin<l && c[fin] != '@' && !test_deux_p) { /*Il peut y avoir des ':' dans le host*/
        test_deux_p = 0;
        for(i_test_dp = fin; i_test_dp < l;i_test_dp++) {
            if (c[i_test_dp] == ':') {
                test_deux_p = 1;
            }
        }
        fin ++ ;
    }
    if (fin<l && c[fin] == '@') { /*Cas userinfo présent*/
        u_p = 1;
        u = est_userinfo(c, fin, s, ls, callback);
        fin ++ ;
        deb = fin ;
        while(fin<l && c[fin] != ':') {
            fin ++ ;
        }
        if (fin<l && c[fin] == ':') { /*Cas port présent*/
            p_p = 1;
            h = est_host(c + sizeof(char) * deb, fin - deb, s, ls, callback) ;
            fin ++ ;
            deb = fin ;
            p = est_port(c + sizeof(char) * deb, l - deb, s, ls, callback);
        }
        else {                      /* Cas pas de port présent */
            h = est_host(c + sizeof(char) * deb, l - deb, s, ls, callback) ;
        }
    }
    else { /*Cas pas de userinfo présent*/
        if (fin<l && c[fin] == ':') {/*Cas port présent*/
            p_p = 1;
            h = est_host(c, fin, s, ls, callback);
            fin ++;
            p = est_port(c + sizeof(char) * fin, l - fin, s, ls, callback);
        }
        else { /*Cas pas de port présent*/
            h = est_host(c, l, s, ls, callback);
        }
    }
    p_ok = (p_p == 0 && p == 0) || (p_p == 1 && p == 1);
    u_ok = (u_p == 0 && u == 0) || (u_p == 1 && u == 1);
    return (h && p_ok && u_ok) ;
}
