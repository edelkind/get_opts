#include <stdlib.h>
#include "get_opts.h"

#if 0
	*** get_opts ***
	usage: get_opts (&args, argv, argc, options);

	gets any options in argv, and sets the respective values in the
	proper option structure element.

	any remaining, non-option arguments are put in *args (the individual
	elements in *args point to the desired elements in argv).  argv is
	not modified.

	argc is used only for allocation of *args, and currently has no
	bearing on how many arguments are processed (though it may in the
	future).

	returns the number of non-option arguments, or a negative number
	on error:
		-1 on invalid option
		-2 on missing or invalid argument
		-3 on system error (i.e. out of memory)
		-4 on program error (i.e. invalid type given in options)
#endif

int get_opts (args, carg, argv, argc, options)
	char ***args;
	char **carg;
	char **argv;
	int argc;
	opt **options;
{
	int argsn = 0;

	if (args) *args = malloc (argc * sizeof(char **));
	if (!args) return -3;

	for (; *argv; argv++) {
		*carg = *argv;
		switch (try_opt (&argv, options)) {
			case -1: return -1;
			case -2: return -2;
			case -3: return -3;
			case -4: return -4;
			case 1: (*args)[argsn++] = *argv;
		}
	}

	(*args)[argsn] = 0;

	return argsn;
}
