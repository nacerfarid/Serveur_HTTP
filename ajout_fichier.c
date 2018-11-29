#include "etape3.h"

void ajout_fichier(){
    FILE *fptr;
    /*  ouverture pour ecriture*/
    fptr = fopen(c_complet, "a");
	if (fptr == NULL) {
		fptr = fopen(c_complet, "w+");
	}
    fwrite(i_req.message,1,i_req.m_l,fptr);
    fclose(fptr);
}
