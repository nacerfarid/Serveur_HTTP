#include "etape3.h"
/*renvoie des ressources*/
void recup_fichier(){
	int k=0;
	FILE *fp;

	fp = fopen(c_complet,"r");
	if (fp == NULL){
		i_res.res->code=404; /*fichier inexistant ==> erreur 404 après*/
	}
	else{
		fseek(fp,0,SEEK_END);
		int taille = ftell(fp);
		fseek(fp,0,SEEK_SET);
		/*int debut = fp;
		fseek(fp,0,SEEK_END);
		int fin = fp;
		fseek(fp,0,SEEK_SET);*/
		while (!feof(fp)) {
			i_res.message[k] = fgetc(fp);
			k++;
		}
		fclose(fp);
		i_res.m_l = taille; 
	}
}
