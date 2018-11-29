#include "abnf.h"
#include "etape3.h"

void est_connection_restr(char *c, int l) {
	if(est_connection(c, l, "",0,NULL)==1) {
		if(!((l == 5 && c[0]=='c' && c[1]=='l' && c[2]=='o' && c[3]=='s' && c[4]=='e') || (l == 8 && c[0]=='k' && c[1]=='e' && c[2]=='e' && c[3]=='p' && c[4]=='-' && c[5]=='a' && c[6]=='l' && c[7]=='i' && c[8]=='v' && c[9]=='e'))){
			semant_ok = 0;
		}
	}
}
