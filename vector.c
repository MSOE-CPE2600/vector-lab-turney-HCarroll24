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

// Allocates memory for vector list
vector* vector_list = (vector*)malloc(4 * sizeof(vector));

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
 * @param new Vector to add
 * @return 0 if successful, 1 if full
*/
int addvect(vector new)
{
    for (int i = 0; i < 4; i++) {
        if (strcmp(vector_list[i].name, new.name) == 0) {
            vector_list[i] = new;
            return 0;
        } else if (vector_list[i].name[0] == '\0') {
            vector_list[i] = new;
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Display help message to user for summary of uses
 * @return 0 to exit
*/
int help()
{
    printf("Vector Operations Functions\n");
    printf("Commands: quit, clear, list, help\n");
    printf("Operations: \n");
    printf("\tAdd: var1 + var2\n");
    printf("\tSub: var1 - var2\n");
    printf("\tScalar Mult: scalar * var1\n");
    printf("\tDot Product: var1 . var2\n");
    printf("\tCross Product: var1 x var2\n");
    printf("\tTo add a vector: varname = x y z\n");
    printf("\tTo find a vector: varname\n\n");
    printf("Reminders: \n");
    printf("\tInclude spaces inbetween values and operands\n");
    return 0;
}

/**
 * @brief Clear storage array
 * @return 0 to exit
*/
int clear()
{
    // Iterates through array and sets all values to 0
    for (int i = 0; i < 4; i++) {
        vector_list[i].name[0] = '\0';
        vector_list[i].x = 0;
        vector_list[i].y = 0;
        vector_list[i].z = 0;
    }

    return 0;
}

/**
 * @brief Display list of all vectors
 * @return 0 to exit
*/
int list()
{
    // Iterates through array and prints all values
    for (int i = 0; i < 4; i++) {
        printf("%d: ", i + 1);
        if (vector_list[i].name[0] != '\0') {
            printf("%s = %f %f %f", vector_list[i].name, 
                vector_list[i].x, vector_list[i].y, vector_list[i].z);
        }
        printf("\n");
    }
    return 0;
}

/**
 * @brief Search array for name vector and return a copy to caller
 * @param name name of vector to find
 * @return copy of vector if found, NULL if not
*/
vector findvect(char* name)
{
    // Iterates through array and returns vector if found
    // Returns empty vector if not found
    vector empty = {"", 0.0, 0.0, 0.0};
    for (int i = 0; i < 4; i++) {
        if (strcmp(vector_list[i].name, name) == 0) {
            return vector_list[i];
        }
    }
    return empty;
}

vector* get_vector_list()
{
    return vector_list;
}