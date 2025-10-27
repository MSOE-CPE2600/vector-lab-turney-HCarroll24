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
#include <string.h>
#include <stdlib.h>

/**
 * @brief loads vectors from a file
 * @param filename name of file to load from
 * @param list pointer to VectorList (will be updated)
 * @return 0 if successful, 1 if error
*/
int load(char* filename, VectorList* list)
{
    // Checking for invalid input
    if (filename == NULL || list == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }

    // Open file for reading
    FILE *file_ptr = fopen(filename, "r");

    // Check for error opening file
    if (!file_ptr) {
        printf("Error: File does not exist %s\n", filename);
        return 1;
    }

    // Count how many data lines in file
    int size = 0;
    char line[256];
    while (fgets(line, 256, file_ptr) != NULL) {
        if (line[0] != '\n' && line[0] != '\0') {
            size = size + 1;
        }
    }

    // Check if file has any data
    if (size == 0) {
        printf("Warning: File %s contains no valid vector data\n", filename);
        fclose(file_ptr);
        return 1;
    }

    // Free existing memory if any
    if (list->data != NULL) {
        free(list->data);
    }
    
    // Allocate memory for list
    list->data = (vector*)malloc(size * sizeof(vector));
    if (!list->data) {
        printf("Error: Memory allocation failed\n");
        fclose(file_ptr);
        return 1;
    }
    
    // Set capacity and reset count
    list->capacity = size;
    list->count = 0;

    // Go back to the beginning of the file
    rewind(file_ptr);

    // Read each line of file and add vectors to list
    int index = 0;
    int total_lines = 0;
    int valid_lines = 0;
    
    while (fgets(line, 256, file_ptr) != NULL) {
        // Skip empty lines
        if (line[0] == '\n' || line[0] == '\0') {
            continue;
        }
        
        total_lines++;
        
        char name[10];
        float x, y, z;
        int parsed = sscanf(line, "%[^,], %f, %f, %f", name, &x, &y, &z);
        
        // Check if line has exactly 4 values (name, x, y, z)
        if (parsed == 4) {
            strcpy(list->data[index].name, name);
            list->data[index].x = x;
            list->data[index].y = y;
            list->data[index].z = z;
            list->count++;
            index++;
            valid_lines++;
        } else {
            // Found incorrectly formatted line - abort loading
            printf("Error: Incorrectly formatted CSV file\n");
            printf("Expected format: name, x, y, z\n");
            fclose(file_ptr);
            return 1;
        }
    }
    
    // Check if file had any data lines
    if (total_lines == 0) {
        printf("Error: File contains no data\n");
        fclose(file_ptr);
        return 1;
    }

    // Close file
    fclose(file_ptr);

    // Return success
    return 0;
}

/**
 * @brief saves vectors to a file
 * @param filename name of file to save to
 * @param list pointer to vector list
 * @param size size of vector list
 * @return 0 if successful, 1 if error
*/
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

    // Return success
    return 0;
}