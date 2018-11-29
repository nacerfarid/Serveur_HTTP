#include "abnf.h"

int parseur(char *c, int l, char *s, void (*callback)()) {
    int ls;
	ls = strlen(s);
    int retour;
    return (est_http_message(c,l,s,ls,callback));
}
