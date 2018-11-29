#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_chunked_body(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "chunked_body";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


    int deb=0,fin=0;
    int sc=0;           /* nb de CRLF (il en faut 2 pour vérifier est_chunk) */
    int rep=1;
    int x=0;            /*passe a 1 quand on a trouvé est_last_chunk */

    while (fin<l && x==0) {
        while (fin<l && fin != 0xD) {
            fin++;
        }
        if (fin==l){
            return(0);
        }


        if (fin!=l && c[fin+1]== 0xA) {                                     /*si on trouve CRLF */
            sc++;
            if ( est_last_chunk (c+deb*sizeof(char),fin-deb+1, s, ls, callback) && sc==1 ) {         /*test si est_last_chunk => arrete la boucle */
                x=1;
                deb=fin+1;
            }
            else if (sc==2) {                                                /* sinon si modulo 2 CRLF => test est_chunk */
                rep=rep && est_chunk(c+deb*sizeof(char),fin-deb+1, s, ls, callback) ;
                sc=0;
                deb=fin+1;
            }
        }
    }
    /* donc la on a testé last_chunk et chunk */

    if (deb+2>=l || c[l-1]!=0xA || c[l-2]!=0xD) {
        return 0;
    }
    int d = est_chunk_data(c+(deb+1)*sizeof(char),l-deb, s, ls, callback);
    return(d && rep);
}
