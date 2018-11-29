#include "abnf.h"
#include "etape3.h"

void est_day_restr(char *c, int l) {
	if(est_day(c,l,"",0,NULL)==1){
		if(c[0]>'3'){
			semant_ok = 0;
		}
		if((c[0]==3) && (c[1]>'1')){
			semant_ok = 0;
		}
		else{
			semant_ok = 1;
	}}

}
