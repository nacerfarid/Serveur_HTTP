#include "etape3.h"

void config_init(){
	/*INITIALISATION DE i_req*/
	if (i_req.req != NULL) {
		free(i_req.req);
	}
	i_req.req = malloc(sizeof(ReqInfo));

	if (i_req.c != NULL) {
		free(i_req.c);
	}
	i_req.c = malloc(sizeof(Champs));
	

	/*INITIALISATION DE i_res*/
	if (i_res.res != NULL) {
		free(i_res.res);
	}
	i_res.res = malloc(sizeof(ResInfo));
	if (i_res.c != NULL) {
		free(i_res.c);
	}
	i_res.c = malloc(sizeof(Champs));


	i_res.res->code = 0;
	semant_ok = 1;
	/*Champs chp_tmp;
    i_req.req->version[0] = 0;
	i_req.req->version[1] = 0;
	i_req.req->method = NUL;
	i_req.req->URL[0] = '\0';
	printf("TEST1\n");
    i_req.req->u_l = 0;
	printf("TEST5\n");
	printf("Adresse connection : %d\n",i_req.c->connection);
    i_req.c->connection = chp_tmp.connection;
	printf("TEST6\n");
    i_req.c->accept_encoding = NULL;
    i_req.c->accept = NULL;
    i_req.c->user_agent = NULL;
    i_req.c->referer = NULL;
    i_req.c->host = NULL;
	printf("TEST4\n");
    i_req.c->content_length = NULL;
    i_req.c->transfer_encoding = NULL;
    i_req.c->cookie = NULL;
	i_req.c->date = NULL;
	i_req.c->server = NULL;
	i_req.c->location = NULL;
    semant_ok = 1;
	printf("TEST2\n");
    i_res.res->version[0] = 0;
	i_res.res->version[1] = 0;
    i_res.res->m_l = 0;
    i_res.res->message_code[0] = '\0';
	i_res.res->code = 0;
	i_res.c->connection = NULL;
    i_res.c->accept_encoding = NULL;
    i_res.c->accept = NULL;
    i_res.c->user_agent = NULL;
    i_res.c->referer = NULL;
    i_res.c->host = NULL;
    i_res.c->content_length = NULL;
    i_res.c->transfer_encoding = NULL;
    i_res.c->cookie = NULL;
	i_res.c->date = NULL;
	i_res.c->server = NULL;
	i_res.c->location = NULL;
	printf("TEST3");*/
}
	
