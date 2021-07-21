# structural get\_opts

## blurb

Structural get\_opts, as the name implies, is an argument-parsing library using structures. You define specific options, along with the type of option it should expect, and at your leisure, you tell it to parse the argument string.

Structural get\_opts is intended to be an easy-to-use, yet reasonably extensible argument-parsing library.


## Available option types include:

* bool
* char
* string
* int
* long
* short
* uint (unsigned int)
* ulong (unsigned long)
* ushort (unsigned short)
* toggle
* increment
* stringlist
* charlist
* intlist


## Additional notes

There are examples to help get you started in the `example` directory. `View opt_example.c` for help with the customizable error handling interface, or `opt_example_em.c` for the "errormatic" interface, which handles your argument errors automatically and uniformly. Keep in mind that `opt_example_em.c` demonstrates more features than `opt_example.c`.


## Functionality notes

* When using a ...list type, use multiple instances of an option to add items to the list. For example, if option `a` is an intlist type option to program `add`, you can use

  ```
  add -a 12 -a 24 -a 87 -a 2956
  ```

  to add the decimal numbers 12, 24, 87, and 2956, respectively, to the list for option `a`.

* When using a char type, only the first character is used. If a string of characters was (incorrectly) used, the remainder is ignored. The same goes for charlist; a string of characters can _not_ be used to generate an entire array of arguments.

* Type bool always turns to 1. For this to be an effective option, you should give it a default value of 0.

* Type toggle will toggle between 0 and 1. This type is user error intolerant, meaning if you (the programmer) were to give a toggle option a default value of, say, 2, its value would always return true (though it would toggle between two different values). This is because 1 is XORed with the current value to perform a toggle.

  For the following example, assume the default value for toggle option `t` is 0:
  ```
  a.out -t -t -t -t
  ```
  Since the `t` option was given four times, its value is changed to 1, back to 0, back to 1, and back to 0 again, ending with a final value of 0.

* Numerical arguments are currently converted using `strtol()` and `strtoul()`, and hence will follow the same semantics.

