#include <string.h>
#include "anytohdr.h"
#include "file.h"

u32 any_to_hdr(anytohdr_t *ath) {
  ATH_ASSERT_RUN(NULL == ath, return ATHS_NULL_PTR);
  ATH_ASSERT_RUN(strlen(ath->in_file) == 0, return ATHS_FAILURE);

  FILE *fp_in, *fp_out;

  fopen_s(&fp_in, ath->in_file, "rb");
  ATH_ASSERT_RUN(NULL == fp_in, return ATHS_NOT_EXIST | ATHS_FILE_MASK);

  // get total size of the file
  fseek(fp_in, 0, SEEK_END);
  u32 fsize = ftell(fp_in);
  ath->len = fsize;
  ATH_ASSERT_RUN(fsize == 0, return ATHS_EMPTY_BUFFER | ATHS_FILE_MASK);
  fseek(fp_in, 0, SEEK_SET);

  // copy read in file data to buffer
  char *buffer = malloc(fsize + 1);
  ATH_ASSERT_RUN(NULL == buffer, return ATHS_FAILURE);
  ATH_ASSERT_RUN(NULL != ath->buffer, {
    free(ath->buffer);
    return ATHS_FAILURE;
  });
  ath->buffer = buffer;
  fread(buffer, fsize, 1, fp_in);
  fclose(fp_in);

  // set last char to null-terminator
  buffer[fsize] = '\0';

  // ensure outfile is declared
  ATH_ASSERT_RUN(strlen(ath->out_file) == 0, {
    memcpy(ath->out_file, ath->in_file, strlen(ath->in_file));
  });

  // strip the current file extension and add .h
  u8 cnt = strip_ext(ath->out_file);
  memcpy(&ath->out_file[cnt], &".h", 3);

  /**
   * Open out file now and prepare to write.
   */
  fopen_s(&fp_out, ath->out_file, "w");
  ATH_ASSERT_RUN(NULL == fp_out, return ATHS_NULL_PTR | ATHS_FILE_MASK);

  // assign variable name if not already
  ATH_ASSERT_RUN(strlen(ath->var_name) == 0,
  {
    memcpy(ath->var_name, ath->in_file, strlen(ath->in_file));
    u8 cnt = strip_ext(ath->var_name);
    memcpy(&ath->var_name[cnt], &"_data", 6);
  });
  

  return ATHS_SUCCESS;
}