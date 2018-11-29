#include "etape3.h"
/*On utilise la fonction remove pour effacer le fichier nom*/
 
void suppr_fichier()
{
	char *buffer = c_complet;
	if(remove(buffer) == 0)
	  i_res.res->code=200; /*fichier supprimé avec success*/
	else
	  i_res.res->code=404; /*probleme de suppression*/
}
