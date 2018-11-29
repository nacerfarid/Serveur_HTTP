#include "etape3.h"

void ajoutContentLength() {
	Champ *chp = malloc(sizeof(Champ));
	int i=0;
	int i_test;
	int k;
	int length = i_res.m_l;
	printf("length = %d",length);
	char dc;
	char str[MAX_VALUE_SIZE];
	snprintf(str, sizeof(str), "%d", length);
	i = 0;
	while (str[i] != '\0') {
		chp->valeur[i] = str[i];
		i++;
	}
	chp->v_l = i;
	i_res.c->content_length = chp;
}

int zeros(int n) {
	int rep = 0;
	if (n==0) {
		return 1;
	}
	while (n%10 == 0) {
		n /= 10;
		rep++;
	}
	return rep;
}

int longueur(int n){
	int res = 0;
	if(n == 0) {
		return 1;
	}
	else if(n < 0)  { //si tu compte le moins dans la longueur
		++res;
	}
	while(n != 0) {
		n /= 10;
		++res;
	}
	return res;
}

char recup_dernier_chiffre(int n) {
	int rep = -1;
	if (n==0) {
		return 0+'0';
	}
	while (n!=0) {
		rep = n;
		n /= 10;
	}
	return rep + '0';
}

int power(int base, int puissance) {
	int rep;
	if (base ==1 || puissance ==0) {
		return 1;
	}
	else {
		rep = base;
		puissance -= 1;
		while (puissance != 0) {
			rep *= base;
			puissance -=1;
		}
		return rep;
	}
}

