#include "etape3.h"

int fonction56 (){
    int taille = 0, k= i_req.c->content_length-> v_l-1;
    if ( (i_req.c -> content_length != NULL) && (i_req.c -> transfer_encoding == NULL) ){
	int k , rep = 0;
	for (k = 0; k < i_req.c->content_length->v_l; k++){
		rep *= 10;
		rep += i_req.c->content_length->valeur[k]- '0';
	}
        return (rep);
    }
    else return (taille);
}


