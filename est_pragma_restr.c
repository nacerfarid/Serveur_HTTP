#include "abnf.h"
#include "etape3.h"

void est_pragma_restr(char *c, int l) {
	if (est_pragma(c, l, "",0,NULL)==1){
		if(!(l == 8 && c[0]=='n' && c[1]=='o' && c[2]=='-' && c[3]=='c' && c[4]=='a' && c[5]=='c' && c[6]=='h' && c[7]=='e')){
			semant_ok = 0;
		}
}

}
