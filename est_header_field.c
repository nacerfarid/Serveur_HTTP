#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "abnf.h"

int est_header_field(char *c, int l, char *s, int ls, void (*callback)()) {
    char S[] = "header_field";
    int i_search = 0;
    if (ls == 12) {
        while (i_search < ls && s[i_search] == S[i_search]) {
            i_search++;
        }
        if (i_search == ls) {
            callback(c, l);
        }
    }
    int i = (est_connection_header(c,l, s, ls, callback) || est_content_length_header(c,l, s, ls, callback) || est_trailer_header(c,l, s, ls, callback) || est_transfer_encoding_header(c,l, s, ls, callback));
    int i2 = (est_upgrade_header(c,l, s, ls, callback) || est_via_header(c,l, s, ls, callback) || est_age_header(c,l, s, ls, callback) || est_expires_header(c,l, s, ls, callback));
    int i3 = (est_date_header(c,l, s, ls, callback) || est_location_header(c,l, s, ls, callback) || est_retry_after_header(c,l, s, ls, callback) || est_vary_header(c,l, s, ls, callback));
    int i4 = (est_warning_header(c,l, s, ls, callback) || est_cache_control_header(c,l, s, ls, callback) || est_expect_header(c,l, s, ls, callback) || est_host_header(c,l, s, ls, callback) || est_max_forwards_header(c,l, s, ls, callback) || est_pragma_header(c,l, s, ls, callback));
    int i5 = (est_range_header(c,l, s, ls, callback) || est_te_header(c,l, s, ls, callback) || est_if_match_header(c,l, s, ls, callback) || est_if_none_match_header(c,l, s, ls, callback));
    int i6 = (est_if_modified_since_header(c,l, s, ls, callback) || est_if_unmodified_since_header(c,l, s, ls, callback) || est_if_range_header(c,l, s, ls, callback) || est_accept_header(c,l, s, ls, callback));
    int i7 = (est_accept_charset_header(c,l, s, ls, callback) || est_accept_encoding_header(c,l, s, ls, callback) || est_accept_language_header(c,l, s, ls, callback) || est_authorization_header(c,l, s, ls, callback));
    int i8 = (est_proxy_authorization_header(c,l, s, ls, callback) || est_referer_header(c,l, s, ls, callback));
    int i9 = (est_user_agent_header(c,l, s, ls, callback) );
    int deb=0;
    int esp=l-1;
    int indice;
    int test = 0;

    int rep = i || i2 || i3 || i4 || i5 || i6 || i7 || i8 || i9;
    if (rep) {
        return 1;
    }

    while (deb<=l && c[deb]!=':'){
        deb =deb+1;
    }
    if (deb==l){
        return 0;
    }
    else {
        indice =est_field_name(c,deb, s, ls, callback);
    }
    deb++;
    while (deb<l && (c[deb] == ' ' || c[deb] == 9)){
        deb++;
    }

    while (esp>=0 && (c[esp] == ' ' || c[esp] == 9)){
        esp--;
    }
    indice= indice && est_field_value(c + deb * sizeof(char),1 + esp-deb, s, ls, callback);
    return indice;
}
