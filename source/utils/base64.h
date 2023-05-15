/*  -------------------------------------------------------------
    Base64 - RFC 1341
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    Description:    Base64 helper functions
    Author:         Jouni Malinen <j@w1.fi>
    License:        BSD-2-Clause
    Source:         This version has been extracted from FreeBSD
                    source code - src/contrib/wpa/src/utils/base64.h
    Commit source:  0a6760a1de32bf5df91ef926eba25b3f74b4f84f
    -------------------------------------------------------------    */

char * base64_encode(const void *src, size_t len, size_t *out_len);
unsigned char * base64_decode(const char *src, size_t len, size_t *out_len);
