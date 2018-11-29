#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_day_name(char *c, int l, char *s, int ls, void (*callback)()){
	char S[] = "day_name";
    int i_search = 0;
    if (ls == 8) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }


	if (l != 3) {
		return 0;
	}
	if (c[0] == 'S' && c[1] == 'u' && c[2] == 'n') {
		return 1;
	}
	if (c[0] == 'M' && c[1] == 'o' && c[2] == 'n') {
		return 1;
	}
	if (c[0] == 'T' && c[1] == 'u' && c[2] == 'e') {
		return 1;
	}
	if (c[0] == 'W' && c[1] == 'e' && c[2] == 'd') {
		return 1;
	}
	if (c[0] == 'T' && c[1] == 'h' && c[2] == 'u') {
		return 1;
	}
	if (c[0] == 'F' && c[1] == 'r' && c[2] == 'i') {
		return 1;
	}
	if (c[0] == 'S' && c[1] == 'a' && c[2] == 't') {
		return 1;
	}
	return 1;
}
