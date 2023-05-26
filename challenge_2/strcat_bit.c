#include <stdio.h>
#include <string.h>

void
strcat_bit(char *dest, const char *src)
{
    char temp = 0;
    char carry = 0;
    while (*dest) {
        dest++;
    }
    while (*src) {
        temp = *src;
        carry = *dest;
        while (temp) {
            carry = *dest ^ temp;
            temp = *dest & temp;
            temp <<= 1;
            *dest = carry;
        }
        dest++;
        src++;
    }
    *dest = '\0';
}
