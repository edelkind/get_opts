#include "get_opts.h"

#if 0
	*** try_opt ***
	check the next option, and gather it if possible.
	advance *argvp if necessary.

	returns:
		 0 on success (found an option with possible arguments, and
				set anything necessary)
		 1 on non-option argument
		-1 on invalid option
		-2 on missing or invalid argument
		-3 on system error (i.e. out of memory)
		-4 on program error (i.e. invalid type)
#endif

int try_opt (argvp, options)
	char ***argvp;
	opt **options;
{
	const char *arg = **argvp;
	const char *opts;

	opt **optp, *o;
	opt_type_t opt_type;

	static char optend = 0;

	if (optend) return 1;
	if (*arg != OPT_DELIM) return 1;

	arg++;

	if (*arg == OPT_DELIM) {
		if (!*++arg) { optend = 1; return 0; }
		opt_type = OPT_LONG;
	} else  opt_type = OPT_SHORT;


	for (o = *(optp = options); o->i_opt; o = *(++optp)) {
		if (opt_type == OPT_SHORT)
			opts = o->s_opt;
		else    opts = o->l_opt;

		if (!opts) continue; /* no opt of that type */

		if (opt_strcmp(opts, arg)) continue; /* no match */

		/* match */

		return (gather_opt (argvp, optp));
	}

	/* invalid option */
	return -1;
}
