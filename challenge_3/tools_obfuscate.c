#include <stdio.h>
#include <string.h>

void obfuscate(char *str, int len, const char *key)
{
    int key_len = strlen(key);
    for (int i = 0; i < len; i++) {
        str[i] ^= key[i % key_len];
    }
}

int
main(void)
{
    char str[] = "01000101010100000100100101000011010101000100011001111011";
    obfuscate(str, strlen(str), "CTF_FLAG_HERE");
    printf("%s\n", str);
    return 0;
}