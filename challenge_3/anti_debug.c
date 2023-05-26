#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
IsDebuggerPresent(void)
{
    char buf[1024];
    FILE* fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        return 0;
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (strncmp(buf, "TracerPid:", 10) == 0) {
            int pid = atoi(buf + 11);
            if (pid != 0) {
                fclose(fp);
                return 1;
            }
            break;
        }
    }
    fclose(fp);
    return 0;
}
