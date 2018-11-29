#include "etape3.h"
void remplissageStruct(char *c, int l) {
    parseur(c, l, "method", cb_method);                  
    parseur(c, l, "request_target", cb_request_target);     
    parseur(c, l, "http_version", cb_http_version);         
    parseur(c, l, "cookie_string", cb_cookie_string);        
    parseur(c, l, "content_length",cb_content_length);       
    parseur(c, l, "transfer_encoding",cb_transfer_encoding);  
    parseur(c, l, "Host",cb_Host);                           
    parseur(c, l, "referer",cb_referer);                   
    parseur(c, l, "user_agent",cb_user_agent);           
    parseur(c, l, "accept",cb_accept);                       
    parseur(c, l, "accept_encoding",cb_accept_encoding);     
    parseur(c, l, "connection",cb_connection);
    parseur(c, l, "uri",cb_URL); 
}
