#include "sstring.h"
#include <stdio.h>
#include <stdlib.h>

int stringlen(const char *text) {
  int size = 0;
  char ch;
  while ((ch = text[size]) != '\0') {
    size++;
  }
  return size;
}

void stringinp(string *s) {
  int size = 0;
  s->str = malloc(sizeof(char) * (size + 2));
  char ch;
  while ((ch = getchar()) != '\n' && (ch != EOF)) {
    char *temp = realloc(s->str, sizeof(char) * (size + 2));
    if (temp != NULL) {
      s->str = temp;
    }
    s->str[size] = ch;
    size++;
    s->str[size] = '\0';
  }
}

void printstr(string *s) { printf("%s", s->str); }

void strings(const char *raw_text, string *s) {
  int length = 0;
  char ch = ' ';
  while ((ch = raw_text[length]) != '\0') {
    length++;
  }
  s->str = malloc(sizeof(char) * (length + 2));
  for (int i = 0; i <= length; i++) {
    s->str[i] = raw_text[i];
  }
}

void strcomb(string *s, const char *part) {
  string strpart;
  strings(part, &strpart);
  printf("%s%s", s->str, strpart.str);
}

void strappend(string *s, const char *raw_text) {
  int length = stringlen(raw_text);
  int start = stringlen(s->str);
  char *temp = realloc(s->str, sizeof(char) * (start + length));
  if (temp != NULL) {
    s->str = temp;
  }
  for (int i = 0; i <= length; i++) {
    s->str[start + i] = raw_text[i];
  }
}

void stringrev(string *s) {
  for (int len = stringlen(s->str); len >= 0; len--) {
    printf("%c", s->str[len]);
  }
}

int stringfind(string *s, const char *find) {
  int findlen = stringlen(find);
  int ans = 0;
  int match = 0;
  if (findlen <= stringlen(s->str)) {
    while (match == 0 && (ans + findlen) < stringlen(s->str)) {
      match = 1;
      for (int i = 0; i < findlen; i++) {
        if (s->str[ans + i] != find[i]) {
          match = 0;
          break;
        }
      }
      ans++;
    }
    return match ? ans : -1;
  }
  return -1;
}

int stringcomp(const char *one, const char *two) {
  int compres = 0;
  if (stringlen(one) == stringlen(two)) {
    for (int i = 0; i < stringlen(one); i++) {
      if (one[i] != two[i]) {
        compres = 0;
        return compres;
      }
      compres = 1;
    }
  } else {
    compres = 0;
  }
  return compres;
}
