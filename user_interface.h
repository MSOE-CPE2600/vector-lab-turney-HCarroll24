/********************************************************************
 * @file user_interface.h
 * @brief declarations for the user interface
 *
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignent: Lab 5
********************************************************************/
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "vector.h"

/**
 * @brief Run the user interface module: contains all function for
 * user interaction with the vector calculator
 * @param vector_list pointer to VectorList
 * @return 0 to exit
*/
int run_user_interface(VectorList* vector_list);

/* internal helpers are defined static in user_interface.c */

#endif