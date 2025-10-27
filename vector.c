/********************************************************************
 * @file vector.c
 * @brief Implementation and definitions of functions for vector
 *
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignent: Lab 5
********************************************************************/
#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief gets size of vector list
 * @param list pointer to VectorList
 * @return size of vector list
*/
int get_size(VectorList* list)
{
    return list->count;
}

/**
 * @brief Computes addition of two vectors
 * @param a first vector
 * @param b second vector
 * @return addition of a and b
*/
vector add(vector a, vector b)
{
    vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;

}

/**
 * @brief Computes subtraction of two vectors
 * @param a first vector
 * @param b second vector
 * @return subtraction of a and b
*/
vector sub(vector a, vector b)
{
    vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

/**
 * @brief Computes scalar multiplication of a vector
 * @param s scalar
 * @param a vector
 * @return scalar multiplicaiton of s and a
*/
vector smult(float s, vector a)
{
    vector result;
    result.x = s * a.x;
    result.y = s * a.y;
    result.z = s * a.z;
    return result;
}

/**
 * @brief Computes dot product of two vectors
 * @param a first vector
 * @param b second vector
 * @return dot product of a and b
*/
float dotprod(vector a, vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
 * @brief Computes cross product of two vectors
 * @param a first vector
 * @param b second vector
 * @return cross product of a and b
*/
vector crossprod(vector a, vector b)
{
    vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

/**
 * @brief Adds new vector to storage array. If same name exists, replace
 * otherwise add to empty location. If full do nothing and return error
 * @param list pointer to VectorList
 * @param new Vector to add
 * @return 0 if successful, 1 if full
*/
int addvect(VectorList* list, vector new)
{
    // Check if vector with same name already exists
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->data[i].name, new.name) == 0) {
            list->data[i] = new;
            return 0;
        }
    }
    
    // Check if we need to allocate or reallocate memory
    if (list->data == NULL) {
        // First allocation
        list->data = (vector*)malloc(sizeof(vector));
        if (!list->data) {
            printf("Error: Memory allocation failed\n");
            return 1;
        }
        list->capacity = 1;
    } else if (list->count >= list->capacity) {
        // Need to grow the array
        list->capacity *= 2;  // Double the capacity
        vector* temp = (vector*)realloc(list->data, list->capacity * sizeof(vector));
        if (!temp) {
            printf("Error: Memory reallocation failed\n");
            return 1;
        }
        list->data = temp;
    }
    
    // Add the new vector
    list->data[list->count] = new;
    list->count++;
    return 0;
}

/**
 * @brief Display help message to user for summary of uses
 * @return 0 to exit
*/
int help()
{
    printf("Vector Operations Functions\n");
    printf("Commands: quit, clear, list, help, save, load\n");
    printf("Operations: \n");
    printf("\tAdd: var1 + var2\n");
    printf("\tSub: var1 - var2\n");
    printf("\tScalar Mult: scalar * var1\n");
    printf("\tDot Product: var1 . var2\n");
    printf("\tCross Product: var1 x var2\n");
    printf("\tTo add a vector: varname = x y z\n");
    printf("\tTo find a vector: varname\n");
    printf("\tTo save vectors: save\n");
    printf("\tTo load vectors: load\n\n");
    printf("Reminders: \n");
    printf("\tInclude spaces inbetween values and operands\n");
    printf("\tVector storage is unlimited\n");
    return 0;
}

/**
 * @brief Clear storage array
 * @param list pointer to VectorList
 * @return 0 to exit
*/
int clear(VectorList* list)
{
    // Reset count to 0 (don't free memory, just mark as empty)
    list->count = 0;
    return 0;
}

/**
 * @brief Display list of all vectors
 * @param list pointer to VectorList
 * @return 0 to exit
*/
int list(VectorList* list)
{
    // Iterates through array and prints all values
    for (int i = 0; i < list->count; i++) {
        printf("%d: ", i + 1);
        if (list->data[i].name[0] != '\0') {
            printf("%s = %f %f %f", list->data[i].name, 
                list->data[i].x, list->data[i].y, list->data[i].z);
        }
        printf("\n");
    }
    return 0;
}

/**
 * @brief Search array for name vector and return a copy to caller
 * @param list pointer to VectorList
 * @param name name of vector to find
 * @return copy of vector if found, NULL if not
*/
vector findvect(VectorList* list, char* name)
{
    // Iterates through array and returns vector if found
    // Returns empty vector if not found
    vector empty = {"", 0.0, 0.0, 0.0};
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->data[i].name, name) == 0) {
            return list->data[i];
        }
    }
    return empty;
}

/**
 * @brief Free memory function to free all allocated memory
 * @param list pointer to VectorList
 * @return 0 on success
*/
int free_memory(VectorList* list)
{
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
        list->count = 0;
        list->capacity = 0;
    }
    return 0;
}
