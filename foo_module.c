/**
 * @file foo_module.c
 * @author Sam Skinner (sski596@aucklanduni.ac.nz)
 * @brief An example of the internal _impementation_ code for a module in a
 * modular C project.
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
// no needed interfaces (foo doesn't depend on any other modules)

/* Implements this interface: */
#include "foo_module.h"
// import your own module interface header
// this ensures that the compiler checks that your implementation matches the
// declared interface

int publicVariable;
static int privateVariable;
//! `static` datatype ensures privateVariable is only visible to code in this
//! file this means that it can only be accessed from within the module!
// TODO this is very likely incorrect. No need to keyword the variable as
// it was never externed

/**
 * @brief A function that is internal to a module and cannot be accessed from
 * anywhere else.
 *
 * This is an example of an internal method. Note the `static` keyword. This
 * could be some sort of helper method that we don't want to see code outside of
 * the module running for itself, or that we don't want code outside the module
 * to depend on (in case we remove it in a future module update–in this case, we
 * only need to make sure the interface stays the same, which is a much easier
 * job).
 *
 */
static void privateFunction(int m) {
    // helper function stuff in here
    // this is just like any other helper function, except (provided you
    // remember the `static` keyword) you don't have to worry about other parts
    // of the application becoming dependent on it.

    // If you feel that this is a very useful generic helper method, it belongs
    // as its own module outright.
}

/**
 * @brief A function that can be called from outside of the Foo module.
 *
 * This is an example of an endpoint. This should be declared in the interface
 * (which is foo_module.h).
 *
 * Public functions like these should be used to initiate operations that the
 * module handles.
 *
 */
void publicFunction(int* n) {
    // this might rely on internal helper methods
    privateFunction(2 * (*n));

    // We can now use the simple trick of putting endpoint (public) methods at
    // the end of a module implementation. This means that all the internal
    // methods will already have been defined by the time the compiler reaches
    // this point, and therefore it should complain a whole lot less about
    // calling methods before they're declared.
}
