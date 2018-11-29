#include "etape3.h"
void ajoutLocation(){
    char *c = c_rep;
    int l = l_rep;
    int i;
    int i_slash = -1;
    for (i=0;i<l;i++) {
        if (c[i] == '/') {
            i_slash = i;
        }
    }
    i_slash++;
    

	Champ* location = malloc(sizeof(Champ));
	for (i=0;i<i_slash+1;i++) {
		location->valeur[i] = c[i];
	}
	//location->valeur = c;
	location->v_l = i_slash;
	i_res.c->location = location;

}
