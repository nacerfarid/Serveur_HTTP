#include "etape3.h"
int compare(char *c, int l, char *c2, int l2) {
    int i;
    if (l != l2) {
        return 0;
    }
    for (i=0;i<l;i++) {
        if (c[i] != c2[i]) {
            return 0;
        }
    }
    return 1;
}
