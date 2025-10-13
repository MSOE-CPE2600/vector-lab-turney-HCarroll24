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
 * 
 * Compile: make
 * Run: ./vector
********************************************************************/
#include <stdio.h>
#include <string.h>
#include "user_interface.h"
#include "vector.h"

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        help();
    }
    
    run_user_interface();
    return 0;
}