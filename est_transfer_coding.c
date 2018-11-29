#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_transfer_coding(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un  */
	char S[] = "transfer_coding";
    int i_search = 0;
    if (ls == 15) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	int i1=0,i2=0,i3=0,i4=0,i5=0;
i1 = (l == 7 && c[0]=='c' && c[1]=='h' && c[2]=='u' && c[3]=='n' && c[4] == 'k' && c[5] == 'e' && c[6] == 'd');
i2 = (l == 8 && c[0]=='c' && c[1]=='o' && c[2]=='m' && c[3]=='p' && c[4] == 'r' && c[5] == 'e' && c[6] == 's' && c[7] == 's');
i3 = (l == 7 && c[0]=='d' && c[1]=='e' && c[2]=='f' && c[3]=='l' && c[4] == 'a' && c[5] == 't' && c[6] == 'e');
i4 = (l == 4 && c[0]=='g' && c[1]=='z' && c[2]=='i' && c[3]=='p');
i5 = est_transfer_extension(c,l, s, ls, callback);
    int indice = i1 || i2 || i3 || i4 || i5;
    return indice;
}
