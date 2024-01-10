#include "test.h"

static int	test_strlen(char *input)
{
	return (strlen(input) == ft_strlen(input));
}

void unit_strlen(void)
{
	printf("ft_strlen\t");
	print_result(test_strlen(""));
	print_result(test_strlen("hello world"));
	printf("\n");
}
