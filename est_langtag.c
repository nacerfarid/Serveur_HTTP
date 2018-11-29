#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_langtag(char *c, int l, char *s, int ls, void (*callback)()) {
/*Retourne 1 si c, de longueur l, est un tag de lang*/
	char S[] = "langtag";
    int i_search = 0;
    if (ls == 7) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }

    printf("COUCOU\n");

    int deb = 0, fin = 0;
    int i, i2;
    int test_chaine;
    int deb_ext, fin_ext;
    while (fin < l && c[fin] != '-') {
        fin++;
    }
    if (fin == l) {
        return 0;
    }
    if (fin == 2 || fin == 3) { /*Le language est un 2*3alpha [-extlang]*/
        /*RECHERCHE DE LA FIN DE LANGUAGE*/
        i = fin;
        if (i + 3 < l && est_alpha(c[i+1]) && est_alpha(c[i+2]) && est_alpha(c[i+3])) {
            i += 3 ;
            if ((i + 1 <l && c[i+1] == '-') || i + 1 == l) { /*ie il y a bien 3 alpha puis un '-'*/
                i2 = i; /*I2 : indicateur de la partie sûre...car il y avait bien 3 alpha et pas plus*/
                i++; /*i pointe sur un '-' ou sur la fin*/

            }
            else { /*on a pas parcouru toute la liste, et ce n'est pas un '-' qui suit*/
                i-= 3; /*Pour éviter que les prochaines recherches de 3 alpha puissent éventuellement aboutir*/
            }
        }
        /*DEUX CHAMPS 3 ALPHA ENCORE POSSIBLE*/
        if (i + 3 < l && est_alpha(c[i+1]) && est_alpha(c[i+2]) && est_alpha(c[i+3])) {
            i += 3 ;
            if ((i + 1 <l && c[i+1] == '-') || i + 1 == l) { /*ie il y a bien 3 alpha puis un '-'*/
                i2 = i; /*I2 : indicateur de la partie sûre...car il y avait bien 3 alpha et pas plus*/
                i++; /*i pointe sur un '-' ou sur la fin*/

            }
            else { /*on a pas parcouru toute la liste, et ce n'est pas un '-' qui suit*/
                i-= 3; /*Pour éviter que les prochaines recherches de 3 alpha puissent éventuellement aboutir*/
            }
        }
        if (i + 3 < l && est_alpha(c[i+1]) && est_alpha(c[i+2]) && est_alpha(c[i+3])) {
            i += 3 ;
            if ((i + 1 <l && c[i+1] == '-') || i + 1 == l) { /*ie il y a bien 3 alpha puis un '-'*/
                i2 = i; /*I2 : indicateur de la partie sûre...car il y avait bien 3 alpha et pas plus*/
                i++; /*i pointe sur un '-' ou sur la fin*/

            }
            else { /*on a pas parcouru toute la liste, et ce n'est pas un '-' qui suit*/
                i-= 3; /*Pour éviter que les prochaines recherches de 3 alpha puissent éventuellement aboutir*/
            }
        }
        /*Ici, i2 pointe sur la fin de language :*/
        fin = i2;
    }
    if (!est_language(c, fin, s, ls, callback)) {
        return 0;
    }

    if (fin == l) {
        return 1;
    }
    fin++;
    /*fin pointe sur le 1er carac après le langage, donc après un '-' a priori*/

    /*On se lance dans la recherche des champs optionnels :*/
    deb = fin;
    while (fin < l && c[fin] != '-') {
        fin++;
    }

    /*SCRIPT*/
    if (fin - deb == 4 && est_alpha(c[deb]) && est_alpha(c[deb+1]) && est_alpha(c[deb+2]) && est_alpha(c[deb+3])) {
        if(!est_script(c + sizeof(char) * deb, fin - deb, s, ls, callback)) { /*Un peu inutile...sauf pour le callback*/
            return 0;
        }
        if (fin == l) { /*Plus de champs optionnels, donc c'est ok*/
            return 1;
        }
        fin++;
        deb = fin;
        while (fin < l && c[fin] != '-') {
            fin++;
        }
    }

    /*REGION*/
    if ((fin - deb == 2 && est_alpha(c[deb]) && est_alpha(c[deb+1])) || (fin - deb == 3 && est_digit(c[deb]) && est_digit(c[deb+1]) && est_digit(c[deb+2]))) {
        if (!est_region(c + sizeof(char) * deb, fin-deb, s, ls, callback)) {
            return 0;
        }
        if (fin == l) {
            return 1;
        }
        fin++;
        deb = fin;
        while (fin < l && c[fin] != '-') {
            fin++;
        }
    }

    /*VARIANTS au pluriel*/
    while(fin < l && fin - deb != 1) { /*Si l'on sort de cette boucle, soit fin = l, soit ce n'est plus un variant*/
        if(!est_variant(c + sizeof(char) * deb, fin - deb, s, ls, callback)) {
            return 0;
        }
        fin++; /*On sait que c[fin] est un '-'*/
        deb = fin;
        while(fin < l && c[fin] != '-') {
            fin++;
        }
    }

    /*EXTENSIONS au pluriel & PRIVATEUSE*/
    /*On cherche s'il y a une chaine -x- dans le reste de la fonction ; si elle y est, il y a une privateuse (on vérifie dans la foulée que c'en est bien une)*/
    test_chaine = fin;
    while(test_chaine+2 < l && (c[test_chaine] != '-' || c[test_chaine+1] != 'x' || c[test_chaine+2] != '-')) {
        test_chaine++;
    }
    if (test_chaine+2 < l) { /*Il y a privateuse, et test_chaine+1 pointe vers x, ie le 1er élt de la privateuse*/
        if (!est_privateuse(c + sizeof(char) * (test_chaine+1),l-(test_chaine+1), s, ls, callback)) {
            return 0;
        }
        /*Il reste à regarder si, de fin à test_chaine (exclu...), on a bien un certain nombre d'extensions*/
        deb_ext = fin+1;
        fin_ext = fin+2;
        /*Pour cela : on regarde si on a bien un -a- au début, puis on va de -a- en -a- pour délimiter les différentes extensions     a qcq*/
        while(fin_ext+1<test_chaine) {
            while(fin_ext+1 < test_chaine && (c[fin_ext-1] != '-' || c[fin_ext+1] == '-')) {
                fin_ext++;
            }
            if (fin_ext+1<test_chaine) {
                if (!est_extension(c + sizeof(char) * deb_ext, fin_ext-deb_ext, s, ls, callback)) {
                    return 0;
                }
                deb_ext = fin_ext;
                fin_ext++;
            }
        }
        return (est_extension(c+sizeof(char) * deb_ext, (test_chaine - fin) -deb_ext, s, ls, callback));
    }

    else { /*Pas de privateuse : même algo pour les extensions, mais avec l au lieu de test_chaine*/
        deb_ext = fin+1;
        fin_ext = fin+2;
        /*Pour cela : on regarde si on a bien un -a- au début, puis on va de -a- en -a- pour délimiter les différentes extensions     a qcq*/
        while(fin_ext+1<l) {
            while(fin_ext+1 < l && (c[fin_ext-1] != '-' || c[fin_ext+1] == '-')) {
                fin_ext++;
            }
            if (fin_ext+1<l) {
                if (!est_extension(c + sizeof(char) * deb_ext, fin_ext-deb_ext, s, ls, callback)) {
                    return 0;
                }
                deb_ext = fin_ext;
                fin_ext++;
            }
        }
        return (est_extension(c+sizeof(char) * deb_ext, (l - fin) -deb_ext, s, ls, callback));
    }
}
