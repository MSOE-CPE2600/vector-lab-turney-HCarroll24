/*************************************************************************
 * @file file_io.h
 * @brief Header file for the io module
 *
 * Name: Hunter Carroll
 * Course: CPE 2600
 * Section: 012
 * Assignment: Lab 7
*************************************************************************/
#ifndef FILE_IO_H
#define FILE_IO_H

#include "vector.h"

/**
 * @brief loads vectors from a file
 * @param filename name of file to load from
 * @return 0 if successful, 1 if error
*/
int load(char* filename, vector* list);

/**
 * @brief saves vectors to a file
 * @param filename name of file to save to
 * @param vector_list pointer to vector list
 * @param size size of vector list
 * @return 0 if successful, 1 if error
*/
int save(char* filename, vector* vector_list, int size);

#endif