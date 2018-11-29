#include "etape3.h"

/*verification des ressources allouées*/
int verif_Resource(struct ReqInfo * reqinfo) {
    normalisationURL(reqinfo->resource);
	strcat(server_root, reqinfo->resource);
    return open(server_root, O_RDONLY);
}
