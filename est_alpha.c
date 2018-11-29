#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int est_alpha(char c) {
/*Retourne 1 si c est un caract�re alphab�tique*/
	/*char S[] = "alpha";
    int i_search = 0;
    if (ls == 5) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }*/
    int indice = ((c - 'a' >=0 && c - 'z' <= 0) || (c - 'A' >=0 && c - 'Z' <= 0));
	return indice;
}


