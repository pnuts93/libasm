#ifndef TEST_H
#define TEST_H

#include "libasm.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void	print_result(int res);
void	unit_strlen(void);
void	unit_strcpy(void);
void	unit_strcmp(void);
void	unit_write(void);
void	unit_read(void);
void	unit_strdup(void);

#endif