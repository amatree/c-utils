#ifndef FILE_EXT_H
#define FILE_EXT_H

#include <stdint.h>
#include <string.h>

typedef uint8_t u8;

u8 strip_ext(char *fname);
void make_path_safe(char *path);

#endif