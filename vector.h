/********************************************************************
 * @file vector.h
 * @brief Function declarations and struct delcarations for vector.c
 *
 * Name: Hunter Carroll
 * Course: CPE 2600
 * Section: 012
 * Assignment: Lab 5
********************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    char name[10];
    float x;
    float y;
    float z;
} vector;

/**
 * @brief Computes addition of two vectors
 * @param a first vector
 * @param b second vector
 * @return addition of a and b
*/
vector add(vector a, vector b);

/**
 * @brief Computes subtraction of two vectors
 * @param a first vector
 * @param b second vector
 * @return subtraction of a and b
*/
vector sub(vector a, vector b);

/**
 * @brief Computes scalar multiplication of a vector
 * @param s scalar
 * @param a vector
 * @return scalar multiplicaiton of s and a */
vector smult(float s, vector a);

/**
 * @brief Computes dot product of two vectors
 * @param a first vector
 * @param b second vector
 * @return dot product of a and b
*/
float dotprod(vector a, vector b);

/** 
 * @brief Computes cross product of two vectors
 * @param a first vector
 * @param b second vector
 * @return cross product of a and b
*/
vector crossprod(vector a, vector b);

/**
 * @brief Adds new vector to storage array. If same name exists, replace
 * otherwise add to empty location. If full do nothing and return error
 * @param new Vector to add
 * @return 0 if successful, 1 if full
*/
int addvect(vector new);

/**
 * @brief Search array for name vector and return a copy to caller
 * @param name name of vector to find
 * @return copy of vector if found, NULL if not
*/
vector findvect(char* name);

/**
 * @brief Clear storage array
 * @return 0 to exit
*/
int clear();

/**
 * @brief Display help message to user for summary of uses
 * @return 0 to exit
*/
int help();

/**
 * @brief Display list of all vectors
 * @return 0 to exit
*/
int list();

/**
 * @brief get the vector list to avoid global
 * @return pointer to vector list
*/
vector* get_vector_list();

#endif