#include <stdio.h>
#include "get_opts.h"

#if 0
	get_opts example.
	errors are handled automatically.
#endif

add_opt(opt_p,  "p",  "ping",  OPT_TOGGLE, (opt_toggle_t)0, 0);
add_opt(opt_h,  "h",  "host",  OPT_STRING, (opt_string_t)0, 0);
add_opt(opt_P,  "P",  "port",  OPT_ULONG,  (opt_ulong_t)23, 0);
add_opt(opt_sp, "sp", "sport", OPT_ULONG,  (opt_ulong_t)0,  0);
add_opt(opt_sl, "sl", "slist", OPT_STRINGLIST, (opt_stringlist_t)0, 0);
add_opt(opt_cl, "cl", "clist", OPT_CHARLIST, (opt_charlist_t)0, 0);
add_opt(opt_il, "il", "ilist", OPT_INTLIST, (opt_intlist_t)0, 0);

put_opts(options, &opt_p, &opt_h, &opt_P, &opt_sp, &opt_sl, &opt_cl, &opt_il);

int main (argc, argv)
	int argc;
	char **argv;
{
	char **args;
	int argn;

	argn = get_opts_errormatic (&args, argv+1, argc-1, options);

	printf ("there were %d non-option arguments.\n", argn);
	printf ("additionally:\n");
	printf ("\tping?  %s\n", opt_p.v_opt.opt_toggle ? "yes" : "no");
	printf ("\thost:  %s\n", opt_h.v_opt.opt_string ? opt_h.v_opt.opt_string : "(none)");
	printf ("\tport:  %lu\n", opt_P.v_opt.opt_ulong);
	printf ("\tsport: %lu\n", opt_sp.v_opt.opt_ulong);
	printf ("\tstringlists:\n");
	for (argn = 0;opt_sl.v_opt.opt_stringlist &&
			argn < opt_sl.v_opt.opt_stringlist->n;argn++)
		printf ("\t\tstringlist[%d]: %s\n", argn,
				opt_sl.v_opt.opt_stringlist->sl[argn]);

	printf ("\tcharlists:\n");
	for (argn = 0;opt_cl.v_opt.opt_charlist &&
			argn < opt_cl.v_opt.opt_charlist->n;argn++)
		printf ("\t\tcharlist[%d]: %c\n", argn,
				opt_cl.v_opt.opt_charlist->cl[argn]);

	printf ("\tintlists:\n");
	for (argn = 0;opt_il.v_opt.opt_intlist &&
			argn < opt_il.v_opt.opt_intlist->n;argn++)
		printf ("\t\tintlist[%d]: %d\n", argn,
				opt_il.v_opt.opt_intlist->il[argn]);

	opt_free(args);

	return 0;
}
