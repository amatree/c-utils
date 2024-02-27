# Any-to-Hdr C Project (WIP)

Convert any file into header file as byte representation. Useful when importing images, font, other data file format that otherwise required flashing onto memory.

# Usage

Example:

```c
#include <stdio.h>
#include "anytohdr.h"

int main() 
{
    anytohdr_t ath = {
        .in_file = "example.txt",
        .out_file = "example_data.h"
    };

    printf("\nResult: %u\n", any_to_hdr(&ath));
    return 0;
}
```
