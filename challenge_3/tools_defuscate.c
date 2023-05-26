#include <stdio.h>
#include <string.h>

#include <stdlib.h>

char *
deobfuscate(char* str, int len, const char* key)
{
    char* deobfuscated_str = malloc(len + 1);
    if (deobfuscated_str == NULL) {
        return NULL;
    }
    int key_len = strlen(key);
    for (int i = 0; i < len; i++) {
        deobfuscated_str[i] = str[i] ^ key[i % key_len];
    }
    deobfuscated_str[len] = '\0';
    return deobfuscated_str;
}

