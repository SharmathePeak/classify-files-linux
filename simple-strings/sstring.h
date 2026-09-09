#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *str;
} string;

int stringlen(const char *text);
void stringinp(string *s);
void printstr(string *s);
void strings(const char *raw_text, string *s);
void strcomb(string *s, const char *part);
void strappend(string *s, const char *raw_text);
void stringrev(string *s);
int stringfind(string *s, const char *find);
int stringcomp(const char *one, const char *two);
