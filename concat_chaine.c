#include "etape3.h"

int concat_chaine(char *chaine1,int l1, char *chaine2, int l2){
	int j;
    for(j=0; j<= l2; j++)
    {
        chaine1[j + l1]=chaine2[j];
    }
	return l1+l2;
}
