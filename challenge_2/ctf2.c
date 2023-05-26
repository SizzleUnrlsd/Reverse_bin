/*
** EPITECH PROJECT, 2023
** ctf
** File description:
** ctf2
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#define LOG_L "001100100011000100110010001100110011001001100110001100100011100100110111011000010011010100110111011000010011010101100001001101110011010000110011001110000011100100110100011000010011000001100101001101000110000100111000001100000011000101100110011000110011001100001010"
#define LOG_P "011000100011010001100010001110000110010001100001011001100011010001100010001110000110010101100001001110010110010000110011001110010011010100110110001110000011011100110001001110010110010100110001011001010011001100110010001100000011000000110111001101100110011000001010"
#define LOG_LL "010001010101000001001001010000110101010001000110"
#define LOG_PP "50 73 20 3A 20 74 6F 75 74 65 20 6C 61 20 70 68 72 61 73 65"

char *md5(const char *input);
char *binary_to_ascii(const char *binary_string);
void strcat_bit(char *dest, const char *src);

typedef struct password_s {
    char *log;
    char *pass_log;
} password_t;

void
pflush(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    fflush(stdout);
    return;
}

void
set_psswd(password_t **struct_psswd)
{
    struct_psswd[0]->log = LOG_L;
    struct_psswd[0]->pass_log = LOG_P;
    return;
}

int
xnor(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] ^ s2[i];
        } else if (s1[i] == '\0') {
            return (EXIT_SUCCESS);
        }
    }
    return (EXIT_SUCCESS);
}

void
resize_line(char **line)
{
    size_t len = strlen(*line);
    (*line)[len - 1] = '\0';
    return;
}

int
get_stdint(char *name, ssize_t *nread, size_t *len, char **line)
{
    pflush("%s", name);
    (*nread) = getline(line, len, stdin);
    if ((*nread) == -1) {
        exit(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int
main(int ac, char **av)
{
    char *line_log_buf = NULL;
    char *line_psswd_buf = NULL;
    char *line_log = NULL;
    char *line_psswd = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    password_t *struct_psswd = malloc(sizeof(password_t));
    if (struct_psswd == NULL) {
        return (EXIT_FAILURE);
    }
    set_psswd(&struct_psswd);
    get_stdint("> login : ", &nread, &len, &line_log_buf);
    get_stdint("> password : ", &nread, &len, &line_psswd_buf);
 
    size_t len_log = strlen(line_log_buf);
    size_t len_psswd = strlen(line_psswd_buf);

    if (strcmp("\n", line_log_buf) == 0 || strcmp("\n", line_log_buf) == 0)
        return (EXIT_FAILURE);

    line_log_buf[len_log - 1] = '\0';
    line_psswd_buf[len_psswd - 1] = '\0';

    line_log =  md5(line_log_buf);
    line_psswd =  md5(line_psswd_buf);

    if (nread == -1) {
        exit(EXIT_FAILURE);
    }

    resize_line(&line_log);
    resize_line(&line_psswd);
    if (xnor(line_log, binary_to_ascii(struct_psswd->log), len_log - 1) == 0) {
        if (xnor(line_psswd, binary_to_ascii(struct_psswd->pass_log), len_psswd - 1) != 0) {
            pflush("Bad password -> %s\n", line_log_buf);
            return (EXIT_FAILURE);
        } else {
            
            pflush("%s\n", LOG_LL);
            pflush("{");
            pflush("%s\n", LOG_L);
            pflush("%s\n", LOG_P);
            pflush("}");
            return (EXIT_SUCCESS);
        }
    } else {
        pflush("Bad password -> %s\n", line_log_buf);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
