#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void rmv_nwline(char *str);
void run_command(char **args, char **env, int *keep_running);
char **_strtok(char *str, char *delim);
ssize_t _getline(char **str, size_t *n, FILE *stream);
char *_getenv(char *arg, char **env);
char *validate_command(char *str, char **env);

#endif
