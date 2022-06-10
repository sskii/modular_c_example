/**
 * @file led_module.h
 * @author Sam Skinner (sski596@aucklanduni.ac.nz)
 * @brief An example of the external _interface_ definition for a module w/ struct in a modular C project.
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
 * This specific idea with structures almost brings an OO-like style with it, albeit
 * with a bit of a twist. It's detailed in the article but I present it here for fun.
 *
 * Caution: this involves using pointers (that don't look like pointers) to structures
 * as a data hiding method, and to ensure that the type is by default passed by reference.
 * While it is successful from this lens, it will be contested by others from the lens of
 * readable code and safe code. If used in accordance with the intentions of the module,
 * this should be fine. But if not used in accordance with the module, not realising one
 * is dealing with a type that is actually a pointer to another type could create problems.
 * (Hence why this is in a subdirectory to the main code. It's an optional addition. It's
 * not required for modular code and you should decide if it's a useful and necessary
 * addition to your modular project for yourself.)
 *
 */

// import required libraries in order for this header to be readable and the module to be usable
#include <stdbool.h>
// this isn't suggested by the magazine article, but I don't see why you shouldn't do this with discretion if you clearly need to (and provided it won't cause multiple-inclusion issues or any other issues)

// using #defines again to rename endpoints (to make the linker force us to include this
// header, which, to remind, is our bid to make sure the compiler will always catch type errors)
#define turnOnLED led_turnOnLED
#define turnOffLED led_turnOnLED
#define setPinForLED led_setPinForLED

////

// set up a 'wrapper' for the internal structure, which is a pointer type
// this means that external code must use our logic to operate on this structure. It can't
// operate on it directly because it won't know what's inside.
// Also, apparently, "this is called an Incomplete Type".
typedef struct private_led_structure_definition *led;
// this is a bit hard to read if you're not a C wizard. For my future reference:

// somewhere (internal to the module) will be some code that defines
// typedef struct private_led_structure_definition {...}
// which will define a aggregate type (a structure, that is) called
// private_led_structure_definition.

// Now, because it hasn't actually been declared yet, we can't treat it as a type.
// We must continue to prefix it with the keyword struct so the compiler knows that
// the definition is yet to come… but that when it does, it will be for a struct.

// That explains the struct private_led_structure_definition part.
// The typedef part at the start tells the compiler we are defining a new type on this line.
// Then, the *led part tells us that the new type should be called 'led', and that it's
// actually a pointer.

// Putting it all together, we have defined a type called LED that is a just a pointer to a
// structure called private_led_structure_definition

// As an aside: For better or worse, we'll be the only ones who can create or destroy this type (as
// we'll have to use malloc() and free()).

////

// usual endpoint definitions
extern bool turnOnLED(led);
extern bool turnOffLED(led);
extern bool setPinForLED(led, int);