#include <stdio.h>
#include <string.h>
#include "anytohdr.h"

int main(int argc, char const *argv[]) 
{
    anytohdr_t ath;
    if (argc > 1)
    {
        strncpy(ath.in_file, argv[1], 252);
    } else {
        strncpy(ath.in_file, "./example.txt", 252);
        // printf("No input file.\n");
        // return 1;
    }

    printf("Processing file %s...\n", ath.in_file);
    printf("Result: %u\n", any_to_hdr(&ath));
    return 0;
}
