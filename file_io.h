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

/**
 * @brief Loads vectors from a file
 * @param filename name of file to load from
 * @return list of vectors read from file
*/
vector* load(char* filename);

/**
 * @brief saves vectors to a file
 * @param filename name of file to save to
 * @param v_list list of vectors to save
 * @param size size of vector list
 * @return 0 if successful, -1 if error
*/
int save(char* filename, vector* v_list, int size);

#endif