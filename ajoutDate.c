#include "etape3.h"

char *jourdesemaine(int d, int m, int y)
{
	int a;
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	a = ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
	switch(a){
	case 0 : 
	    return "Sun";
	    break;
	case 1 : 
	    return "Mon";
	    break;
	case 2 : 
	    return "Tue";
	    break;
	case 3 : 
	    return "Wed";
	    break;
	case 4 : 
	    return "Thu";
	    break;
	case 5 : 
	    return "Fri";
	    break;
	case 6 : 
	    return "Sat";
	    break;
	default :
		return "impossible";
		break;
}

}

void ajoutDate() {
	time_t t = time(NULL);
	int i;
	struct tm tm = *localtime(&t);
	char *jour = malloc(sizeof(char[3]));
	jour = jourdesemaine(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	char day[3];
	char month[3];
	char year[5];
	char hour[3];
	char min[3];
	char sec[3];
	sprintf(day, "%02d", tm.tm_mday, sizeof(day));
	sprintf(month, "%02d", tm.tm_mon+1, sizeof(month));
	sprintf(year, "%04d", tm.tm_year + 1900, sizeof(year));
	sprintf(hour, "%02d", tm.tm_hour, sizeof(hour));
	sprintf(min, "%02d", tm.tm_min, sizeof(min));
	sprintf(sec, "%02d", tm.tm_sec, sizeof(sec));
	char temps[28];
	temps[0] = jour[0];
	temps[1] = jour[1]; 
	temps[2] = jour[2];
	temps[3] = ',';
	temps[4] = ' ';
	temps[5] = day[0];
	temps[6] = day[1];
	temps[7] = ' ';
	temps[8] = month[0];
	temps[9] = month[1];
	temps[10] = ' ';
	temps[11] = year[0];
	temps[12] = year[1];
	temps[13] = year[2];
	temps[14] = year[3];
	temps[15] = ' ';
	temps[16] = hour[0];
	temps[17] = hour[1];
	temps[18] = ':';
	temps[19] = min[0];
	temps[20] = min[1];
	temps[21] = ':';
	temps[22] = sec[0];
	temps[23] = sec[1];
	temps[24] = ' ';
	temps[25] = 'G';
	temps[26] = 'M';
	temps[27] = 'T';

	Champ* dateee = malloc(sizeof(Champ));
	for (i=0;i<28;i++) {
		dateee->valeur[i] = temps[i];
	}
	//dateee->valeur = temps;
	dateee->v_l = 28;
	i_res.c->date = dateee;

}

