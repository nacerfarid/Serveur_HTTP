#include "abnf.h"
#include "etape3.h"

void est_method_restr(char *c, int l) {
	if(est_method(c, l, "",0,NULL)==1){
		if(l == 3 && c[0]=='P' && c[1]=='U' && c[2]=='T'){
			semant_ok = 1;
		}
		else if(l == 3 && c[0]=='G' && c[1]=='E' && c[2]=='T'){
			semant_ok = 1;
		}
		else if(l == 7 && c[0]=='O' && c[1]=='P' && c[2]=='T' && c[3]=='I' && c[4]=='O' && c[5]=='N' && c[6]=='S'){
			semant_ok = 1;
		}
		else if(l == 4 && c[0]=='H' && c[1]=='E' && c[2]=='A' && c[3]=='D'){
			semant_ok = 1;
		}
		else if(l == 6 && c[0]=='D' && c[1]=='E' && c[2]=='L' && c[3]=='E' && c[4]=='T' && c[5]=='E'){
			semant_ok = 1;
		}
		else if(l == 4 && c[0]=='P' && c[1]=='O' && c[2]=='S' && c[3]=='T'){
			semant_ok = 1;
		}
		else if(l == 11 && c[0]=='C' && c[1]=='O' && c[2]=='N' && c[3]=='N' && c[4]=='E' && c[5]=='C' && c[6]=='T' && c[7]=='I' && c[8]=='O' && c[9]=='N' && c[10]=='S'){
			semant_ok = 1;
		}
		else if(l == 5 && c[0]=='T' && c[1]=='R' && c[2]=='A' && c[3]=='C' && c[4]=='E'){
			semant_ok = 1;
		}
		else {
			semant_ok = 0;
		}
		
	}
}
