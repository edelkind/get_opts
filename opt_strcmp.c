#include <string.h>

char opt_strcmp (a, b)
	const char *a;
	const char *b;
{
	if (strcmp(a,b)) return 1;
	return 0;
}
