/**
 * @file main_module.c
 * @author Sam Skinner (sski596@aucklanduni.ac.nz)
 * @brief An example of the main file in a modular C project.
 * @version 1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 * https://www.embedded.com/modular-programming-in-c/
 *
 * This is part of an example program that attempts to use all the techniques
 * demonstrated in the above article, so that when I try to write an actual
 * application in this style, I can have a good, simple, easy-to-read exemplar
 * to follow.
 *
 */

/* Import needed interfaces: */
#include "foo_module.h"

/* Implements this interface: */
// omited as this is a special case (the main module starts the program,
// and isn't really a 'module'. It's the inter-modular glue.)

/**
 * @brief The main endpoint to start the program
 * (The only required module endpoint for a main module)
 */
int main()
{
	// do anything that you would normally do in C
	int stackVariable = 3;

	// as well as confidently interface with modules
	publicVariable = 4;
	publicFunction(&stackVariable);

	return 0;
}