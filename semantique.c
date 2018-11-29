#include "etape3.h"

void semantique(char *c, int l) {
    parseur(c, l, "connection", est_connection_restr);
    parseur(c, l, "date1", est_date1_restr);
    parseur(c, l, "day", est_day_restr);
    parseur(c, l, "hour", est_hour_restr);
    parseur(c, l, "method", est_method_restr);
    parseur(c, l, "minute", est_minute_restr);
    parseur(c, l, "pragma", est_pragma_restr);
    parseur(c, l, "second", est_second_restr);
}
