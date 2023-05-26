#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
binary_to_ascii(const char *binary_string)
{
    size_t len = strlen(binary_string);
    if (len % 8 != 0) {
        return NULL;
    }
    size_t ascii_len = len / 8;
    char *ascii_string = malloc(ascii_len + 1);
    if (ascii_string == NULL) {
        return NULL;
    }
    ascii_string[ascii_len] = '\0';
    for (size_t i = 0; i < ascii_len; i++) {
        char ascii_char = 0;
        for (size_t j = 0; j < 8; j++) {
            if (binary_string[i*8+j] == '1') {
                ascii_char |= (1 << (7 - j));
            }
        }
        ascii_string[i] = ascii_char;
    }
    return ascii_string;
}
