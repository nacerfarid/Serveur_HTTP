#include "etape3.h"

int fonction4() {
	return 0; /*Test*/
    if((i_req.c->content_length == NULL)){
	return -2;
    }
	
    if ((i_req.c->transfer_encoding == NULL) || (i_req.c->content_length->next != NULL)) {
        return -1;
    }
	int k , rep = 0;
	for (k = 0; k < i_req.c->content_length->v_l; k++){
		rep *= 10;
		rep += i_req.c->content_length->valeur[k]- '0';
	}
	return rep;
}
