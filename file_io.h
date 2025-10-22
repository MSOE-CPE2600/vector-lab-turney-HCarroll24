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

vector* load(char* filename);

int save(char* filename, vector* vector_list, int size);

#endif