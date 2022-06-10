/**
 * @file foo_module.h
 * @author Sam Skinner (sski596@aucklanduni.ac.nz)
 * @brief An example of the external _interface_ definition for a module in a modular C project.
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

/* foo_module.h */

// first, we use compiler macros to rename the module interface components to include their prefix
// this won't affect anything with how we write the code. __We still call publicFunction(int*)__, because this
// header file should be included anywhere we use the module, and it will therefore rename the calls there too.
// We rename as it means that we are required to include a module's header file. If we do not, the linker will
// complain, because we will be calling a function that does not really exist (it does, but was renamed by the
// preprocessor).
// While the code would compile just fine and mostly work without this step, performing this step catches
// us when we forget to include the module interface header. We want the header to be included, because then
// the compiler can catch us if, for example, we try to pass a regular int to publicFunction, when actually,
// as this interface file says, it expects a _pointer_ to an int. This would otherwise become a rather painful
// run-time bug.
#define publicVariable foo_publicVariable
#define publicFunction foo_publicFunction
// OPTIONAL: call these foo_publicVariable and foo_publicFunction, so that it's always obvious in source code
// the module from which a function is used. Then change these lines to something like,
// #define foo__publicVariable foo_publicVariable
// This could make larger projects with more niche modules more readable. The only critical thing with these
// defines is that they change the name of the module (to something that is guaranteed to be unique)!

// next, we declare the public interface methods exposed by the internal logic. This means that importing this
// header is now enough to allow us to call these methods. Plus, as above, it means the compiler will catch any
// bugs where we might have passed the wrong type to an interface method (and other similar issues).
// Without these, the compiler would complain about us calling a method before it is defined. With this, it trusts
// that the linker will find the methods.
extern int publicVariable;
extern void publicFunction(int*);

//* NB when you're actually writing a module's header (interface) file, substitute the general explanatory comments
//* for something implementation specific. This will mean that you have the advantage of your IDE providing
//* implementation hints to anyone who interfaces with your module.