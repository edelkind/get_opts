#include <stdlib.h>
#include "get_opts.h"

#if 0
	*** gather_opt ***
	gather actual option info, and advance *argvp if necessary

	returns:
		0 on success
		-2 on missing argument
		-3 on system error
		-4 on program error (invalid type)

	currently implemented:
		OPT_BOOL
		OPT_CHAR
		OPT_STRING
		OPT_PTR
		OPT_INT
		OPT_LONG
		OPT_SHORT
		OPT_UINT
		OPT_ULONG
		OPT_USHORT
		OPT_TOGGLE
		OPT_INCREMENT

	alpha:
		OPT_STRINGLIST
		OPT_CHARLIST
		OPT_INTLIST

	notes:
		OPT_BOOL: always turns to 1
		OPT_CHAR: ignores successive characters
		numerics: converted from strto[u]l()
		OPT_TOGGLE: intolerant of user programming errors
				(i.e. a default value of 2 will always
				return true, regardless of toggles)

#endif

#define OPT_ADVANCE(argvp) { (*argvp)++; if (!**argvp) return -2; }
#define ADD_ELEM(optpl, t) { if (optpl->t) \
			optpl->t = realloc ((void *)optpl->t, \
				(optpl->n+1) * sizeof(optpl->t)); \
					else optpl->t = malloc(sizeof(optpl->t)); }

int gather_opt (argvp, optpp)
	char ***argvp;
	opt   **optpp;
{
	opt *optp = *optpp;

	switch (optp->t_opt) {
		case OPT_BOOL:
			optp->v_opt.opt_bool = 1;
			break;
		case OPT_CHAR:
			OPT_ADVANCE(argvp);
			/* ignores successive chars */
			optp->v_opt.opt_char = ***argvp;
			break;
		case OPT_STRING:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_string = **argvp;
			break;
		case OPT_PTR:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_ptr =
				(opt_ptr_t)strtol(**argvp, 0, 0);
			break;
		case OPT_INT:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_int =
				(opt_int_t)strtol(**argvp, 0, 0);
			break;
		case OPT_LONG:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_long =
				(opt_long_t)strtol(**argvp, 0, 0);
			break;
		case OPT_SHORT:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_short =
				(opt_short_t)strtol(**argvp, 0, 0);
			break;
		case OPT_UINT:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_uint =
				(opt_uint_t)strtoul(**argvp, 0, 0);
			break;
		case OPT_ULONG:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_ulong =
				(opt_ulong_t)strtoul(**argvp, 0, 0);
			break;
		case OPT_USHORT:
			OPT_ADVANCE(argvp);
			optp->v_opt.opt_ulong =
				(opt_ushort_t)strtoul(**argvp, 0, 0);
			break;
		case OPT_TOGGLE:
			/* intolerant of user error */
			optp->v_opt.opt_toggle ^= 1;
			break;
		case OPT_INCREMENT:
			optp->v_opt.opt_increment++;
			break;
		case OPT_STRINGLIST:
#define optpsl (optp->v_opt.opt_stringlist)
			if (!optpsl) optpsl = new_list (OPT_STRINGLIST);
			if (!optpsl) return -3;
			ADD_ELEM(optpsl, sl);
			OPT_ADVANCE(argvp);
			optpsl->sl[optpsl->n++] = **argvp;
			break;
		case OPT_CHARLIST:
#define optpcl (optp->v_opt.opt_charlist)
			if (!optpcl) optpcl = new_list (OPT_CHARLIST);
			if (!optpcl) return -3;
			ADD_ELEM(optpcl, cl);
			OPT_ADVANCE(argvp);
			optpcl->cl[optpcl->n++] = ***argvp;
			break;
		case OPT_INTLIST:
#define optpil (optp->v_opt.opt_intlist)
			if (!optpil) optpil = new_list (OPT_CHARLIST);
			if (!optpil) return -3;
			ADD_ELEM(optpil, il);
			OPT_ADVANCE(argvp);
			optpil->il[optpil->n++] =
				(opt_int_t)strtol(**argvp, 0, 0);
			break;
		default:
			return -4;
	}

	if (optp->f_opt) {
		/* perhaps do something with the return value later */
		optp->f_opt(optp);
	}

	return 0;
}
