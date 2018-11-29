#include "etape3.h"

message requettttte;
message repppponse;
message *requete = &requettttte;
message *reponse = &repppponse;

int main() {
	//signal(SIGPIPE,SIG_IGN);

	int longueur_message_body;
	char *c;
	int l;
	
	int i;

    while(1) {
		printf("Recuperation de requete...");
        /*RAZ DES STRUCTURES*/
        config_init();
		//test();
        
        /*RECUPERATION DE LA REQUETE*/
        requete = getRequest(8080);
        c = requete->buf;
        l = requete->len;
		printf("reçu\n\n| Requete\nv ici\n");
		for (i = 0;i<l;i++) {
				printf("%c",c[i]);
		}
		printf("^ Requete\n| ici\n\n");
        
        /*PARSEUR*/
		printf("Parsing et analyse semantique...");
        if (!parseur(c, l, "", 0)) {
            i_res.res->code = 400;
        }
        
        /*ANALYSE SEMANTIQUE*/
        if (i_res.res->code == 0) {
            semant_ok = 1;
            semantique(c, l);
            if (semant_ok == 0) {
                i_res.res->code = 400;
            }
        }
        
        /*REMPLISSAGE DE StructInfoReq*/
        if (i_res.res->code == 0) {
            remplissageStruct(c, l); /*Doit revérifier chaque valeur d'en-tête*/
        }
        
		/*NORMALISATION D'URL*/
		printf("fait.\nCorrection de l'URL et remplissage de i_req...");
        if (i_res.res->code == 0) {
            l_rep = norm_URL(i_req.req->u_l, i_req.req->URL, c_rep);
        }
		/*COMPLETION D'URL*/
			

		for (i=0;i<server_root_l;i++) {
			c_complet[i] = server_root[i];
		}
		l_complet = server_root_l;
		
		l_complet = concat_chaine(c_complet,l_complet,c_rep,l_rep);
		c_complet[l_complet] = '\0';
		recup_ext();
		/*STOCKAGE DE LA VRAIE URL DANS i_req*/
		i_req.req->u_l = l_rep;		
		for(i=0;i<i_req.req->u_l;i++) {
			i_req.req->URL[i] = c_complet[i];
		}
		//cb_URL(i_req.req->URL,i_req.req->u_l); /* solution trouvee pour contourner est_uri qui retourne tjs 0*/
		//printf("EST_URI = %d",est_uri(i_req.req->URL,i_req.req->u_l,"uri",3,cb_URL)); /*permet de stocker l'extension*/

        /*VERIF. DE LA TAILLE DU MESSAGE*/
        if (i_res.res->code ==0) {
			longueur_message_body = fonctionx();
        	if (longueur_message_body != i_req.m_l) {
            	i_res.res->code = 411;
			}
        }
        
        /*AUTHORISATION*/
        //verifAuthor();
        
        /*LANGAGE*/
        //verifLang();
        
        /*ACCEPT*/
        //verifAccept();
        
        /*ACTION*/
		printf("fait.\nAction en cours...");
		printf("");
        switch (i_req.req->method) {
            case (POST) : ajout_fichier(); break;
            case (GET) : recup_fichier(); break;
            case (DELETE) : suppr_fichier(); break;
			case (PUT) : ecrase_fichier(); break;
        }
        
        /*REMPLISSAGE DE StructInfoRes*/
		printf("fait.\nGeneration de réponse...");
		if (i_res.res->code ==0) {
			i_res.res->code = 200;
		}
		ajoutDate();
		ajoutContentLength();
        ajoutServeur();
        ajoutLocation();
        ajoutMessageCode();
        ajoutContentType();

	//	
//	char triche[] = "text/txt";
//	Champ *chp = malloc(sizeof(Champ));
//	chp->v_l = 8;
//	i_res.c->content_type = chp;
//	for (i=0;i<8;i++) {
//		chp->valeur[i] = triche[i];
//	}
//	i_res.c->content_type = chp;
        //

        /*ECRITURE REPONSE*/
        create_res();
	/*ENVOI AVEC sendResponse*/
	reponse->buf = c_res;
	reponse->len = l_res;
	reponse->clientId = requete->clientId;
	sendReponse(reponse);
	freeRequest(requete);

	/*FERMETURE EVENTUELLE DU SOCKET*/
	if (i_req.c->connection == NULL ||
            !compare(i_req.c->connection->valeur, i_req.c->connection->v_l, "keep-alive", 10)) {
		requestShutdownSocket(reponse->clientId);
	}
	config_init();
    }
	return 0;
}
