#include "t006.h"

#include <iostream>
#include <stdio.h>

#define PATH "statistics_raw_data.txt"

uint8_t* MeasureUnit::get_data() {
    FILE *file;
    file = fopen(PATH, "r");
    
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t data_raw[file_size];
    fread(data_raw, 1, file_size, file);

    fclose(file);
    return data_raw;
}

int main(void)
{
    
}