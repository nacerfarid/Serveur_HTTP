#include "etape3.h"


/*On normalise l'URL en le parcourant lettre par lettre et en analysant le code ascii*/
void normalisationURL(char *buffer, int l) {
    char asciinum[3] = {0};
    int i = 0, c;
    
    while ( i< l ) {
	if ( buffer[i] == '+' )
	    buffer[i] = ' ';
	else if ( buffer[i] == '%' ) {
	    asciinum[0] = buffer[i+1];
	    asciinum[1] = buffer[i+2];
	    buffer[i] = strtol(asciinum, NULL, 16);
	    /*Convert string to long integer*/
	    c = i+1;
	    do {
		buffer[c] = buffer[c+2];
	    } while ( buffer[2+(c++)] );
	}
	++i;
    }
}
