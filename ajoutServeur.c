#include "etape3.h"

void ajoutServeur(){
	char nom[] = "ESISAR/2.0";
	Champ* server = malloc(sizeof(Champ));
	int i;
	for (i=0;i<10;i++) {
		server->valeur[i] = nom[i];
	}
	server->v_l = 10;
	i_res.c->server = server;
}
