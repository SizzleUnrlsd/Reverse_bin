#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void
md5_to_string(unsigned char *md5, char *output)
{
    for (int i = 0; i < EVP_MD_size(EVP_md5()); i++) {
        sprintf(output + i * 2, "%02x", md5[i]);
    }
}

void
ascii_to_md5(const char *input, unsigned char *output)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), NULL);
    EVP_DigestUpdate(ctx, input, strlen(input));
    EVP_DigestFinal_ex(ctx, output, NULL);
    EVP_MD_CTX_free(ctx);
    return;
}

char *
md5(const char *input)
{
    unsigned char md5_hash[EVP_MAX_MD_SIZE];
    ascii_to_md5(input, md5_hash);

    char *md5_str = malloc((EVP_MAX_MD_SIZE * 2) + 1);
    md5_to_string(md5_hash, md5_str);
    return strdup(md5_str);
}

