# modular_c_example

This is my attempt at transcribing what I found [in this magazine article](https://www.embedded.com/modular-programming-in-c/) into something I can refer back to more readily.

This is all untested. Its only purpose is to serve as an example of this technique that I can refer back to when developing medium-sized embedded C applications.

## Cheatsheat

If you want a full overview, read the article. If you want a demo, read the code. But for the sake of making it clear that this is not too difficult, here is a summary of the standard tricks to get modular code. (This doesn't include the tricks for more niche implementations in subdirectories.)

### Create a header file that defines the interface
- This file could (highly recommended but not necessary) change the names of 'public' methods and variables using `#define`s
- This file should define any 'public' methods and variables using the `extern` keyword

### Create a source file that defines the implementation
- This file should include its own header
- This file should declare and define any internal ('private') methods and variables with the `static` keyword
- This file should define the interface ('public') methods and variables declared in the header
- (Tip) Declare the variables at the top, then the `static` internal methods, then the interface methods, in that order, to avoid a good deal of the define-something-before-using-it errors.

And really, that's about it for a bare-bones modular project. With discipline, this should bring all the OO benefits of encapsulation without the unnecessary headroom requirements.

## Expected errors

In the header files, it is strongly recommended to use `#define`s to change the names of public methods and variables. This is in a bid to turn as many bugs as possible into compiler/linker errors.
- You will get a linker error if you forget to include a module's header file somewhere
- You should (with luck) get a compiler error if;
	* you call a module's method with the wrong parameter
	* your definition for the implementation of a module's method does not match what the interface promises it should be