/*************************************************************************
 * @file file_io.c
 * @brief Implementation of save and load functions
 *
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignment: Lab7
*************************************************************************/
#include "file_io.h"
#include "vector.h"
#include <stdio.h>

vector* load(char* filename)
{
    return NULL;
}

int save(char* filename, vector* list, int size)
{
    // Checking for invalid input
    if (filename == NULL || list == NULL || size <= 0) {
        printf("Error: Invalid input\n");
        return 1;
    }
    
    // Open file for writing
    FILE *file_ptr = fopen(filename, "w");
    // Check for error opening/creating file
    if (!file_ptr) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Write header line for .csv file
    fprintf(file_ptr, "Name, X, Y, Z\n");
    
    // Write each vector in list to file
    for (int i = 0; i < size; i++) {
        float x = list[i].x;
        float y = list[i].y;
        float z = list[i].z;
        fprintf(file_ptr, "%s, %f, %f, %f\n", list[i].name, x, y, z);
        if (ferror(file_ptr)) {
            printf("Error: Could not write to file %s\n", filename);
            return 1;
        }
    }

    // Close file
    fclose(file_ptr);
    return 0;
}