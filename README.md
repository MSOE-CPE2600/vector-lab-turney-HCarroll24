# Vector Calculator with Dynamic Memory

## Brief Summary
Vector calculator program that can load and save vectors to and from files.
There is an ability to store an unlimited number of vectors. The vector 
calculator uses a matlab approach and is able to perform basic artihmetic 
operations with vectors.

## Build Instructions
To build the program, make sure the makefile is uploaded and pulled from
the repository. Then run make if compiling for the first time. If not, 
run make clean first and then make after.

## Run Instructions
To run the vector calculator, use ./vector. To display help message, you
can either add the -h tag to the end of ./vector (./vector -h) or you can
type help when the program is running.

## Commands
 * help - displays information about the vector calculator and its uses
 * list - lists all current vectors stored in the program
 * clear - clears the vector list
 * quit - exits the program
 * vectname - prints the vector to interface that was referenced
 * vectname = x y z - values replacing x y z are initialized for the vector
 * a is a vector, b is a vector, s is a scalar
    * a . b - computes and displays the dot product of a and b
    * a x b - computes and displays the cross product of a and b
    * a + b - computes and displays addition of a and b
    * a - b - computes and displays subtraction of a and b
    * s * a - computes and displays scalar multiplication of a and s
    * a * s - computes and displays scalar multiplication of a and s
    * Note: by using vectname = to any of the operations, assigns result as vector

## Dynamic Memory Use
Do later