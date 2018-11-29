#include "abnf.h"
#include "etape3.h"

void est_hour_restr(char *c, int l) {
	if(est_hour(c,l,"",0,NULL)==1){
		if(c[0]>'2'){
			semant_ok = 0;
		}
		if((c[0]=='2') && (c[1] > '3')){
			semant_ok = 0;
		}
		else{
			semant_ok = 1;
	}}

}
