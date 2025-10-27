/********************************************************************
 * @file main.c
 * @brief Main function for the vector calculator/mini matlab
 *
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignment: Lab 5
 *
 * Algorithm:
 * - Display help message
 * - Run user interface
 * - Take user input
 * - Display result of user input
 * - If quit command, exit
 * - If help command, display help
 * - If clear command, clear storage
 * - If list command, display list of vectors
 * - If vector command, display vector
 * - If operation command, display result of operation
 * - If assignment command, assign result to vector
 * - if save command, save vector list to file
 * - if load command, load vector list from file
 * 
 * Compile: make
 * Run: ./vector
********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user_interface.h"
#include "vector.h"
#include "file_io.h"

/**
 * @brief Main function for the vector calculator/mini matlab
 * @param argc number of arguments
 * @param argv arguments
 * @return 0 to exit
*/
int main(int argc, char *argv[])
{
    // Initialize VectorList
    VectorList list = {NULL, 0, 0};
    
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        help();
    }
    
    run_user_interface(&list);
    
    // Free memory before exiting
    free_memory(&list);
    
    return 0;
}