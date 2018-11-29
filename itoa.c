#include "etape3.h"

void code_en_char(char c[3], int code) {
	int unite = code % 10;
	int dizaine = (code % 100) / 10;
	int centaine = code / 100;
	
	switch(centaine) {
		case(0) : c[0] = '0';break;
		case(1) : c[0] = '1';break;
		case(2) : c[0] = '2';break;
		case(3) : c[0] = '3';break;
		case(4) : c[0] = '4';break;
		case(5) : c[0] = '5';break;
		case(6) : c[0] = '6';break;
		case(7) : c[0] = '7';break;
		case(8) : c[0] = '8';break;
		case(9) : c[0] = '9';break;
	}
	switch(dizaine) {
		case(0) : c[1] = '0';break;
		case(1) : c[1] = '1';break;
		case(2) : c[1] = '2';break;
		case(3) : c[1] = '3';break;
		case(4) : c[1] = '4';break;
		case(5) : c[1] = '5';break;
		case(6) : c[1] = '6';break;
		case(7) : c[1] = '7';break;
		case(8) : c[1] = '8';break;
		case(9) : c[1] = '9';break;
	}
	switch(unite) {
		case(0) : c[2] = '0';break;
		case(1) : c[2] = '1';break;
		case(2) : c[2] = '2';break;
		case(3) : c[2] = '3';break;
		case(4) : c[2] = '4';break;
		case(5) : c[2] = '5';break;
		case(6) : c[2] = '6';break;
		case(7) : c[2] = '7';break;
		case(8) : c[2] = '8';break;
		case(9) : c[2] = '9';break;
	}
}
