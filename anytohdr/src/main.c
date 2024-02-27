#include <stdio.h>
#include "anytohdr.h"

int main() 
{
    anytohdr_t ath = {
        .in_file = "example.txt"
    };

    printf("\nResult: %u\n", any_to_hdr(&ath));
    return 0;
}
