#include <stdio.h>
#include <unistd.h>
#include "get_opts.h"

int get_opts_errormatic (args, argv, argc, options)
	char ***args;
	char **argv;
	int argc;
	opt **options;
{
	int argn;
	char *carg;

	argn = get_opts (args, &carg, argv, argc, options);

	switch (argn) {
		case -1:
			fprintf (stderr, "error (%s): invalid argument\n",
					carg);
			_exit (1);
		case -2:
			fprintf (stderr, "error (%s): missing argument\n",
					carg);
			_exit (1);
		case -3:
			fprintf (stderr, "system error (%s): out of memory\n",
					carg);
			_exit (1);
		case -4:
			fprintf (stderr, "program error (%s): invalid type\n",
					carg);
			_exit (1);
	}

	return (argn);
}
