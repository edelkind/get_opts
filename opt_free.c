#include <stdlib.h>

void opt_free(args)
	char **args;
{
	free ((void *)args);
}
