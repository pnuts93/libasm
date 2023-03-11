#include "test.h"

static int	test_strcmp(char *s1, char *s2)
{
	int n1, n2;
	n1 = ft_strcmp(s1, s2);
	n2 = strcmp(s1, s2);
	return (
		(n1 == n2)
		|| (n1 < 0 && n2 < 0)
		|| (n1 > 0 && n2 > 0)
	);
}

void unit_strcmp(void)
{
	printf("ft_strcmp\t");
	print_result(test_strcmp("", ""));
	print_result(test_strcmp("string", ""));
	print_result(test_strcmp("", "string"));
	print_result(test_strcmp("string", "string"));
	print_result(test_strcmp("string1", "string2"));
	print_result(test_strcmp("short", "short but longer"));
	print_result(test_strcmp("short but longer", "short"));
	printf("\n");
}
