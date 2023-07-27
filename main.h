#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>


#define READ_BUF_SIZE 1024
#define WR_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststring - sigly linked list
 * @n: number
 * @str: str
 * @next: ptr
*/

typedef struct liststring
{
	int n;
	char *str;
	struct liststring *next;
} str_t;

/**
 * struct info_str - countains two str
 * @arg: str
*/

typedef struct info_str
{
	char *arg;
	char **argv;
	int *path;
	int argc;
	unsigned int l_count;
	int err_n;
	int lcount_fg;
	char *fn;
	str_t *env;
	str_t *hst;
	str_t *alias;
	char **environ;
	int env_ch;
	int st;

	char **cmd_buf;
	int cmd_buf_t;
	int rd_fn;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL,0 ,0 ,0 ,0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

typedef struct bitlin
{
	char *t;
	int (*fun)(info_t *);
} bit_t;


/* str_funct_.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *strts(const char *, const char *);
char *_strcat(char *, char *);

/* str_funct_2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void puts(char *);
int _putchar(char);

/* str_funct_3.c */
char *_strcpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* str_funct_4.c */
char **strtow(char *, char *);

/* mem_funct */
char *_memset(char *, unsigned int);
void frees(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* mem_funct_2 */
int ndfrees(void **);

/* other_funct */
int intctv(info_t *);
int _delim(char, char *);
int _alpha(int);
int _atoi(char *);

/* other_funct_2 */
void pr_err(info_t *, char *);
int _erroratoi(char *);
int pr_d(int, int);
char *conv_num(long int, int, int);
void rm_comments(char *);

/* str.c */
str_t _nd(str_t **, const char *, int);
size_t pr_list(const str_t *);
str_t *nd_strt(str_t *, char *, char);
ssize_t get_nd_index(str_t *, str_t *);

/* str_2.c */
size_t l_lenght(const str_t *);
char **list_str(str_t *);
size_t pr_list(const str_t *);
str_t nd_strt(str_t *, char *, char);
ssize_t get_nd_index(str_t *, str_t *);

/* error_funct.c */
void _iputs(char *);
int _iputchar(char);
int _putsfile(char *, int);

