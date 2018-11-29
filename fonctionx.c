#include "etape3.h"
int fonctionx() {
    int i = fonction3();
    if (i == -2) {
        i_res.res->code = 411; /*Juste ?*/
    }
    else if (i >= 0) {
        return i;
    }
    else { /* i = -1 ie on est pas dans le bon "cadre" pour statuer de la longueur du message_body*/
        
        i = fonction4();
        if (i == -2) {
            i_res.res->code = 411; /*Juste ?*/
        }
        else if (i >= 0) {
            return i;
        }
        
        else {
            i = fonction56();
            
            return i;
            }
        
    }
}
