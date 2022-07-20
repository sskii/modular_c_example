/**
 * @file led_module.c
 * @author Sam Skinner (sski596@aucklanduni.ac.nz)
 * @brief An example of the internal implementation for a module w/ struct in a modular C project.
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

//* Import needed interfaces
// no needed interfaces (led doesn't depend on any other modules)

//* Implements this interface
#include "led_module.h"

//* declare internal type
// this is hidden, because it's only typedeffed inside this source code file
// as we never typedef it in any global .h files, no other code will know of
// its type

// obviously use a better name for this sort of thing when you actually implement it for a proper project.
// This name is needlessly verbose for the simple fact that this is designed to explain an unfamiliar concept
typedef struct private_led_structure_definition
{
	int pinNumber;
	bool currentState; // don't do this is actual avr code, but it did come quickly to mind as an example
};

//* Define internal helper methods
static void digitalWrite(int pinNumber, bool state)
{
	// implementation would go here
}

static void setLEDState(struct private_led_structure_definition *l, bool newState)
{
	// best to go back to using the actual internal type to make it clear it's a pointer
	digitalWrite(l->pinNumber, (l->currentState = newState));
}

//* Define interface endpoints

led constructLED() {
	// I have not tested or even double-checked this. You should before you copy this style of constructor.
	private_led_structure_definition newLED = malloc(sizeof private_led_structure_defition);
	return &newLED;
}

void destructLED(led target) {
	free(target);
}

bool turnOnLED(led l)
{

	// use the arrow operator to access members of a structure using a pointer to it
	digitalWrite(l->pinNumber, true);
	// alternative approach: dereference the structure pointer then directly change a value
	(*l).currentState = true;

	return true;
}

bool turnOffLED(led l)
{

	// improved method: refactor common code from an endpoint to a helper method
	setLEDState(l, false);

	return false;
}

bool setPinForLED(led target, int pinNumber) {
	target->pinNumber = pinNumber;
	return true;
}
