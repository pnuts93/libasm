#include <stdio.h>

void	print_result(int res)
{
	if (!res)
		printf("\U0000274C ");
	else
		printf("\U00002705 ");
}