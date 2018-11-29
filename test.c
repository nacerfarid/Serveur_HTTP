#include "etape3.h"

void test() {
	int i;	
	printf("Contenu de i_req :\n");
	printf("message body de taille %d et de contenu :",i_req.m_l);
	for (i=0;i<i_req.m_l;i++) {
		printf("%c",i_req.message[i]);
	}
	if (i_req.req != NULL) {
		printf("\ni_req.req défini, avec :");
		printf("\n- url de taille %d et de contenu :",i_req.req->u_l);
		for (i=0;i<i_req.req->u_l;i++) {
			printf("%c",i_req.req->URL[i]);
		}
		printf("\n- http version : %d.%d",i_req.req->version[0],i_req.req->version[1]);
		printf("\n- methode : de numéro %d",i_req.req->method);
	}
	else {
		printf("\ni_req.req non défini");
	}
	
	if (i_req.c != NULL) {
		printf("\ni_req.c défini, avec :");
		/*...*/
	}
	else {
		printf("\ni_req.c non défini");
	}
}
