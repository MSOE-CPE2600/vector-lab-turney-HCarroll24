/*************************************************************************
 * @file user_interface.c
 * @brief Implementation of the user interface for vector calculator
 *
 * Name: Hunter Carroll
 * Course: CPE2600
 * Section: 012
 * Assignent: Lab 5
*************************************************************************/
#include "user_interface.h"
#include "vector.h"
#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_INPUT 256

/** 
 * @brief Check if vector is found
 * @param v vector
 * @param name name of vector
 * @return 0 if vector is not found
 * @return 1 if vector is found
*/
static int vector_not_found(vector v, char* name)
{
    if (v.name[0] == '\0') {
        return 0;
    }

    return 1;
}

/**
 * @brief Run the user interface module
 * @param vector_list pointer to VectorList
 * @return 0 to exit
*/
int run_user_interface(VectorList* vector_list)
{
    // Initialize variables
    char line[MAX_INPUT];
    char *tokens[5];
    int count;
    int vector_found1;
    int vector_found2;
    char filename[16];

    // Display welcome message
    printf("Vector Calculator - Mini Matlab\n");
    printf("Type 'help' for commands, 'quit' to exit\n");

    // Main loop to continue, until quit command is issued
    while (1) {
        // prompt user for input
        printf("minimat> ");
        
        // Get input from user
        if (fgets(line, MAX_INPUT, stdin) == NULL) {
            break;
        }

        // Remove newline from input
        line[strcspn(line, "\n")] = '\0';

        // Tokenize input by spaces into tokens array
        count = 0;
        char *tok = strtok(line, " ");
        while (tok && count < 5) {
            tokens[count++] = tok;
            tok = strtok(NULL, " ");
        }

        // if no input, continue to next iteration of loop
        if (count == 0) {
            continue;
        }

        // Single token commands
        if (count == 1) {
            // Check if quit command
            if (strcmp(tokens[0], "quit") == 0) {
                printf("Exiting...\n");
                break;
            }
            // check if help command
            if (strcmp(tokens[0], "help") == 0) {
                help();
                continue;
            }
            // check if clear command
            if (strcmp(tokens[0], "clear") == 0) {
                clear(vector_list);
                printf("Vector list cleared\n");
                continue;
            }
            // check if list command
            if (strcmp(tokens[0], "list") == 0) {
                list(vector_list);
                continue;
            }
            // check if save command
            if (strcmp(tokens[0], "save") == 0) {
                printf("Input name to save to: ");
                if (fgets(filename, 16, stdin) == NULL) {
                    continue;
                }
                filename[strcspn(filename, "\n")] = '\0';
                int size = get_size(vector_list);
                if (save(filename, vector_list->data, size) == 0) {
                    printf("Vector list saved to %s\n", filename);
                } else {
                    printf("Error: Failed to save vector list\n");
                }
                continue;
            }
            // check if load command
            if (strcmp(tokens[0], "load") == 0) {
                printf("Input filename to load from: ");
                if (fgets(filename, 16, stdin) == NULL) {
                    continue;
                }
                filename[strcspn(filename, "\n")] = '\0';
                if (load(filename, &vector_list->data) == 0) {
                    printf("Vector list loaded from %s\n", filename);
                } else {
                    printf("Error: Failed to load vector list from %s\n", filename);
                }
                continue;
            }
            // else find vector
            vector vect = findvect(vector_list, tokens[0]);
            if (vect.name[0] == '\0') {
                printf("Error: vector '%s' not found\n", tokens[0]);
                continue;
            }
            printf("%s = %.2f %.2f %.2f\n", vect.name, vect.x, vect.y, vect.z);
            continue;
        }

        // Operation commands without assignment
        if (count == 3) {
            vector result;
            // check if add command
            if (strcmp(tokens[1], "+") == 0) {
                vector v1 = findvect(vector_list, tokens[0]); // find vector
                // Check if vector exists
                vector_found1 = vector_not_found(v1, tokens[0]);
                if (vector_found1 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[0]);
                }
                vector v2 = findvect(vector_list, tokens[2]);
                vector_found2 = vector_not_found(v2, tokens[2]);
                if (vector_found2 == 0) { // check if vectors are found
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    continue;
                }
                result = add(v1, v2); // add vectors
                printf("ans = %.2f %.2f %.2f\n", result.x, 
                    result.y, result.z);
            } else if (strcmp(tokens[1], "-") == 0) {
                vector v1 = findvect(vector_list, tokens[0]);
                vector_found1 = vector_not_found(v1, tokens[0]);
                if (vector_found1 == 0) {
                    printf("ERROR: Vector '%s' not found\n", tokens[0]);
                }
                vector v2 = findvect(vector_list, tokens[2]);
                vector_found2 = vector_not_found(v2, tokens[2]);
                if (vector_found2 == 0) { // check if vectors are found
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    continue;
                }
                result = sub(v1, v2); // subtract vectors
                // print result
                printf("ans = %.2f %.2f %.2f\n", result.x, 
                    result.y, result.z);
            } else if (strcmp(tokens[1], ".") == 0) {
                vector v1 = findvect(vector_list, tokens[0]);
                // check if vector exists
                vector_found1 = vector_not_found(v1, tokens[0]);
                if (vector_found1 == 0) {
                    printf("ERROR: Vector '%s' not found\n", tokens[0]);
                }
                vector v2 = findvect(vector_list, tokens[2]);
                // check if vector exists
                vector_found2 = vector_not_found(v2, tokens[2]);
                if (vector_found2 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    continue;
                }
                float dp = dotprod(v1, v2); // dot product
                // print result as scalar not as vector
                printf("ans = %.2f\n", dp);
            } else if (strcmp(tokens[1], "x") == 0) {
                vector v1 = findvect(vector_list, tokens[0]);
                // check if vector exists
                vector_found1 = vector_not_found(v1, tokens[0]);
                if (vector_found1 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[0]);
                }
                vector v2 = findvect(vector_list, tokens[2]);
                // check if vector exists
                vector_found2 = vector_not_found(v2, tokens[2]);   
                if (vector_found2 == 0) {
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    // continue to next iteration of loop if not found
                    continue;
                }
                result = crossprod(v1, v2); // cross product
                printf("ans = %.2f %.2f %.2f\n", result.x, 
                    result.y, result.z); // print result as vector
            } else if (strcmp(tokens[1], "*") == 0){ // scalar multiplication
                vector v1 = findvect(vector_list, tokens[0]);
                vector v2 = findvect(vector_list, tokens[2]);
                // check if vectors exist
                vector_found1 = vector_not_found(v1, tokens[0]);
                vector_found2 = vector_not_found(v2, tokens[2]);
                if (vector_found1 == 0 && vector_found2 == 0) {
                    // error if no valid vector given
                    printf("ERROR: No valid vector given\n");
                }
                if (vector_found1 == 1 && vector_found2 == 1) {
                    // error if no valid scalar given
                    printf("ERROR: No valid scalar given\n");
                    continue;
                }
                if (vector_found1 == 1) { // v * a
                    float s = atof(tokens[2]);
                    result = smult(s, v1); // scalar multiplication
                }
                if (vector_found2 == 1) { // a * v
                    float s = atof(tokens[0]);
                    result = smult(s, v2); // scalar multiplication
                }
                printf("ans = %.2f %.2f %.2f\n", result.x, 
                    result.y, result.z); // print result as vector
            }
        }

        // Operation commands with assignment and assignment commands
        if (count == 5) {
            vector resultassign;
            if (strcmp(tokens[3], "+") == 0) {
                vector v1 = findvect(vector_list, tokens[2]);
                if (vector_found1 == 0) {
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                // check if vector exists
                vector_found1 = vector_not_found(v1, tokens[2]);
                vector v2 = findvect(vector_list, tokens[4]);
                // check if vector exists
                vector_found2 = vector_not_found(v2, tokens[4]);
                if (vector_found2 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[4]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    // continue to next iteration of loop if not found
                    continue;
                }
                resultassign = add(v1, v2); // add vectors
                strcpy(resultassign.name, tokens[0]);
                if (addvect(vector_list, resultassign) != 0) { // check storage
                    printf("Error: failed to add vector\n");
                    continue;
                }
                // print result as vector
                printf("%s = %.2f %.2f %.2f\n", resultassign.name, 
                    resultassign.x, resultassign.y, resultassign.z);
            } else if (strcmp(tokens[3], "-") == 0) {
                vector v1 = findvect(vector_list, tokens[2]);
                // check if vector exists
                vector_found1 = vector_not_found(v1, tokens[2]);
                if (vector_found1 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                vector v2 = findvect(vector_list, tokens[4]);
                // check if vector exists
                vector_found2 = vector_not_found(v2, tokens[4]);
                if (vector_found2 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[4]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    // continue to next iteration of loop if not found
                    continue;
                }
                resultassign = sub(v1, v2); // subtract vectors
                strcpy(resultassign.name, tokens[0]);
                if (addvect(vector_list, resultassign) != 0) { // check storage
                    printf("Error: failed to add vector\n");
                    continue;
                }
                // print result as vector
                printf("%s = %.2f %.2f %.2f\n", resultassign.name, 
                    resultassign.x, resultassign.y, resultassign.z);
            } else if (strcmp(tokens[3], "*") == 0) {
                vector v1 = findvect(vector_list, tokens[2]);
                vector v2 = findvect(vector_list, tokens[4]);
                // check if vectors exist
                vector_found1 = vector_not_found(v1, tokens[0]);
                vector_found2 = vector_not_found(v2, tokens[2]);
                if (vector_found1 == 0 && vector_found2 == 0) {
                    // error if no valid vector given
                    printf("ERROR: No valid vector given\n");
                    continue;
                }
                if (vector_found1 == 1 && vector_found2 == 1) {
                    // error if no valid scalar given
                    printf("ERROR: No valid scalar given\n");
                    continue;
                }
                if (vector_found1 == 1) { // v * a
                    float s = atof(tokens[4]);
                    resultassign = smult(s, v1);
                }
                if (vector_found2 == 1) { // a * v
                    float s = atof(tokens[2]);
                    resultassign = smult(s, v2);
                }
                // print result as vector after assignment
                strcpy(resultassign.name, tokens[0]);
                if (addvect(vector_list, resultassign) != 0) {
                    printf("Error: failed to add vector\n");
                    continue;
                }
                printf("%s = %.2f %.2f %.2f\n", resultassign.name, 
                    resultassign.x, resultassign.y, resultassign.z);
            } else if (strcmp(tokens[3], "x") == 0) {
                vector v1 = findvect(vector_list, tokens[2]);
                // check if vector exists
                vector_found1 = vector_not_found(v1, tokens[2]);
                if (vector_found1 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[2]);
                }
                vector v2 = findvect(vector_list, tokens[4]);
                // check if vector exists
                vector_found2 = vector_not_found(v2, tokens[4]);
                if (vector_found2 == 0) { // error message if not found
                    printf("ERROR: Vector '%s' not found\n", tokens[4]);
                }
                if (vector_found1 == 0 || vector_found2 == 0) {
                    continue;
                }
                // assign result
                resultassign = crossprod(v1, v2); // cross product
                strcpy(resultassign.name, tokens[0]);
                if (addvect(vector_list, resultassign) != 0) { // check full storage
                    printf("Error: failed to add vector\n");
                    continue;
                }
                printf("%s = %.2f %.2f %.2f\n", resultassign.name, 
                    resultassign.x, resultassign.y, resultassign.z);
            } else if (strcmp(tokens[3], ".") == 0) {
                // error if trying to assign dot product
                printf("ERROR: Dot product outputs scalar, not vector\n");
                printf("Please use dot command without assignment\n");
                continue;
            } else if (strcmp(tokens[1], "=") == 0) {
                // assign result
                strcpy(resultassign.name, tokens[0]);
                resultassign.x = atof(tokens[2]); // assign x
                resultassign.y = atof(tokens[3]); // assign y
                resultassign.z = atof(tokens[4]); // assign z 
                if (addvect(vector_list, resultassign) != 0) { // check if storage is full
                    printf("Error: failed to add vector\n");
                    continue;
                }
                // print result as vector after assignment
                printf("%s = %.2f %.2f %.2f\n", resultassign.name, resultassign.x, resultassign.y, resultassign.z);
            }
        } 
    }

    // return 0 to exit
    return 0;
}