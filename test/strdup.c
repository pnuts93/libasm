#include "test.h"

static int	test_strdup(char *input)
{
	char	*dest_original, *dest_custom;
	int		ret;

	dest_original = strdup(input);
	dest_custom = ft_strdup(input);
	ret = strcmp(dest_custom, dest_original) == 0;
	free(dest_custom);
	free(dest_original);
	return (ret);
}

void unit_strdup(void)
{
	printf("ft_strdup\t");
	print_result(test_strdup(""));
	print_result(test_strdup("hello world"));
	printf("\n");
}
