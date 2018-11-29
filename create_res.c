#include "etape3.h"



void create_res(){
	char crlf[2] ;
	crlf[0] = 10;
	crlf[1] = 13;
    char space[] = " ";
	char nom_http[] = "HTTP/1.1 ";
	char nom_cookie[] = "Cookie: ";
	char nom_content_length[] = "Content-Length: ";
	char nom_content_type[] = "Content-Type: ";
	char nom_transfer_encoding[] = "Transfer-Encoding: ";
	char nom_host[] = "Host: ";
	char nom_referer[] = "Referer: ";
	char nom_user_agent[] = "User-Agent: ";
	char nom_accept[] = "Accept: ";
	char nom_accept_encoding[] = "Accept-Encoding: ";
	char nom_connection[] = "Connection: ";
	char nom_date[] = "Date: ";
	char nom_server[] = "Server: ";
	char nom_location[] = "Location: ";
	/*HTTP VERSION*/
    char reponse[MAX_RES_SIZE];
    int i;

	/*NOM, CODE ET MESSAGE CODE*/
	concat_chaine(reponse, 0, nom_http,9);
	char code[3];
	code_en_char(code, i_res.res->code); /*dans le fichier itoa.c*/
    int k = 9;
    concat_chaine(reponse, 9, code, 3);
    concat_chaine(reponse, 12, space, 1);
    char msg_code[MAX_SIZE_MESSAGE_CODE];
	for (i=0;i<i_res.res->m_l;i++) {
		msg_code[i] = i_res.res->message_code[i];
	}
	//msg_code = i_res.res->message_code;
	k=13;
    concat_chaine(reponse,k,  msg_code, i_res.res->m_l);
    k = k+ (i_res.res->m_l);
    concat_chaine(reponse, k,  crlf, 2);
    k=k+2;

	/*CHAMPS COOKIE*/
    Champ* C= i_res.c->cookie;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_cookie, 8); k+= 8;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_cookie, 8); k+= 8;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }

	/*CHAMP CONTENT LENGTH*/
    C = i_res.c->content_length;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_content_length, 16); k+= 16;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_content_length, 16); k+= 16;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }

	/*CHAMP CONTENT TYPE*/
    C = i_res.c->content_type;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_content_type, 14); k+= 14;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_content_type, 14); k+= 14;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP TRANSFER ENCODING*/
    C = i_res.c->transfer_encoding;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_transfer_encoding, 19); k+= 19;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_transfer_encoding, 19); k+= 19;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP HOST*/
    C = i_res.c->host;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_host, 6); k+= 6;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_host, 6); k+= 6;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP REFERER*/
    C = i_res.c->referer;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_referer, 9); k+= 9;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_referer, 9); k+= 9;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP USER AGENT*/
    C = i_res.c->user_agent;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_user_agent, 12); k+= 12;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_user_agent, 12); k+= 12;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP ACCEPT*/
    C = i_res.c->accept;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_accept, 8); k+= 8;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_accept, 8); k+= 8;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP ACCEPT ENCODING*/
    C = i_res.c->accept_encoding;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_accept_encoding, 17); k+= 17;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_accept_encoding, 17); k+= 17;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP CONNECTION*/
    C = i_res.c->connection;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_connection, 12); k+= 12;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_connection, 12); k+= 12;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP DATE*/
    C = i_res.c->date;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_date, 6); k+= 6;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_date, 6); k+= 6;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP SERVER*/
    C = i_res.c->server;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_server, 8); k+= 8;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_server, 8); k+= 8;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }
    
	/*CHAMP LOCATION*/
    C = i_res.c->location;
    if ( C != NULL){
		concat_chaine(reponse, k, nom_location, 10); k+= 10;
        concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
        concat_chaine(reponse, k, crlf, 2); k=k+2;
        while (C->next != NULL){
			concat_chaine(reponse, k, nom_location, 10); k+= 10;
            C=C->next;
            concat_chaine(reponse, k, C->valeur, C->v_l); k=k+C->v_l;
            concat_chaine(reponse, k, crlf, 2); k=k+2;
        }   
    }

	/*AFFICHAGE DE LA REPONSE ENVOYEE (Sans message body)*/
	printf("\nReponse :\n");
	for (i=0;i<k;i++) {
		printf("%c",reponse[i]);
	}
	printf("\n");	

	/*MESSAGE BODY*/
    concat_chaine(reponse, k, crlf, 2); k=k+2;

    char *msg= i_res.message;
    concat_chaine(reponse, k, msg, i_res.m_l /*-1*/);
    k=k+i_res.m_l;
    
    l_res=k;
    c_res=reponse;

	/*AFFICHAGE DE LA REPONSE ENVOYEE (Avec message body)*/
	//printf("\nReponse :\n");
	//for (i=0;i<k;i++) {
	//	printf("%c",reponse[i]);
	//}
	//printf("\n");	
}

/*
int main {
    i_res.res-> code= 300;
    i_res.res -> message_code= "1,2,3 nous irons aux bois";
    i_res.c->user_agent="55";
    i_res.c->date = '3';
    create_res();
    int k=0;
    while(c_res[k]!=0){
        printf("%d", c_res[k]);
    }
    return 0;
}
*/
