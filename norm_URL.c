#include "etape3.h"
int norm_URL(int l, char *c,char *c_rep) {
	
    int nb_perc = 0 ; /*nb de pourcentage*/
    int i;

	/*printf("c = ");
	for (i=0;i<l;i++) {
		printf("%c",c[i]);
	}
	printf("\nc_rep = ");
	for (i=0;i<l_rep;i++) {
		printf("%c",c[i]);
	}*/

    for (i = 0;i<l;i++) {
        if (c[i] == '%') {
            nb_perc++;
        }
    }
    char tamp[2];
    int hex[2];
    int tampon_nombre = 0;
    
    int rep = l - 2*nb_perc;

    int i_rep = 0; /*indice du c_rep*/
    int i_c = 0; /*indice de c*/
    while (i_c< l) {
        if (c[i_c] != '%') {
            c_rep[i_rep++] = c[i_c++];
        }
        else {
            tamp[0] = c[i_c + 1];
            tamp[1] = c[i_c + 2];
            
            for(i=0; i<2; i++) {
                tamp[i] = toupper(tamp[i]);
                if (tamp[i] >= '0' && tamp[i] <= '9') {
                    hex[i] = tamp[i] - '0';
                }
                else {
                    hex[i] = tamp[i] - 'A' + 10;
                }
            }
            c_rep[i_rep++] = 16*hex[0] + hex[1];
            i_c += 3;
            }
    }
    return rep;
}
