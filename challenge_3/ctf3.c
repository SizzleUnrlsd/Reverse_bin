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
#include <sys/ptrace.h>

#define LOG_L "sewov}qwoytburdwow}qwnyubtrdvow}qvnxuburdvnw|qvnxtcusevnv|pvoxtcurevow}qwnyubtsevnw|qvoyubtrdvnw|pvoxtbusdwnv|qvoxtcusdwov}pwoyubtrdvow|qwnytburdvnw|qvoxuctsewnv|pvoyucusewnv|qwoytcusevow}qvnxuctsdwov|qvnxubusdwnw|qwoxtcurevov}pvoxuburewov|qwnyubtrdwnv|pvo"
#define LOG_P "sdwnv|qwoytbusevow}qwoxtbtrdvnv}qvnxuburdvnw|qvoxtcusewov|pvoxuburevov|pwnyubtsevow}qwnxubtrdvov|qvnxubtsdwnv}qvoxtcusdvow}qwnxubtrdvow|qwnyuctrdvnw}qwoxtcusewov|pvoyucusewnv|qwnyuburevnw|qvoxuctsdwov|pvoxubtsewov|pvoxtcurdvov}pwnxuburevow|qvnxuburdvnw}qwn"
#define LOG_LL "sevov}qvoyucusdvow|qvoxtbtsdvow}qvoyucusdwov|pvoxtctrdwn"
#define SUPER "sdwnw|qvoxtcurevov}pwoxtburevnv}qwnytburdvnw|qvoxtcusdwnv|pvoxtcusewow}pwoytburevow}qwoyuctsdwow|qvnyubusdwnv}qvoxtcusdwov}pwoytbtrdvnv}qwnytbusdvnw|qwnxtcusdwnv}pwoxucurevow|pwoytbtrevow}qwnyubtrevow|pvoxubtsdwnv|pvoxtcurevow}qwoxtburevnw}qvnxucusdvnw}qwn"
#define LOG_PP "7D"

char *md5(const char *input);
char *binary_to_ascii(const char *binary_string);
void strcat_bit(char *dest, const char *src);
int IsDebuggerPresent(void);
char *deobfuscate(char* str, int len, const char* key);

typedef struct password_s {
    char *log;
    char *pass_log;
} password_t;

void
check_dbg(void)
{
    if (ptrace(PTRACE_TRACEME, 0) < 0) {
        printf("\"DEBUGGER IS NOT ALLOWED\"\n");
        exit(1);
    }
    return;
}

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
    struct_psswd[0]->log = deobfuscate(LOG_L, strlen(LOG_L), "CTF_FLAG_HERE");
    struct_psswd[0]->pass_log = deobfuscate(LOG_P, strlen(LOG_P), "CTF_FLAG_HERE");
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
    check_dbg();
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

    if (strcmp("\n", line_log_buf) == 0 || strcmp("\n", line_log_buf) == 0) {
        return (EXIT_FAILURE);
    }
    size_t len_log = strlen(line_log_buf);
    size_t len_psswd = strlen(line_psswd_buf);

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
            pflush("%s", deobfuscate(LOG_LL, strlen(LOG_LL), "CTF_FLAG_HERE"));
            pflush("%s", deobfuscate(SUPER, strlen(SUPER), "CTF_FLAG_HERE"));
            pflush("%s\n", LOG_PP);
            return (EXIT_SUCCESS);
        }
    } else {
        pflush("Bad password -> %s\n", line_log_buf);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}