#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_month(char *c, int l, char *s, int ls, void (*callback)()){
		char S[] = "month";
    int i_search = 0;
    if (ls == 5) {
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
	if (c[0] == 'J' && c[1] == 'a' && c[2] == 'n') {
		return 1;
	}
	if (c[0] == 'F' && c[1] == 'e' && c[2] == 'b') {
		return 1;
	}
	if (c[0] == 'M' && c[1] == 'a' && c[2] == 'r') {
		return 1;
	}
	if (c[0] == 'A' && c[1] == 'p' && c[2] == 'r') {
		return 1;
	}
	if (c[0] == 'M' && c[1] == 'a' && c[2] == 'y') {
		return 1;
	}
	if (c[0] == 'J' && c[1] == 'u' && c[2] == 'n') {
		return 1;
	}
	if (c[0] == 'J' && c[1] == 'u' && c[2] == 'l') {
		return 1;
	}
	if (c[0] == 'A' && c[1] == 'o' && c[2] == 'u') {
		return 1;
	}
	if (c[0] == 'S' && c[1] == 'e' && c[2] == 'p') {
		return 1;
	}
	if (c[0] == 'O' && c[1] == 'c' && c[2] == 't') {
		return 1;
	}
	if (c[0] == 'N' && c[1] == 'o' && c[2] == 'v') {
		return 1;
	}
	if (c[0] == 'D' && c[1] == 'e' && c[2] == 'c') {
		return 1;
	}
	return 1;
}
