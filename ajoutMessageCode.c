#include "etape3.h"


void ajoutMessageCode(){
    int k=0;
	char msg1[] = "Continue";
	char msg2[] = "Switching Protocols";
	char msg3[] = "OK";
	char msg4[] = "Created";
	char msg5[] = "Accepted";
	char msg6[] = "Non-Authoritative Information";
	char msg7[] = "No Content";
	char msg8[] = "Reset Content";
	char msg9[] = "Partial Content";
	char msg10[] = "Multiple Choices";
	char msg11[] = "Moved Permanently";
	char msg12[] = "Found";
	char msg13[] = "See Other";
	char msg14[] = "Not Modified";
	char msg15[] = "Use Proxy";
	char msg16[] = "Unused";
	char msg17[] = "Temporary Redirect";
	char msg18[] = "Bad Request";
	char msg19[] = "Unauthorized";
	char msg20[] = "Payment Required";
	char msg21[] = "Forbidden";
	char msg22[] = "Not Found";
	char msg23[] = "Method Not Allowed";
	char msg24[] = "Not Acceptable";
	char msg25[] = "Proxy Authentication Required";
	char msg26[] = "Request Timeout";
	char msg27[] = "Conflict";
	char msg28[] = "Gone";
	char msg29[] = "Length Required";
	char msg30[] = "Precondition Failed";
	char msg31[] = "Request Entity Too Large";
	char msg32[] = "Request-url Too Long";
	char msg33[] = "Unsupported Media Type";
	char msg34[] = "Requested Range Not Satisfiable";
	char msg35[] = "Expectation Failed";
	char msg36[] = "Internal Server Error";
	char msg37[] = "Not Implemented";
	char msg38[] = "Bad Gateway";
	char msg39[] = "Service Unavailable";
	char msg40[] = "Gateway Timeout";
	char msg41[] = "HTTP Version Not Supported";
	
    switch (i_res.res-> code){
        case 100:
            i_res.res-> m_l = 8;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg1[k];
            }
            break;
        case 101:
            i_res.res-> m_l = 19;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg2[k];
            }   
            break;
        case 200:
            i_res.res-> m_l = 2;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg3[k];
            }
            break;
        case 201:
			i_res.res-> m_l = 7;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg4[k];
            }
            break;
        case 202:
            i_res.res-> m_l = 8;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg5[k];
            }
            break;
        case 203:
            
            i_res.res-> m_l = 29;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg6[k];
            }
            break;
        case 204:
            i_res.res-> m_l = 10;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg7[k];
            }
            break;
        case 205:
            i_res.res-> m_l = 13;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg8[k];
            }
            break;
        case 206:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg9[k];
            }
            break;
        case 300:
            i_res.res-> m_l = 16;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg10[k];
            }
            break;
        case 301:
            i_res.res-> m_l = 17;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg11[k];
            }
            break;
        case 302:
            i_res.res-> m_l = 5;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg12[k];
            }
            break;
        case 303:
            i_res.res-> m_l = 9;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg13[k];
            }
            break;
        case 304:
            i_res.res-> m_l = 12;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg14[k];
            }
            break;
        case 305:
            i_res.res-> m_l = 9;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg15[k];
            }
            break;
        case 306:
            i_res.res-> m_l = 6;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg16[k];
            }
            break;
        case 307:
            i_res.res-> m_l = 18;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg17[k];
            }
            break;
        case 400:
            i_res.res-> m_l = 11;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg18[k];
            }
            break;
        case 401:
            i_res.res-> m_l = 12;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg19[k];
            }
            break;
        case 402:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg20[k];
            }
            break;
        case 403:
            i_res.res-> m_l = 9;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg21[k];
            }
            break;
        case 404:
            i_res.res-> m_l = 9;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg22[k];
            }
            break;
        case 405:
            i_res.res-> m_l = 18;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg23[k];
            }
            break;
        case 406:
            i_res.res-> m_l = 14;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg24[k];
            }
            break;
        case 407:
            i_res.res-> m_l = 29;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg25[k];
            }
            break;
        case 408:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg26[k];
            }
            break;
        case 409:
            i_res.res-> m_l = 8;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg27[k];
            }
            break;
        case 410:
            i_res.res-> m_l = 4;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg28[k];
            }
            break;
        case 411:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg29[k];
            }
            break;
        case 412:
            i_res.res-> m_l = 19;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg30[k];
            }
            break;
        case 413:
            i_res.res-> m_l = 24;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg31[k];
            }
            break;
        case 414:
            i_res.res-> m_l = 20;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg32[k];
            }
            break;
        case 415:
            i_res.res-> m_l = 22;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg33[k];
            }
            break;
        case 416:
            i_res.res-> m_l = 31;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg34[k];
            }
            break;
        case 417:
            i_res.res-> m_l = 18;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg35[k];
            }
            break;
        case 500:
            i_res.res-> m_l = 21;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg36[k];
            }
            break;
        case 501:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg37[k];
            }
            break;
        case 502:
            i_res.res-> m_l = 11;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg38[k];
            }
            break;
        case 503:
            i_res.res-> m_l = 19;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg39[k];
            }
            break;
        case 504:
            i_res.res-> m_l = 15;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg40[k];
            }
            break;
        case 505:
            i_res.res-> m_l = 26;
            for ( k=0; k<i_res.res->m_l; k++){
                i_res.res->message_code[k] = msg41[k];
            }
            break;
    }
}
