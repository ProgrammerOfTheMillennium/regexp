#include "t006.h"

#include <iostream>
#include <stdio.h>

#define PATH "statistics_raw_data.txt"

uint8_t* get_data() {
    FILE *file;
    file = fopen(PATH, "r");

    size_t fread(void *ptr, size_t size_of_elements,
                        size_t number_of_elements, FILE *a_file);

    fclose(file);
    return ptr;
}

int main(void)
{

}