#include "abnf.h"
#include "etape3.h"

void est_minute_restr(char *c, int l) {
	if(est_minute(c,l,"",0,NULL)==1){
		if(c[0]>'5'){
				semant_ok = 0;
			}
}
}
