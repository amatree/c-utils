#ifndef ANYTOHDR_SRC_H
#define ANYTOHDR_SRC_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ATH_ASSERT_RUN(expression, callback) { if (expression) { callback; } }

#define ATHS_FILE_MASK          0xF0
#define ATHS_SUCCESS            0U
#define ATHS_FAILURE            1U
#define ATHS_NOT_EXIST          2U
#define ATHS_EMPTY_BUFFER       3U
#define ATHS_NULL_PTR           4U

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef struct anytohdr_t {
    char in_file[252];          // File name
    char out_file[252];         // Out file name
    char var_name[252];         // In header variable name
    char *buffer;               // Data buffer
    u64 len;                    // Buffer length
} anytohdr_t;

u32 any_to_hdr(anytohdr_t *ath);

#endif
