#include <stdio.h>
#include "get_opts.h"

#if 0
	get_opts example.
	errors are custom-handled.
#endif

add_opt(opt_p,  "p",  "ping",  OPT_TOGGLE, (opt_toggle_t)0, 0);
add_opt(opt_h,  "h",  "host",  OPT_STRING, (opt_string_t)0, 0);
add_opt(opt_P,  "P",  "port",  OPT_ULONG,  (opt_ulong_t)23, 0);
add_opt(opt_sp, "sp", "sport", OPT_ULONG,  (opt_ulong_t)0,  0);

put_opts(options, &opt_p, &opt_h, &opt_P, &opt_sp);

int main (argc, argv)
	int argc;
	char **argv;
{
	char **args;
	char *carg;
	int argn;

	argn = get_opts (&args, &carg, argv+1, argc-1, options);

	switch (argn) {
		case -1: /* argument error */
			printf("error (%s): invalid argument\n", carg);
			_exit (1);
		case -2: /* missing argument */
			printf("error (%s): missing argument\n", carg);
			_exit (1);
		case -3: /* system error (out of memory) */
			printf("error (%s): out of memory\n", carg);
			_exit (1);
		case -4: /* program error (invalid type) */
			printf("program error (%s): invalid type (duh)\n", carg);
			_exit (1);
	}

	printf ("there were %d non-option arguments.\n", argn);
	printf ("additionally:\n");
	printf ("\tping?  %s\n", opt_p.v_opt.opt_toggle ? "yes" : "no");
	printf ("\thost:  %s\n", opt_h.v_opt.opt_string ? opt_h.v_opt.opt_string : "(none)");
	printf ("\tport:  %lu\n", opt_P.v_opt.opt_ulong);
	printf ("\tsport: %lu\n", opt_sp.v_opt.opt_ulong);

	opt_free(args);

	return 0;
}
