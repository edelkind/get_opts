#include <string.h>
#include <stdlib.h>
#include "get_opts.h"

#if 0
	*** new_list ***
	get a new list ready.

#endif


void *new_list (t_list)
	opt_type_t t_list;
{
	void *ptr;

	switch (t_list) {
		case OPT_STRINGLIST:
			ptr = malloc (sizeof(sl_elem));
			if (ptr) memset (ptr, 0, sizeof(sl_elem));
			return (ptr);
		case OPT_CHARLIST:
			ptr = malloc (sizeof(cl_elem));
			if (ptr) memset (ptr, 0, sizeof(cl_elem));
			return (ptr);
		case OPT_INTLIST:
			ptr = malloc (sizeof(il_elem));
			if (ptr) memset (ptr, 0, sizeof(il_elem));
			return (ptr);
	}
	return (void *)0;
}
