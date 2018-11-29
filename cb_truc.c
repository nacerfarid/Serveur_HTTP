#include "etape3.h"
#include "abnf.h"
void cb_method(char *c, int l) {
    if (est_method(c,l,"",0,NULL)) {
        if (compare(c,l,"GET",3)) {
			i_req.req->method = GET;
		}
		if (compare(c,l,"POST",4)) {
			i_req.req->method = POST;
		}
if (compare(c,l,"PUT",3)) {
			i_req.req->method = PUT;
		}
if (compare(c,l,"OPTIONS",7)) {
			i_req.req->method = OPTIONS;
		}
if (compare(c,l,"HEAD",4)) {
			i_req.req->method= HEAD;
		}
if (compare(c,l,"DELETE",6)) {
			i_req.req->method = DELETE;
		}
if (compare(c,l,"CONNECTIONS",11)) {
			i_req.req->method = CONNECTIONS;
		}
if (compare(c,l,"TRACE",5)) {
			i_req.req->method = TRACE;
		}
    }
}

void cb_request_target(char *c, int l) {
    if (est_request_target(c,l,"",0,NULL)) {
        i_req.req->u_l = l;
        int i;
        for (i=0;i<l;i++) {
            i_req.req->URL[i] = c[i];
        }
    }
}

void cb_http_version(char *c, int l) {
    i_req.req->version[0] = c[1];
    i_req.req->version[1] = c[3];
}

void cb_URL(char *c, int l) {
	int i;
	if (est_uri(c, l,"",0,NULL)) { /*On supprime ici aussi cette vérification supplémentaire*/
		recup_ext(); /*Extension*/
	}
}

void cb_cookie_string(char *c, int l) {
	
    if (est_cookie_string(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->cookie == NULL) {
            i_req.c->cookie = chp;
        }
        else {
            pointeur = i_req.c->cookie;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_content_length(char *c, int l) {
    if (est_content_length(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->content_length == NULL) {
            i_req.c->content_length = chp;
        }
        else {
            pointeur = i_req.c->content_length;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_transfer_encoding(char *c, int l) {
    if (est_transfer_encoding(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->transfer_encoding == NULL) {
            i_req.c->transfer_encoding = chp;
        }
        else {
            pointeur = i_req.c->transfer_encoding;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_Host(char *c, int l) {
    if (est_Host(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->host == NULL) {
            i_req.c->host = chp;
        }
        else {
            pointeur = i_req.c->host;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_referer(char *c, int l) {
    if (est_referer(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->referer == NULL) {
            i_req.c->referer = chp;
        }
        else {
            pointeur = i_req.c->referer;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_user_agent(char *c, int l) {
    if (est_user_agent(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->user_agent == NULL) {
            i_req.c->user_agent = chp;
        }
        else {
            pointeur = i_req.c->user_agent;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_accept(char *c, int l) {
    if (est_accept(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->accept == NULL) {
            i_req.c->accept = chp;
        }
        else {
            pointeur = i_req.c->accept;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

/*VRAIE FONCTION*/
// void cb_accept(char *c, int l) { /*On suppose que les q sont dans l'ordre décroissant*/
//     Champ_accept chp;
    
//     md1 ; q=0.7 , md2 , md3 ; q = 0.5
    
//     est_accept(c, l, "media_range",11, cb_accept_media_range); /*on stocke d'abord toutes les extensions*/      /*   md1     md2      md3                =>     md1     md2    md3   */
//     est_accept(c, l, "accept_params",13,cb_accept_accept_params) /*on met ensuite les extensions                                                         =>                          */
//     /*                                                                                                                                                   =>                          */
//                                                                                                                 /*    q=0. ?   q=0.7 ?                  =>     q=1     q=0.8  q=0.7 */
    
//     /*Champ chp;
//     Champ* pointeur;
//     chp.v_l = l;
//     int i;
//     for (i=0;i<l;i++) {
//         chp.valeur[i] = c[i];
//     }
//     if (i_req->c->accept == NULL) {
//         i_req->c->accept = &chp;
//     }
//     else {
//         pointeur = i_req->c->accept;
//         while((*pointeur).next != NULL) {
//             pointeur = (*pointeur).next;
//         }
//         pointeur.next = &chp;
//     }*/
// }

void cb_accept_encoding(char *c, int l) {
    if (est_accept_encoding(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->accept_encoding == NULL) {
            i_req.c->accept_encoding = chp;
        }
        else {
            pointeur = i_req.c->accept_encoding;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}

void cb_connection(char *c, int l) {
    if (est_connection(c,l,"",0,NULL)) {
        Champ* chp = malloc(sizeof(Champ));
		char *texte = malloc(sizeof(char[MAX_VALUE_SIZE]));
		
        Champ* pointeur;
        chp->v_l = l;
        int i;
        for (i=0;i<l;i++) {
            chp->valeur[i] = c[i];
        }
        if (i_req.c->connection == NULL) {
            i_req.c->connection = chp;
        }
        else {
            pointeur = i_req.c->connection;
            while((*pointeur).next != NULL) {
                pointeur = (*pointeur).next;
            }
            (*pointeur).next = chp;
        }
    }
}
