#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_day_name_l(char *c, int l, char *s, int ls, void (*callback)()){
		char S[] = "day_name_l";
    int i_search = 0;
    if (ls == 10) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
	if (l<6 || l>9) {
		return 0;
	}
	if (c[0] == 'S' && c[1] == 'u' && c[2] == 'n' && c[3] == 'd' && c[4] == 'a' && c[5] == 'y') {
		return 1;
	}
	if (c[0] == 'M' && c[1] == 'o' && c[2] == 'n' && c[3] == 'd' && c[4] == 'a' && c[5] == 'y') {
		return 1;
	}
	if (c[0] == 'T' && c[1] == 'u' && c[2] == 'e' && c[3] == 's' && c[4] == 'd' && c[5] == 'a' && c[6] == 'y') {
		return 1;
	}
	if (c[0] == 'W' && c[1] == 'e' && c[2] == 'd' && c[3] == 'n' && c[4] == 'e' && c[5] == 's' && c[6] == 'd' && c[7] == 'a' && c[8] == 'y') {
		return 1;
	}
	if (c[0] == 'T' && c[1] == 'h' && c[2] == 'u' && c[3] == 'r' && c[4] == 's' && c[4] == 'd' && c[5] == 'a' && c[6] == 'y') {
		return 1;
	}
	if (c[0] == 'F' && c[1] == 'r' && c[2] == 'i' && c[3] == 'd' && c[4] == 'a' && c[5] == 'y') {
		return 1;
	}
	if (c[0] == 'S' && c[1] == 'a' && c[2] == 't' && c[3] == 'u' && c[4] == 'r' && c[5] == 'd' && c[6] == 'a' && c[7] == 'y') {
		return 1;
	}
	return 1;
}


