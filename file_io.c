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

/**
 * @brief Loads vectors from a file
 * @param filename name of file to load from
 * @return list of vectors read from file
*/
vector* load(char* filename)
{
    return NULL;
}

/**
 * @brief Saves vectors to a file
 * @param filename name of file to save to
 * @param v_list list of vectors to save
 * @param size size of vector list
 * @return 0 if successful, -1 if error
*/
int save(char* filename, vector* v_list, int size)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }
    fprintf(file, "Vector, x, y, z\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s, %f, %f, %f\n", (v_list + i)->name, (v_list + i)->x, (v_list + i)->y, (v_list + i)->z);
    }
    fclose(file);
    return 0;
}