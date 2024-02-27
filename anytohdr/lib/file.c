#include "file.h"
#include <string.h>

u8 strip_ext(char *fname) {
  char *end = fname + strlen(fname);
  u8 cnt = 0;

  while (end > fname && *end != '.') {
    --end;
    cnt++;
  }

  if (end > fname) {
    *end = '\0';
  }

  return strlen(fname);
}

void make_path_safe(char *path) {
  char forbidden_chars[] = "\\/:*?\"<>|";

  // Replace forbidden characters with underscores
  for (int i = 0; i < strlen(forbidden_chars); ++i) {
    char *forbidden_char = strchr(path, forbidden_chars[i]);
    while (forbidden_char != NULL) {
      *forbidden_char = '_';
      forbidden_char = strchr(forbidden_char + 1, forbidden_chars[i]);
    }
  }
}