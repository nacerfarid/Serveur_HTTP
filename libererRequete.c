#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void libererRequete(){
    if (i_req.m_l)
	    free(i_req.m_l);
    if (i_req.message)
	    free(i_req.message);
    if (i_req.req->c->connection)
	    free(i_req.req->c->connection);
    if (i_req.req->c->accept_encoding)
	    free(i_req.req->c->accept_encoding);
    if (i_req.req->c->accept)
	    free(i_req.req->c->accept);
    if (i_req.req->c->user_agent)
	    free(i_req.req->c->user_agent);
    if (i_req.req->c->referer)
	    free(i_req.req->c->referer);
    if (i_req.req->c->host)
	    free(i_req.req->c->host);
    if (i_req.req->c->content_length)
	    free(i_req.req->c->content_length);
    if (i_req.req->c->transfer_encoding)
	    free(i_req.req->c->transfer_encoding);
    if (i_req.req->c->cookie)
	    free(i_req.req->c->cookie);
    if (i_req.req->version)
	    free(i_req.req->version);
    if (i_req.req->URL)
	    free(i_req.req->URL);
    if (i_req.req->u_l)
	    free(i_req.req->u_l);
    if (i_req.req->Methode)
	    free(i_req.req->Methode);
    if (i_req.req->m_l)
	    free(i_req.req->m_l);
}
	
