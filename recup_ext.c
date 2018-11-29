#include "etape3.h"

void recup_ext() {
    char *c = /*i_req.req->c*/   c_complet;
    int l = /*i_req.req->u_l*/  l_complet;
    int i;
    int i_point = -1;
    for (i=0;i<l;i++) {
        if (c[i] == '.') {
            i_point = i;
        }
    }
    i_point++;
	for (i = i_point;i<l_complet;i++) {
		i_req.req->ext[i-i_point] = c_complet[i];
	}
    //i_req.req->ext = (char*) (c + sizeof(char)*i_point);
    i_req.req->l_ext = l - i_point;
	//printf("Dans recup_ext, l = %d, i_point = %d",l,i_point);
}
