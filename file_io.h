/*************************************************************************
 * @file file_io.h
 * @brief Declarations for file io of load and save functions
 * 
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignment: Lab7
*************************************************************************/
#ifndef FILE_IO_H
#define FILE_IO_H

#include "vector.h"

vector* load(char* filename);

int save(char* filename, vector* vector_list, int size);

#endif