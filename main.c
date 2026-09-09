
#include "simple-strings/sstring.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *ifile = fopen("ls.txt", "r");
  char *line = NULL;
  size_t len;
  ssize_t read;
  string s;

  if (ifile == NULL) {
    return 159;
  }

  int linenum = 0;
  if (argc >= 2) {
    while ((read = getline(&line, &len, ifile)) != -1) {
      strings(line, &s);
      if (stringfind(&s, argv[1]) >= 0) {
        printf("%s", line);
        break;
      }
      linenum++;
      free(s.str);
    }
    return linenum + 1;
  }
  free(ifile);
  free(line);
  return 144;
}
