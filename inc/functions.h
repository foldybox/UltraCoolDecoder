// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include "enums.h"
#include "structs.h"

// Library functions
unsigned int mx_strlen(const char *);
bool mx_isdigit(int);
bool mx_isminus(char);
int mx_pow(int, unsigned int);
char *mx_strnew(const int);
char *mx_strcpy(char *, const char *);
char *mx_strjoin(char const *, char const *);
void mx_strdel(char **);
bool mx_isspace(char);
char *mx_strnew(const int);
char *mx_strncpy(char *, const char *, int);
char *mx_strtrim(const char *);
int mx_count_of_matches(char *, char);
void mx_printchar(char);
void mx_printint(int);
void mx_printstr(const char *str);

// Args functions
t_args args_init(char *argv[]);
void args_calculation(t_args args);
void args_free(t_args *args);

// Error function
void raise_error(t_error error, char *arg);


#endif
