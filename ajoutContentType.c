#include "etape3.h"

void ajoutContentType() {
	Champ *chp = malloc(sizeof(Champ));
	int i;
	for (i=0;i< i_req.req->l_ext;i++) {
		chp->valeur[i] = i_req.req->ext[i];
	}
	chp->v_l = i;
	
	i_res.c->content_type = chp;
}
