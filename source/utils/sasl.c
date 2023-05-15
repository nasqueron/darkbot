/*  -------------------------------------------------------------
    SASL PLAIN authentication
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    Description:    SASL plain authentication to solve T1739
    License:        BSD-2-Clause
    -------------------------------------------------------------    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "base64.h"

/*  -------------------------------------------------------------
    SASL plain authentication
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    */

/**
 * Build a SASL PLAIN string, encoded in Base64
 * @identity: The identity you want to authenticate as
 * @username: The username
 * @password: The password, in plain
 * Returns: Allocated buffer of encoded data or %NULL on failure
 *
 * If the specification isn't clear what to use as identity, generally
 * you can pass again the username. If not, pass an empty string.
 *
 * Caller is responsible for freeing the returned buffer. Returned buffer is
 * nul terminated to make it easier to use as a C string.
 */
char* build_sasl_plain_string(char* identity, char* username, char* password) {
    // Authentication string: concatenate the fields, with 2 NUL separator
    // A lot of string.h functions stop at NUL character, so memcpy is safer.
    // For example, with sprintf, only identity is copied to sasl_plain_string.
    int identity_len = strlen(identity);
    int username_len = strlen(username);
    int password_len = strlen(password);

    int sasl_plain_string_len = identity_len + username_len + password_len + 2;
    char* sasl_plain_string = (char*) malloc(sasl_plain_string_len + 1);

    char* buffer = sasl_plain_string;

    memcpy(buffer, identity, identity_len);
    buffer += identity_len;
    *buffer++ = '\0';

    memcpy(buffer, username, username_len);
    buffer += username_len;
    *buffer++ = '\0';

    memcpy(buffer, password, password_len);
    buffer += password_len;
    *buffer++ = '\0';

    // Base64 encode
    char* result = base64_encode(sasl_plain_string, sasl_plain_string_len, NULL);

    free(sasl_plain_string);

    return result;
}
