#include <string.h>

char opt_strcmp (a, b)
	char *a;
	char *b;
{
	if (strcmp(a,b)) return 1;
	return 0;
}
